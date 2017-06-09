/*
	
	Description: Central class for environmental objects (usually server side)
	Created By: Stormridge
	
*/

//###############################
// AI Items
//###############################
BRFR_AI_Plane_A10_Init = {
	
	_doDropBombs = false;
	_doDropFlares = false;
	
	_targetPos = [14823.9,16379.3, 0];	// Runway middle
	
	_dropDistance = 500;
	_speed = 150;
	_altitude = 100;
	_heading = 90;
		
	_dropPosX = _targetPos select 0;
	_dropPosY = _targetPos select 1;
	_dropPosZ = _targetPos select 2;	// always returns 0 - need better z coord to calculate bombing timing.

	_planeSpawnPos = [_dropPosX - 3000, _dropPosY, _altitude + 500];  // 3000 is good.  1k to test

	//O_Plane_CAS_02_F    B_Plane_CAS_01_F=A10  BR_MV22
	_plane = createVehicle ["BR_MV22",_planespawnpos,[], 0, "FLY"];
	_plane setposATL  _planeSpawnPos;
	_plane setDir ([_planespawnpos, _targetPos] call BIS_fnc_dirTo);	
	_plane setbehaviour "careless";
	
	_velx = (sin _heading * _speed);
	_vely = (cos _heading * _speed);
	_velz = 0;
	_plane setVelocity [_velx,_vely,_velz];
	
	_newPilot = GROUP_AI_DRIVERS createUnit ["C_man_pilot_F", [1000,1000,1000], [], 0, "NONE"];
	_newPilot moveinDriver _plane;
	_newPilot setBehaviour "CARELESS";

	_plane flyInHeight _altitude;
	_plane setSpeedMode "NORMAL";
	
	{_newPilot disableAI _x} forEach ["AUTOTARGET", "FSM", "TARGET"];

	/*sleep 10;
	_plane doMove [15426.8,14283.9,300];  // altis middle
	sleep 200;
	_newPilot doMove _targetPos;
	sleep 100;
		*/
	// Pre-Bomb and Bomb	
	[_plane, _targetPos, _dropDistance, _newPilot, _doDropBombs, _altitude, _doDropFlares] spawn {

		_plane = _this select 0;
		_targetPos = _this select 1;
		_dropDistance = _this select 2;
		_newPilot = _this select 3;
		_doDropBombs = _this select 4;
		_altitude = _this select 5;
		_doDropFlares = _this select 6;
		
		while {true} do {

			_newPilot doMove _targetPos;
			_plane flyInHeight _altitude;
			_plane setSpeedMode "NORMAL";

			_doBombLoop = true;
			_numberOfBombs = 5;
			_dropRadius = 200;	// how wide the bomb zone is
			_dropIncrement = _dropRadius / _numberOfBombs;
			_dropStart = (_targetPos select 0) - (_dropRadius / 2);
			
			while {_doBombLoop} do {
				_doBombLoop = (alive _newPilot);
				// Check distance to target				
				if (((getPos _plane) distance _targetPos) < _dropDistance) then {
					sleep 1;
					//Bombs away
					if (_doDropBombs) then {
						for [{_i=0}, {_i<_numberOfBombs}, {_i=_i+1}] do {
								_bomb = "Sh_155mm_AMOS" createVehicle [1000, 1000, 1000];  // Sh_155mm_AMOS
								//_bomb attachTo [_plane, [0, 0, -125]]; //spawn under left wing
								_bomb setposATL [(_dropStart + (_i * _dropIncrement)), _targetPos select 1, 500];
								_bomb setdir (getdir _plane);
								_bomb setVelocity [0,0,-250];
								sleep .3; //allow the bomb to be attached before detaching it
								//detach _bomb;
						}; 
					};
					_doBombLoop=false;
				};
				sleep .5;
			};
			
			_plane flyInHeight 3000;
			_newPilot doMove [15426.8,14283.9,3000];  // altis middle

			sleep 2;
			if (_doDropFlares) then {
				_weapon = "CMFlareLauncher";
				_mode = (getArray (configFile >> "cfgweapons" >> _weapon >> "modes")) select 0;
				_plane addMagazines ["300Rnd_CMFlare_Chaff_Magazine", 10];
				_newPilot forceWeaponFire  [_weapon, _mode]; 
				sleep 3;
				_newPilot forceWeaponFire  [_weapon, _mode];
			};
			
			sleep 300;
			
		};
	};
};