/*
	
	Description: Cleans up a driving AI soldier, after killed
	Created By: Stormridge
	
*/

_unit = _this select 0 select 0;

systemChat "Your target is dead.";

[_unit] spawn {
	_unit = _this select 0;
	_car = vehicle _unit;

	sleep 10;

	// Remove any attached objects from this AI
	{
		detach _x;
		deleteVehicle _x;
	} foreach (attachedObjects _unit);
	deleteVehicle _unit;
	
	sleep 6;  //  60
	// delete the vehicle, if they were driving.
	if (_car != _unit) then {
		deleteVehicle _car;
	};
};
