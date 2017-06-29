/*

	Description: AI Setup and Events, for driving targets.  Called by mission.sqm Inits, per unit
	Created By: Stormridge
	
*/
#include "..\..\Includes\globals.hpp"		// global variables, these are included early in the mission so AI can be spawned with globals.  

if (isServer) then {

	_unit = _this select 0;

	[_unit] execVM "Functions\Spawn\changeAILoadout.sqf";
	_unit disableAI "TARGET";
	_unit allowFleeing 0;

	// Give him a random car.
	_carType = G_CAR_OPTIONS select floor random count G_CAR_OPTIONS;

	_car = createVehicle [_carType,position _unit,[], 0, "NONE"];
	_car setposATL  position _unit;
	_unit moveinDriver _car;

	// wire up event to clean up cars with no driver.
	[_car] spawn {
		_car = _this select 0;
		_done = false;
		while {!_done} do {
			_driver = driver _car;
			if (isNull _driver) then {
				deleteVehicle _car;
				_done = true;
			};
			sleep 120;
		};
	};

	// wire up killed event
	_unit addEventHandler [
		"Killed",
		{
			_ai = _this select 0;
			_type = (typeOf _ai);
			_grp = group _ai;
			_pos = getPosATL _ai;
			hideBody _ai;
			
			// Move this new vehicle away from old vehicle
			_y = _pos select 1;
			_y = _y+15;
			_pos set [1, _y];
					
			[_pos, _grp, _ai, _this, _type] spawn {
				_pos = _this select 0;
				_grp = _this select 1;
				_ai = _this select 2;
				this = _this select 3;
				_type = _this select 4;
				sleep 5.0;
				//_type createUnit [_pos, _grp, "this disableCollisionWith _ai; this setVariable ['BIS_enableRandomization', false]; _grp setBehaviour 'CARELESS'; this allowFleeing 0;this disableAI 'TARGET'; nul=[this] execVM 'Functions\Spawn\AISpawnInit_Driving.sqf';"];
				_newUnit = _grp createUnit [_type, _pos, [], 0, "NONE"];
				_newUnit disableCollisionWith _ai; 
				_newUnit setVariable ['BIS_enableRandomization', false];
				_grp setBehaviour 'CARELESS';
				_newUnit allowFleeing 0;
				_newUnit  disableAI 'TARGET'; 
				[_newUnit] execVM 'Functions\Spawn\AISpawnInit_Driving.sqf';
			};	
		}
	];

	_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];

	// Hit parts do not work in multiplayer, here....
	_unit addEventHandler ['Killed', {[_this] execVM 'Functions\Spawn\AISpawnInit_Driving_KilledEvent.sqf'}];

	// Hit Parts don't attach correctly while the AI is in a vehicle... 
	_unit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];

};