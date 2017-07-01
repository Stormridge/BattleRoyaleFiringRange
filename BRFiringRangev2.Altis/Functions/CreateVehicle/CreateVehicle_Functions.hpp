/*
	
	Description: Sets up player action menu
	Created By: Stormridge
	
*/
BRFR_Actions_CreateVehicle_Init = {
	
	if (!isdedicated) then
	{
		disableSerialization;
		
		_dialogOK = createDialog "BRFR_Dialog_CreateVehicle";
		
		if (_dialogOK) then 
		{
			{
				_index = lbAdd [IDC_BRFR_CreateVehicle_Combo_Vehicle, gettext(configfile >> "CfgVehicles" >> (_x) >> "displayname")];
				lbSetData[IDC_BRFR_CreateVehicle_Combo_Vehicle, _forEachIndex, _x];
			} foreach G_CAR_OPTIONS;

			lbSetCurSel [IDC_BRFR_CreateVehicle_Combo_Vehicle,0];

			waitUntil { !isNull (findDisplay IDD_BRFR_CreateVehicle) }; 
			
			_myDisplay = findDisplay IDD_BRFR_CreateVehicle;

			_myDisplay displayCtrl IDC_BRFR_CreateVehicle_Button_Create ctrlSetEventHandler ["ButtonClick", "_this call BRFR_Actions_CreateVehicle_Click; false"];
		};
	};
};

BRFR_Actions_CreateVehicle_Click = {

	private ["_value","_newVehicle"];

	_value = lbData[IDC_BRFR_CreateVehicle_Combo_Vehicle, lbCurSel IDC_BRFR_CreateVehicle_Combo_Vehicle];

	_newVehicle = _value createVehicle position player;

	_newVehicle setVariable[PLAYER_MADE,true,true];		// Do this so it doesn't get cleaned up.

	closeDialog 0;
};