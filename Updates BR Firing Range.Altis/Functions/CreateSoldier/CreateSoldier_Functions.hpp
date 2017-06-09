/*
	
	Description: Central class for the Create Soldier Feature
	Created By: Stormridge
	
*/

//###############################
// Soldier Creation Items
//###############################
 BRFR_CreateSoldier = 
 {
	_uniform =  _this select 0;
	_vest =  _this select 1;
	_headgear =  _this select 2;
	_backpack =  _this select 3;
	_distance =  _this select 4;
	_doDetailedReport = _this select 5;

	 _grp = 0;

	_playerPosition = getPos player;
	_playerDirection = getDir player;
	_playerVectorDir = vectorDir player;

	_type = "B_BattleRoyalePlayer_F";	// C_man_1
	
	_dirSoldier = _playerDirection + 180;
	
	_vVectorLocation = _playerVectorDir vectorMultiply (_distance);
	_posSoldier = _vVectorLocation vectorAdd _playerPosition;
	
	createcenter Civilian;
	_grp = createGroup Civilian;

	//_type createUnit [_posSoldier, _grp, "this addEventHandler ['Killed', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_KilledEvent.sqf'}]; this setVariable ['BIS_enableRandomization', false]; this disableCollisionWith player; nul = [this,_uniform, _vest, _headgear, _backpack, _distance] execVM 'Functions\CreateSoldier\CreateSoldier_Loadout.sqf'; this disableAI 'MOVE'; this disableAI 'TARGET';this disableAI 'ANIM'; this setDir _dirSoldier; this addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}]"]; ////////////////////////////////////////////////////////////////////////////////////////////
	_newUnit = _grp createUnit [_type, _posSoldier, [], 0, "NONE"];
	_newUnit addEventHandler ['Killed', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_KilledEvent.sqf'}]; 
	_newUnit setVariable ['BIS_enableRandomization', false]; 
	_newUnit disableCollisionWith player; 
	_newUnit disableAI 'MOVE'; 
	_newUnit disableAI 'TARGET';
	_newUnit disableAI 'ANIM';
	_newUnit setDir _dirSoldier; 
	_newUnit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];
	_newUnit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];
	
	if (_doDetailedReport) then 
	{
		_newUnit addEventHandler ['HandleDamage', {0 = _this execVM 'Functions\CreateSoldier\CreateSoldier_HandleDamage.sqf'}]; 
	};


	[_newUnit,_uniform, _vest, _headgear, _backpack, _distance] execVM 'Functions\CreateSoldier\CreateSoldier_Loadout.sqf'; 

	// Make unit easier to see, once spawned.
	if (_distance > 100) then 
	{
		// Make it easier to see
		_arrowPos = +_posSoldier;
		_arrowPos set [2, (_posSoldier select 2) + 10];
		_arrow = "Sign_Arrow_Large_Yellow_F" createVehicle _arrowPos;
		_arrow setPos _arrowPos;
		[_arrow] spawn { sleep 10; deleteVehicle (_this select 0);};
	};
	
	nul = ["<t color='#EEEEEE' size = '.5'>Soldier Created.  This soldier will report hit information back to you.</t>",0,0,5] spawn BIS_fnc_dynamicText;

 };
//###############################
// Soldier Creation - Click Event
//###############################
BRFR_Actions_CreateSoldier_Click = 
{
	_uniform = G_CLOTHING_OPTIONS select BRFR_Dialog_CreateSoldier_Uniform_LastIndex;
	_vest = G_VEST_OPTIONS select BRFR_Dialog_CreateSoldier_Vest_LastIndex;
	_headgear = G_HEADGEAR_OPTIONS select BRFR_Dialog_CreateSoldier_Headgear_LastIndex;
	_backpack = G_BACKPACK_OPTIONS select BRFR_Dialog_CreateSoldier_Backpack_LastIndex;
	_distance = G_DISTANCE_OPTIONS select BRFR_Dialog_CreateSoldier_Distance_LastIndex;
	
	waitUntil { !isNull (findDisplay IDD_BRFR_CreateSoldier) }; 
	_myDisplay = findDisplay IDD_BRFR_CreateSoldier;
	_doDetailedReport = cbChecked (_myDisplay displayCtrl IDC_BRFR_Button_DetailedReport);

	[_uniform, _vest, _headgear, _backpack, _distance, _doDetailedReport] call BRFR_CreateSoldier;
	
	closeDialog 0;
};
//###############################
// Soldier Creation Selection Changed
//###############################
BRFR_Actions_CreateSoldier_SetListSelectionIndex = {
	_control = _this select 0;
	_index = _this select 1;
	_idc = ctrlIDC _control;
	
	switch (_idc) do
	{
		case IDC_BRFR_Combo_Uniform: 
		{
			BRFR_Dialog_CreateSoldier_Uniform_LastIndex = _index;
		};
		case IDC_BRFR_Combo_Vest: 
		{
			BRFR_Dialog_CreateSoldier_Vest_LastIndex = _index;
		};
		case IDC_BRFR_Combo_Headgear: 
		{
			BRFR_Dialog_CreateSoldier_Headgear_LastIndex = _index;
		};
		case IDC_BRFR_Combo_Backpack: 
		{
			BRFR_Dialog_CreateSoldier_Backpack_LastIndex = _index;
		};
		case IDC_BRFR_Combo_Distance: 
		{
			BRFR_Dialog_CreateSoldier_Distance_LastIndex = _index;
		};

		BRFR_Dialog_CreateSoldier_DamageReport_OnOff
	};
};
//###############################
// Soldier Creation Initialization
//###############################
BRFR_Actions_CreateSoldier_Init = {
	if (!isdedicated) then
	{
		disableSerialization;
		
		/*if (currentNamespace isEqualTo uiNamespace) then {systemChat "This is uiNamespace"};
		if (currentNamespace isEqualTo missionNamespace) then {systemChat "This is missionNamespace"};
		if (currentNamespace isEqualTo profileNamespace) then {systemChat "This is profileNamespace"};
		if (currentNamespace isEqualTo parsingNamespace) then {systemChat "This is parsingNamespace"};*/

		_dialogOK = createDialog "BRFR_Dialog_CreateSoldier";
		
		if (_dialogOK) then 
		{
			// Uniform List
			{
				_index = lbAdd [IDC_BRFR_Combo_Uniform, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_Combo_Uniform, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];
			} foreach G_CLOTHING_OPTIONS;
			lbSetCurSel [IDC_BRFR_Combo_Uniform, BRFR_Dialog_CreateSoldier_Uniform_LastIndex];
			// Vests
			{
				_index = lbAdd [IDC_BRFR_Combo_Vest, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_Combo_Vest, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];			
			} foreach G_VEST_OPTIONS;
			lbSetCurSel [IDC_BRFR_Combo_Vest, BRFR_Dialog_CreateSoldier_Vest_LastIndex];
			// Headgear
			{
				_index = lbAdd [IDC_BRFR_Combo_Headgear, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_Combo_Headgear, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];
			} foreach G_HEADGEAR_OPTIONS;
			lbSetCurSel [IDC_BRFR_Combo_Headgear, BRFR_Dialog_CreateSoldier_Headgear_LastIndex];
			// Backpack
			{
				_index = lbAdd [IDC_BRFR_Combo_Backpack, gettext(configfile >> "CfgVehicles" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_Combo_Backpack, _index, gettext(configfile >> "CfgVehicles" >> (_x) >> "picture")];				
			} foreach G_BACKPACK_OPTIONS;
			lbSetCurSel [IDC_BRFR_Combo_Backpack, BRFR_Dialog_CreateSoldier_Backpack_LastIndex];
			// Distance
			{
				lbAdd [IDC_BRFR_Combo_Distance, str _x];
			} foreach G_DISTANCE_OPTIONS;
			lbSetCurSel [IDC_BRFR_Combo_Distance, BRFR_Dialog_CreateSoldier_Distance_LastIndex];

			// Wire up events
			waitUntil { !isNull (findDisplay IDD_BRFR_CreateSoldier) }; 
			
			_myDisplay = findDisplay IDD_BRFR_CreateSoldier;
			
			_myDisplay displayCtrl IDC_BRFR_Combo_Uniform ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_CreateSoldier_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_Combo_Vest ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_CreateSoldier_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_Combo_Headgear ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_CreateSoldier_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_Combo_Backpack ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_CreateSoldier_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_Combo_Distance ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_CreateSoldier_SetListSelectionIndex"]; 

			_myDisplay displayCtrl IDC_BRFR_Button_Create ctrlSetEventHandler ["ButtonClick", "_this call BRFR_Actions_CreateSoldier_Click; false"]; 

		};
	};
};
