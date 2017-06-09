/*
	
	Description: Cleans up created soldier, after killed
	Created By: Stormridge
	
*/

_unit = _this select 0 select 0;

[_unit] spawn {
	sleep 5;
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

