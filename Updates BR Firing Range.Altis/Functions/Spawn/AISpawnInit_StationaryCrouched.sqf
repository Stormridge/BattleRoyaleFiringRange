/*

	Description: AI Setup and Events, for stationary targets.  Called by mission.sqm Inits, per unit
	Created By: Stormridge
	
*/
_randomPositions = ["DOWN", "MIDDLE"];  // UP  is boring.

_unit = _this select 0;

if (isServer) then {
	
	_unit allowFleeing 0;
	//_unit disableAI "MOVE";
	_unit disableAI "TARGET";
	//_unit disableAI "ANIM";   // Must be animated to crouch or go prone
	_unit setUnitPos "MIDDLE";
	[_unit] execVM "Functions\Spawn\changeAILoadout.sqf";
	
	_unit addWeapon "arifle_katiba_f";
	
	// randomize his position a bit.
	[_unit, _randomPositions] spawn {
		_myUnit = _this select 0;
		_myRandomPositions = _this select 1;
		_cycle = 0;
		while {!isNull _myUnit && !isNil "_myUnit"} do {
			_cycle = _cycle + 1;
			if (_cycle >= count _myRandomPositions) then {_cycle = 0;};
			_newPosition = _myRandomPositions select _cycle;
			_myUnit setUnitPos _newPosition;
			sleep 20;
		};
	};

	_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];

	_unit addEventHandler [
		"Killed",
		{
			_ai = _this select 0;
			_type = (typeOf _ai);
			_grp = group _ai;
			_pos = getPos _ai;
			hideBody _ai;
					
			[_pos, _grp, _ai, _this, _type] spawn {
				_pos = _this select 0;
				_grp = _this select 1;
				_ai = _this select 2;
				this = _this select 3;
				_type = _this select 4;
				sleep 5.0;
				//_type createUnit [_pos, _grp, "this disableCollisionWith _ai; this setVariable ['BIS_enableRandomization', false]; this disableAI 'MOVE'; this disableAI 'TARGET';this disableAI 'ANIM';this setPos _pos; nul = [this]execVM 'Functions\Spawn\AISpawnInit_Stationary.sqf';"];
				_newUnit = _grp createUnit [_type, _pos, [], 0, "NONE"];
				_newUnit setVariable ['BIS_enableRandomization', false];
				_newUnit disableCollisionWith _ai; 
				_grp setBehaviour 'CARELESS';
				[_newUnit] execVM 'Functions\Spawn\AISpawnInit_StationaryCrouched.sqf';
			};
		}
	];

	// Hit parts do not work in multiplayer, here....  Only server will get the "Your target is dead" message.
	_unit addEventHandler ['Killed', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_KilledEvent.sqf'}];

};

// Add MP hit part event here.  This function will check if the player actually hit the target.
_unit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];