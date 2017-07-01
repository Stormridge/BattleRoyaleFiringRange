/////////////////////////////////////////////////////////////////////////////////
// Begin isolated code that is easily transportable to temporary mod files
/////////////////////////////////////////////////////////////////////////////////

// Recoil
//	 Based off OfotViking's and ACE3 overheat code 
br_public_bulletDispersionFactor = 4;
br_bulletDispersionRNG = [];
br_bulletDispersionRNGCount = -1;
for "_i" from 0 to 30 do
{
	br_bulletDispersionRNG pushBack [(random [-1,0,1] * br_public_bulletDispersionFactor), (random [-1,0,1] * br_public_bulletDispersionFactor)];
};
br_bulletDispersionRNGCount = count br_bulletDispersionRNG;

BR_Test_onFired = 
{
	if !(cameraView isEqualTo "GUNNER") then 
	{
		private _projectile = _this select 6;
		private _dispersionArray = br_bulletDispersionRNG select ((player ammo (_this select 1)) mod br_bulletDispersionRNGCount);
		private _projDirVector = vectorNormalized velocity _projectile;
		private _latDegrees = (_projDirVector select 0) atan2 (_projDirVector select 1) + (_dispersionArray select 0);
		private _elevationDegrees = asin (_projDirVector select 2) + (_dispersionArray select 1);
		_projDirVector = [sin _latDegrees * cos _elevationDegrees, cos _latDegrees * cos _elevationDegrees, sin _elevationDegrees];
		_projectile setVectorDirAndUp [_projDirVector, (vectorNormalized (_projDirVector vectorCrossProduct [0,0,1])) vectorCrossProduct _projDirVector];
		_projectile setVelocity (_projDirVector vectorMultiply (vectorMagnitude velocity _projectile));
	};
};
//brTestFiredEH = player addEventHandler ["Fired", {_this call BR_Test_onFired}];