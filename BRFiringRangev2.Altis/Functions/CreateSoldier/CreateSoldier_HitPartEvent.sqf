/*
	
	Description: Handles damage to the target Soldier
	Created By: Stormridge

*/
_partsHit = count (_this select 0);
	
//diag_log format ["==> Found %1 parts", _partsHit];

_root = _this select 0;

// Only support parsing 1 item.
_part = _root select 0;

// Extract Damage Info
_target 	= _part select 0;
_shooter 	= _part select 1;

// Stop processing if we're not the shooter
if (_shooter == player) then {

	_bullet		= _part select 2;
	_posImpact	= _part select 3;
	_velocityV = _part select 4;
	_hitObjectsArray = _part select 5;
	_hitObjectsArrayCount = count _hitObjectsArray;
	_ammoInfoArray = _part select 6;
	_ammoInfoArrayCount = count _ammoInfoArray;
	_dirImpactV = _part select 7;
	_radiusHit = _part select 8;
	_surfaceType = _part select 9;
	_boolDirectHit = _part select 10;

	// Diagnostics
	
	/*
	diag_log "#####################";
	diag_log format ["Target=%1, Shooter=%2, Bobj=%3", _target, _shooter, _bullet];
	diag_log format ["PosImpact=%1, Velocity=%2, HitCount=%3, HitObjects=%4", _posImpact, _velocityV, _hitObjectsArrayCount, _hitObjectsArray];
	diag_log format ["AmmoCount=%1, AmmoArray=%2, dirImpact=%3, Radius=%4", _ammoInfoArrayCount, _ammoInfoArray, _dirImpactV, _radiusHit];
	diag_log format ["Surface=%1, DirectHit=%2", _surfaceType, _boolDirectHit];
	diag_log "#####################";
	*/
	
	// Pyth. Theorem using 3 vectors
	_speed = abs floor sqrt(   (_velocityV select 0)^2 + (_velocityV select 1)^2  + (_velocityV select 2)^2 ); 

	// Only add hit markers if the unit is NOT driving.
	if (vehicle _target == _target) then {
		_sphere = "Sign_Sphere25cm_F" createVehicle _posImpact;
		_sphere setPosASL _posImpact;
		_sphere attachTo [_target];
	};

	// Player feedback
	_hitText = _hitObjectsArray select 0;
	//systemChat format ["Target hit at %1   (velocity: %2m/s)", _hitText, _speed];

	// Delay and sound
	//sleep .5;
	//playSound3D ["A3\sounds_f\weapons\Other\sfx5.wss", player];
	
};