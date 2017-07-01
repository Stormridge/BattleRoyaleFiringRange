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

// _unit addEventHandler
// [
// 	"Killed",	
// 		{
// 			_killer = _this select 1;
// 			_weapon = currentWeapon _killer;
// 			systemChat format["DEBUG: YOU WERE KILLED by %1, with %2, isP=%3", _killer, _weapon, isPlayer _killer];
// 		}
// ];

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