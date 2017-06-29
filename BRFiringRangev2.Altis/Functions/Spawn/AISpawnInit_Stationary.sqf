/*

	Description: AI Setup and Events, for stationary targets.  Called by mission.sqm Inits, per unit
	Created By: Stormridge
	
*/

_unit = _this select 0;

if (isServer) then {

	[_unit] execVM "Functions\Spawn\changeAILoadout.sqf";
	_unit disableAI "MOVE";
	//_unit disableAI "TARGET";
	//_unit disableAI "ANIM";
	//_unit switchMove "";
	_unit commandTarget player;

	_unit addEventHandler [
		"Killed",
		{
			// _killer = _this select 1;
			// _weapon = currentWeapon _killer;
			// if (vehicle _killer != _killer) then { _weapon = typeOf (vehicle _killer); };
			// systemChat format["DEBUG: Killed by %1, with %2, isP=%3", _killer, _weapon, isPlayer _killer];

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
				_newUnit disableCollisionWith _ai; 
				_newUnit setVariable ['BIS_enableRandomization', false];
				_grp setBehaviour 'CARELESS';
				_newUnit allowFleeing 0;
				//_newUnit  disableAI 'TARGET'; 
				_newUnit commandTarget player;
				[_newUnit] execVM 'Functions\Spawn\AISpawnInit_Stationary.sqf';
			};
		}
	];

	_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];

	// _aethonian = random 100;
	// if (_aethonian < 2) then {
	// 	_unit spawn {
	// 		_this setName "Aethonian";
	// 		while {alive _this} do {		
	// 			_source01 = "#particlesource" createVehicle (position _this);
	// 			_source01 setParticleClass "UAVCrashSmoke"; 
	// 			_source01 attachTo [_this,[0,0,1.6]];  
	// 			_source01 spawn { sleep .6; deleteVehicle _this; };
	// 			sleep 60;
	// 		};
	// 	};
	// };

	// Hit parts do not work in multiplayer, here....  Only server will get the "Your target is dead" message.
	_unit addEventHandler ['Killed', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_KilledEvent.sqf'}];

};

// Add MP hit part event here.  This function will check if the player actually hit the target.
_unit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];