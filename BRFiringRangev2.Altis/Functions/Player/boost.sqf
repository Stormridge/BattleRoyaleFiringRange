/* 
	By PLAYERUNKNOWN and BR Devs

Updated Jan9 2016 Stormridge:
	- Fixed med kit and boost interaction issues, which could cause Action Menu to disappear forever
	- Attempts to detect simultaneous use of FirstAidKits and Boost Items, disallows it.
	- Will now cancel boosting if use tries to FirstAidKit from action menu.  (also causes action menu issues)
	- Adds boost spam protection (1 second delay required between boost attempts)
	- New logic for boost application thread
		Rules:
			- Each boost item provides 40 boost
			- Boost > 90 (player had 2 boosters) will provide sway reduction & advantage  ('insta-heal' hands)
			- Boost > 40 (player had 2 boosters) will heal legs to the point the player can walk, simulating ability to run while injured
			- Medkitting to 75% and two boosters will get you to full health.
			-	Prior requirement means boosters will heal about 13% per hitbox, per booster
			- Boost ticks every 3 seconds, for 120 seconds of boost. (2 mins)
			- .13/40 = .00325 healed per tick
*/
/////////////////////// Global Boost variables
BR_CancelAnim = false;
BR_PlayerAnimationCancellationMovements = actionKeys "NextAction" + actionKeys "PreviousAction" + actionKeys "Action" + actionKeys "ActionContext" + actionKeys "TurnLeft" + actionKeys "TurnRight" + actionKeys  "SitDown" + actionKeys "MoveForward" + actionKeys "MoveBack" + actionKeys "MoveFastForward" + actionKeys "MoveSlowForward" + actionKeys "MoveLeft" + actionKeys "MoveRight" + actionKeys "EvasiveForward" + actionKeys "EvasiveLeft" + actionKeys "EvasiveRight" + actionKeys "EvasiveBack" + actionKeys "Stand" + actionKeys "Crouch" + actionKeys "Prone" + actionKeys "LeanLeft" + actionKeys "LeanRight"; //actionKeys "DefaultAction" == Map Action Only
BR_IsPlayerBoosting = false;
BR_BoostHealPerTick=(.13/40);	// Percent total heal divided by booster amount (40)
BR_LastBoostAttempt=0;
BR_MOUSE_DIK_LOOKUP = [
	65536, // Prim. Mouse Btn. 0
	65537, // Sec. Mouse Btn.	1
	65538, // Middle Mouse Btn. 2
	65539, // Mouse Btn. 3
	65540, // Mouse Btn. 4
	65541, // Mouse Btn. 5
	65542, // Mouse Btn. 6
	65543  // Mouse Btn. 7
];
/////////////////////// Initialize
waitUntil{!isNull player};
waitUntil{alive player};
sleep 3;
diag_log "[BOOST] Loading";
1 cutRsc ["br_RscDisplayPlayerStatus","PLAIN"];
/////////////////////// Functions
/* 
* Boost Applier thread
*/
[] spawn {
	private ["_damage", "_hitPointsArray", "_startDamage"];
	br_Boost = 100;
	br_TargetHPIncreasePerBoost = .13;
	while{true} do {
		
		uiSleep 3; //4;
		br_Boost = br_Boost - 1;
		if (br_Boost <= 0) then {
			br_Boost = 0;
		};
		
		if (alive player && br_Boost > 0) then 
		{
			// 1. Snapshot current state
			_startDamage = damage player;
			_hitPointsArray = (getAllHitPointsDamage player) select 2;
			// 2. Update overall damage value
			if (_startDamage > 0) then 
			{
				player setDamage (_startDamage - linearConversion[0,100,br_Boost,BR_BoostHealPerTick,BR_BoostHealPerTick*2,true]);
				if (damage player < 0) then { player setDamage 0;};
			};
			// ? Make sure Player is NOT invulnerable (e.g. Firing Range start zone) - opting not to check to keep this fast.
			// 3. Heal body parts and replace damage screwed up by setDamage
			{
				_x = _x - linearConversion[0,100,br_Boost,BR_BoostHealPerTick,BR_BoostHealPerTick*2,true];
				if (_x < 0) then {_x=0;};
				player setHitIndex[_forEachIndex,_x];
			} foreach _hitPointsArray;
			// 4. Apply Advantages
			// 	  Heal hands to reduce sway.  Arms have no effect.
			if (br_Boost > 90) then 
			{
				if ((_hitPointsArray select 9) > 0) then 
				{ 
					player setHitIndex[9,0];
					//systemChat "The pain in your hands has gone away.";
				};
			};
			//   Heal Legs, for movement
			if (br_Boost > 40) then
			{
				if ((_hitPointsArray select 10) >= .5) then 
				{
					player setHitIndex[10,.4];	// Can Walk at 0.4
					//systemChat "Your legs feel better.";
				};
			};			
		};
		player setVariable ["br_BoostVar", br_Boost, true];			
	};
};
/* 
* Key Handler for boosting
*/
br_fnc_doBoost = {
    BR_IsPlayerBoosting = true;
    if(vehicle player != player) exitWith {BR_IsPlayerBoosting = false};
	try {
		private ["_mags", "_boostItem", "_hasBoosted"];
   	    
   	    _hasBoosted = false;
		_boostItem = "";
		_mags = magazines player;

	    if ("ItemRedgull" in _mags) then
	    {
			_boostItem = "ItemRedgull";
	    }
		else
	    {
			_boostItem = "ItemPainkiller";
	    };
	    if (_boostItem isEqualTo "") throw "You need boost items in order to boost!";
	    
	    player removeMagazine _boostItem;

	    if !(6.4 call br_fnc_doAnim) then {
	        player addMagazine _boostItem;
	        throw "Boost canceled";
	    };

	    br_Boost = (br_Boost + 40) min 100;
	    BR_IsPlayerBoosting = false;
	} 
	catch
	{
		BR_IsPlayerBoosting = false;
		systemChat _exception;
	};
};
/**
 * Animate the boosting process.
 * @param endOfAnimationTime The duration of the animation.
 * @returns true if the animation has not been canceled during the given endOfAnimationTimeframe
 */
br_fnc_doAnim = {
	private ["_stance", "_time", "_success"];
	BR_CancelAnim = false;
	_stance = animationState player;
	_time = time + _this;
	_success = true;
	
	player playActionNow "Medic";

	_eh = (findDisplay 46) displayAddEventHandler ["KeyDown",{
		if((_this select 1) in BR_PlayerAnimationCancellationMovements) then {
			BR_CancelAnim = true;
		};
		false
	}];

	// Added to fix when players accidentally FirstAidKit while in middle of boosting-which causes the action menu to disappear forever.
	// Stormridge: Jan23.2016 - Fixed mouse button lookup, and translation of mouse buttons to DIK codes.
	_mouseEH = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
		if((BR_MOUSE_DIK_LOOKUP select (_this select 1)) in BR_PlayerAnimationCancellationMovements) then {
			BR_CancelAnim = true;
		};
		false
	}];
	_mouseEH2 = (findDisplay 46) displayAddEventHandler ["MouseButtonClick", {
		if((BR_MOUSE_DIK_LOOKUP select (_this select 1)) in BR_PlayerAnimationCancellationMovements) then {
			BR_CancelAnim = true;
		};
		false
	}];

	waitUntil{time >= _time or BR_CancelAnim};

	anim_cancel = [player,_stance];
	publicVariable "anim_cancel";
	player switchMove _stance;

	(findDisplay 46) displayRemoveEventHandler ["KeyDown",_eh];
	(findDisplay 46) displayRemoveEventHandler ["MouseButtonDown",_mouseEH];
	(findDisplay 46) displayRemoveEventHandler ["MouseButtonClick",_mouseEH2];

	if(BR_CancelAnim) then {
		_success = false;
	};
	_success;
};
/**
* Verify whether the player is able to consume a booster of any type
*/
br_fnc_hasBoostItems = {
    private _mags = magazines player;
    ("ItemRedgull" in _mags || "ItemPainkiller" in _mags)
};
/* 
* Verify player is not medkitting
*/
br_fnc_isPlayerMedKitting = {
    (((animationState player) find "medic") >= 0)
};
/* 
* Public event for player animation state.
*/
"anim_cancel" addPublicVariableEventHandler {
	_info = _this select 0;
	_player = _info select 0;
	_playerStance = _info select 1;
	(_player) switchMove _playerStance;
    anim_cancel = nil;
};
/* 
* GUI Hooks
*/
[] spawn {
    waitUntil{
        !isNil "br_Boost"
    };
	private ["_totalHealth","_percent","_totalDmg"];

    _ctrlHP = 1101;
    _ctrlThirst = 1201;
    disableserialization;
    _display = uiNamespace getVariable ["br_GUI_status",displayNull];

    if(isNull _display) then {
        1 cutRsc ["br_RscDisplayPlayerStatus","PLAIN"];
        _display = uiNamespace getVariable ["br_GUI_status",displayNull];
    };

    _ctrl = _display displayCtrl _ctrlHP;
    _pos = ctrlPosition _ctrl;
    _HPOrigWidth = _pos select 2;
    _ctrl = _display displayCtrl _ctrlThirst;
    _pos = ctrlPosition _ctrl;
    _boostOrigWidth = _pos select 2;

	while{true} do {
		_dmg = damage player;
		_boost = br_Boost;
		waitUntil{damage player != _dmg || br_Boost != _boost || isNull _display || !(alive player)};
		
		if !(alive player) exitWith {1 cutText ["","PLAIN"];};		
		
		if(isNull _display) then {
			1 cutRsc ["br_RscDisplayPlayerStatus","PLAIN"];
			_display = uiNamespace getVariable ["br_GUI_status",displayNull];
			
			_percent = 1 - (damage player);
			_ctrl = _display displayCtrl _ctrlHP;
			_pos = ctrlPosition _ctrl;
			_newPos = [_pos select 0,_pos select 1,_HPOrigWidth*_percent,_pos select 3];
			_ctrl ctrlSetPosition _newPos;
			_ctrl ctrlCommit 0;
			
			_percent = br_Boost/100;
	
			_ctrl = _display displayCtrl _ctrlThirst;
			_pos = ctrlPosition _ctrl;
			_newPos = [_pos select 0,_pos select 1,_boostOrigWidth*_percent,_pos select 3];
			_ctrl ctrlSetPosition _newPos;
			_ctrl ctrlCommit 0;
		} else {
			
			_percent = 1 - (damage player);
			_ctrl = _display displayCtrl _ctrlHP;
			_pos = ctrlPosition _ctrl;
			_newPos = [_pos select 0,_pos select 1,_HPOrigWidth*_percent,_pos select 3];
			_ctrl ctrlSetPosition _newPos;
			_ctrl ctrlCommit 1;
	
			_percent = br_Boost/100;
	
			_ctrl = _display displayCtrl _ctrlThirst;
			_pos = ctrlPosition _ctrl;
			_newPos = [_pos select 0,_pos select 1,_boostOrigWidth*_percent,_pos select 3];
			_ctrl ctrlSetPosition _newPos;
			_ctrl ctrlCommit 1;
		};
	};
};
/* 
* Key Handler for boosting
*/
(findDisplay 46) displayAddEventHandler ["KeyDown", {
    private _success = false;
    if((_this select 1) in (ActionKeys "User4")) then {
    	if (diag_tickTime - BR_LastBoostAttempt > 1) then
    	{
	    	// Non-warnable items
	    	if ((vehicle player == player) && (call br_fnc_hasBoostItems) && (br_Boost < 100)) then 
	    	{
	    		// Warnable items, which result in player message
	    		try {
			        if (BR_IsPlayerBoosting) throw "Finish this boost before using another booster.";
			        if (call br_fnc_isPlayerMedKitting) throw "You can't boost while using First Aid.";
			        [] spawn br_fnc_doBoost;
			        _success = true;
			    } catch {
			    	systemChat _exception;
				};
		    };
			BR_LastBoostAttempt = diag_tickTime;
		};
    };
    _success
}];