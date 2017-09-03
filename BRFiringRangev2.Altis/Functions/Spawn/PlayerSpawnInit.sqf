/*

	Description: Player initialization scripts
	Created By: Stormridge
	
*/
private ["_unit"];

_unit = _this select 0;

_unit addEventHandler
[
	"Respawn",	
		{
			[_this select 0] execVM "Functions\Spawn\PlayerSpawnInit.sqf";
		}
];

_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];
_unit addEventHandler ['Fired', {_this call BR_Test_onFired}];

_unit addEventHandler
[
	"Killed",	
		{
			private _impactData = player getVariable [BR_PLAYER_HIT_LAST_IMPACT_KILLEDME, [] ];
			private _instigator = objNull;
			private _hitboxIndex = 0;
			private _ammoType = 0;
			private _doProceed = false;

			if (count _impactData > 0) then 
			{	
				// Good data
				_instigator = _impactData select 0;
				_hitboxIndex = _impactData select 1;
				_ammoType = _impactData select 2;
				_doProceed = true;
			}
			else
			{
				// Meh data.
				_impactData = player getVariable [BR_PLAYER_HIT_LAST_IMPACT, [] ];
				if (count _impactData > 0) then 
				{
					_instigator = _impactData select 0;
					_hitboxIndex = _impactData select 1;
					_ammoType = _impactData select 2;
					_doProceed = true;
				};
			};

			if (_doProceed) then 
			{
				player setVariable ["BR_DMG_LAST_INSTIGATOR", netid _instigator, true]; // push value to server.  We can do this after the setDamage call because the server will wait 1 second for this info to arrive.

				private _hitboxName = _hitboxIndex call BR_DamageHandler_GetHitBoxNameStringFromIndex;
				private _ammoTypeGenericName = _ammoType call BR_DamageHandler_GetAmmoGenericName;

				private _displayInstigatorText = "An unknown player";
				private _message = "";

				if (!isNull _instigator) then 
				{
					if (isPlayer _instigator) then 
					{
						_displayInstigatorText = name _instigator;
					};
				};

				switch (_ammoType) do 
				{
					case BR_ENUM_AMMO_ROUND_TYPE_EXPLOSIVE :  
						{ 
							_message = format[">> %1 killed you with an explosion", _displayInstigatorText];
						};
					case BR_ENUM_AMMO_ROUND_TYPE_EMPTY : 
						{
							_message = format[">> You were killed!"];
						};
					default 
						{
							_message = format[">> %1 hit you in the %2 with %3", _displayInstigatorText, 
																		_hitboxIndex call BR_DamageHandler_GetHitBoxNameStringFromIndex, 
																		_ammoTypeGenericName];
						};
				};
				
				_message spawn 
				{	// Hack until we get this integrated to client mod.  Let the "thanks for playing go first".
					sleep 1;
					systemChat _this;
				};
			};
			true 
		}
];

_unit enableFatigue false;
_unit enableAimPrecision false;
_unit setCustomAimCoef 0.000;
_unit enableStamina false;
_unit allowSprint true;

// Don't Trace bullets by default. -- too much fps drop.
//[_unit,10] spawn BIS_fnc_traceBullets;

nul = [_unit]execVM "Functions\Spawn\changeLoadout.sqf";
nul = [_unit]execVM "Functions\Player\checkHealth.sqf";
nul = [_unit]execvm "Functions\Player\jump.sqf";
nul = [_unit]execVM "Functions\Player\NoDamage.sqf";

if (isNil "oneTimeHackPlease") then {
	br_deploy_players=true;
	[] spawn BR_Client_Player_Boost_BoostSystemWaitStart;
	oneTimeHackPlease=true;
};

nul = []execVM "Functions\SpawnSoldiers\SpawnSoldiersActions.sqf";
//nul = [_unit]execVM "Functions\Player\earplugs.sqf";
nul = []execVM "Mission\ATC_Tele.sqf";
nul = []execVM "Mission\TeleportPad.sqf";
nul = []execVM "Mission\Tower_Tele.sqf";

call BRFR_Actions_InitializeActions;

_unit onMapSingleClick "if (vehicle player == player) then {_this setPos(_pos);} else {vehicle _this setPos(_pos)};";

[] spawn {
	waitUntil {!isNull BRFROracleObject};
	BRFROracleAction1 = BRFROracleObject addAction ["Tell me about the vest I'm wearing.", {'vest_armor' spawn BRFR_LRN2Equipment}, "", 3, true];
	BRFROracleAction1 = BRFROracleObject addAction ["Tell me about the uniform I'm wearing.", {'uniform_armor' spawn BRFR_LRN2Equipment}, "", 3, true];
};