/*
	
	Description: Central server loop
	Created By: Stormridge
	
*/
// Main loop for server code
[] spawn {
	
	_environment_Plane_Exists = false;
	
	// Oracle 
	_group = createGroup independent;
	_unit = _group createUnit ["B_BattleRoyalePlayer_F", [0,0,0], [], 0, "CAN_COLLIDE"]; // CAN_COLLIDE
	_unit setVariable ["BIS_enableRandomization", false];
	_unit addUniform "U_C_Scientist";
	_unit addHeadgear "H_Beret_Colonel";
	_unit setPosATL [15059.4,16645.6,0.00143814];
	_unit setDir 135;
	{_unit disableAI _x} forEach ["AUTOTARGET", "FSM", "MOVE", "TARGET"];
	_unit setVariable ["Oracle", true];
	_unit allowDamage false;
	_unit setName "The Oracle";
	BRFROracleObject = _unit;

	while {true} do 
	{
		// Set up environment stuff
		if (!_environment_Plane_Exists) then {
			// Set up our plane
			call BRFR_AI_Plane_A10_Init;

			_environment_Plane_Exists = true;
		};
		
		// Sleep
		sleep 1;
	};	
};

// Loop for clean-up - This looks for dropped backpacks and such.
// For a bullet proof implementation, see https://forums.bistudio.com/topic/153481-repetitive-cleanup/
//		S: Fixed detaching/deleting attached objects.
[] spawn {
	while {true} do
	{
		_countDeleted = 0;
		_countDeletedAttached = 0;
		sleep 120;
		
		diag_log "Cleaning up ground objects...";
		{
			if (!isNil{_x} && {!isNull(_x)}) then {
				{
					detach _x;
					deleteVehicle _x;
					_countDeletedAttached = _countDeletedAttached + 1;
				} foreach (attachedObjects _x);
				_countDeleted=_countDeleted+1;
				deleteVehicle _x;
			};
		} foreach allMissionObjects "GroundWeaponHolder";
		
		{
			if (!canMove _x && {alive _x} count crew _x==0) then {
				{
					if (_x getVariable["PLAYER_MADE",false]) then {
						detach _x;
						deleteVehicle _x;
						_countDeletedAttached = _countDeletedAttached + 1;		
					};
				} foreach (attachedObjects _x);
				_countDeleted=_countDeleted+1;
				deleteVehicle _x;
			};
		} forEach vehicles;	
		
		{
			if (!isNil{_x} && {!isNull(_x)}) then {
				{
					detach _x;
					deleteVehicle _x;
					_countDeletedAttached = _countDeletedAttached + 1;
				} foreach (attachedObjects _x);
				_countDeleted=_countDeleted+1;
				deleteVehicle _x;
			};
		} forEach allDeadMen;
		
		// Display Statistics
		diag_log format["Cleanup: Removed %1 objects, and %2 attached objects)", _countDeleted, _countDeletedAttached];
	};
};
