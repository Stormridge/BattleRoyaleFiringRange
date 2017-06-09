/*
	
	Description: Waits a certain amount of time, then removes a spawned unit.
	Created By: Stormridge
	
*/

_unit = _this select 0;

[_unit] spawn {
	sleep 180;
	_unit = _this select 0;
	if (!isnil "_unit") then {
		// Remove any attached objects from this AI
		{
			detach _x;
			deleteVehicle _x;
		} foreach (attachedObjects _unit);
		deleteVehicle _unit;
	};
};

