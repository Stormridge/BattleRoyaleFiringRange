/*
	
	Description: Central class for the Custom Loadout Features
	Created By: Stormridge
	
*/

//###############################
// Soldier Creation Items
//###############################
BRFR_Actions_PlayerLoadout_Init =
{
	if (!isdedicated) then
	{
		disableSerialization;
		
		_dialogOK = createDialog "BRFR_Dialog_PlayerLoadout";
		
		if (_dialogOK) then 
		{
			// Uniform List
			{
				_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Uniform, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Uniform, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];
			} foreach G_CLOTHING_OPTIONS;
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Uniform, BRFR_Dialog_PlayerLoadout_Uniform_LastIndex];
			// Vests
			{
				_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Vest, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Vest, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];			
			} foreach G_VEST_OPTIONS;
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Vest, BRFR_Dialog_PlayerLoadout_Vest_LastIndex];
			// Headgear
			{
				_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Headgear, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Headgear, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];
			} foreach G_HEADGEAR_OPTIONS;
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Headgear, BRFR_Dialog_PlayerLoadout_Headgear_LastIndex];
			// Backpack
			{
				_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Backpack, gettext(configfile >> "CfgVehicles" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Backpack, _index, gettext(configfile >> "CfgVehicles" >> (_x) >> "picture")];				
			} foreach G_BACKPACK_OPTIONS;
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Backpack, BRFR_Dialog_PlayerLoadout_Backpack_LastIndex];
			// Weapon
			{
				_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Weapon, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
				lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Weapon, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];
				lbSetValue[IDC_BRFR_PlayerLoadout_Combo_Weapon, _index, _index];
			} foreach G_WEAPON_OPTIONS;

			waitUntil { !isNull (findDisplay IDD_BRFR_PlayerLoadout) }; 
			_myDisplay = findDisplay IDD_BRFR_PlayerLoadout;

			// Sorting hat  - Weapons are sorted by name.
			lbSort (_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Weapon);		// Sort it.
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Weapon, BRFR_Dialog_PlayerLoadout_Weapon_LastIndex];
					
			// Wire up events
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Uniform ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Vest ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Headgear ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Backpack ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Weapon ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Optic ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Ammo ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 
			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Suppressor ctrlSetEventHandler ["LBSelChanged", "_this call BRFR_Actions_PlayerLoadout_SetListSelectionIndex"]; 

			_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Button_Create ctrlSetEventHandler ["ButtonClick", "_this call BRFR_Actions_PlayerLoadout_Click; false"]; 

			// Fire events for first selection
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Weapon, BRFR_Dialog_PlayerLoadout_Weapon_LastIndex];
			
		};
	};
};

//###############################
// Player Loadout Selection Changed
//###############################
BRFR_Actions_PlayerLoadout_SetListSelectionIndex = {
	_control = _this select 0;
	_index = _this select 1;
	_idc = ctrlIDC _control;
	
	switch (_idc) do
	{
		case IDC_BRFR_PlayerLoadout_Combo_Uniform: 
		{
			BRFR_Dialog_PlayerLoadout_Uniform_LastIndex = _index;
		};
		case IDC_BRFR_PlayerLoadout_Combo_Vest: 
		{
			BRFR_Dialog_PlayerLoadout_Vest_LastIndex = _index;
		};
		case IDC_BRFR_PlayerLoadout_Combo_Headgear: 
		{
			BRFR_Dialog_PlayerLoadout_Headgear_LastIndex = _index;
		};
		case IDC_BRFR_PlayerLoadout_Combo_Backpack: 
		{
			BRFR_Dialog_PlayerLoadout_Backpack_LastIndex = _index;
		};
		case IDC_BRFR_PlayerLoadout_Combo_Weapon: 
		{
			BRFR_Dialog_PlayerLoadout_Weapon_LastIndex = _index;

			// Change Ammo List =============================================
			_indexValue = lbValue[IDC_BRFR_PlayerLoadout_Combo_Weapon, BRFR_Dialog_PlayerLoadout_Weapon_LastIndex];
			_weapon = G_WEAPON_OPTIONS select _indexValue;
			
			_ammoArray = (configFile >> "CfgWeapons" >> _weapon >> "magazines") call BIS_fnc_getCfgData;
			
			lbClear IDC_BRFR_PlayerLoadout_Combo_Ammo;
			
			if (count _ammoArray > 0) then {
				{
					_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Ammo, gettext(configfile >> "CfgMagazines" >> (_x) >> "displayname")];
					lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Ammo, _index, gettext(configfile >> "CfgMagazines" >> (_x) >> "picture")];				
				} foreach _ammoArray;
			};
			// reset selected index.
			BRFR_Dialog_PlayerLoadout_Ammo_LastIndex = 0;
			// fire event for ammo selection
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Ammo, 0];
			
			// Build list of optics =============================================
			_opticArray = [_weapon, 201] call CBA_fnc_compatibleItems ;	// Can try CBA_fnc_compatibleItems
			lbClear IDC_BRFR_PlayerLoadout_Combo_Optic;
			// Add a NONE
			lbAdd [IDC_BRFR_PlayerLoadout_Combo_Optic, "    <No Optic>"];
			// Then add rest...
			if (count _opticArray > 0) then {
				{	
					// Check and see if this optic exists in the BR loot table.
					if ((G_OPTIC_OPTIONS find _x) >= 0) then {
						_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Optic, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
						lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Optic, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];		
						lbSetData[IDC_BRFR_PlayerLoadout_Combo_Optic, _index, _x];
						//lbSetValue[IDC_BRFR_PlayerLoadout_Combo_Optic, _index, _forEachIndex + 1];		// Add 1 to account for the <NONE>, so we are at base 1 for CBA_fnc_compatibleItems.
					};
				} foreach _opticArray;
			};
			// Sort Optics
			_myDisplay = findDisplay IDD_BRFR_PlayerLoadout;
			lbSort (_myDisplay displayCtrl IDC_BRFR_PlayerLoadout_Combo_Optic);		// Sort it.
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Optic, BRFR_Dialog_PlayerLoadout_Optic_LastIndex];
			
			// Build list of suppressors =============================================
			_supArray = [_weapon, 101] call CBA_fnc_compatibleItems ;	// Can try CBA_fnc_compatibleItems
			lbClear IDC_BRFR_PlayerLoadout_Combo_Suppressor;
			// Add a NONE
			lbAdd [IDC_BRFR_PlayerLoadout_Combo_Suppressor, "  <No Suppressor>"];
			// Then add rest...
			if (count _supArray > 0) then {
				{
					_index = lbAdd [IDC_BRFR_PlayerLoadout_Combo_Suppressor, gettext(configfile >> "CfgWeapons" >> (_x) >> "displayname")];
					lbSetPicture [IDC_BRFR_PlayerLoadout_Combo_Suppressor, _index, gettext(configfile >> "CfgWeapons" >> (_x) >> "picture")];				
				} foreach _supArray;
			};
			// fire event for suppressor selection
			lbSetCurSel [IDC_BRFR_PlayerLoadout_Combo_Suppressor, BRFR_PlayerLoadout_Combo_Suppressor_LastIndex];
			
			// Show picture of weapon ============================================
			_weaponImgPath = gettext(configfile >> "CfgWeapons" >> _weapon >> "Picture");
			ctrlSetText [IDC_BRFR_PlayerLoadout_Picture_Weapon, _weaponImgPath];
		};
		case IDC_BRFR_PlayerLoadout_Combo_Optic: 
		{
			BRFR_Dialog_PlayerLoadout_Optic_LastIndex =  _index;			
		};
		case IDC_BRFR_PlayerLoadout_Combo_Ammo:
		{
			BRFR_Dialog_PlayerLoadout_Ammo_LastIndex = _index;
		};
		case IDC_BRFR_PlayerLoadout_Combo_Suppressor:
		{
			BRFR_PlayerLoadout_Combo_Suppressor_LastIndex = _index;
		};
	};
};
//###############################
// Player Loadout - Click Event
//###############################
BRFR_Actions_PlayerLoadout_Click = 
{
	_uniform = G_CLOTHING_OPTIONS select BRFR_Dialog_PlayerLoadout_Uniform_LastIndex;
	_vest = G_VEST_OPTIONS select BRFR_Dialog_PlayerLoadout_Vest_LastIndex;
	_headgear = G_HEADGEAR_OPTIONS select BRFR_Dialog_PlayerLoadout_Headgear_LastIndex;
	_backpack = G_BACKPACK_OPTIONS select BRFR_Dialog_PlayerLoadout_Backpack_LastIndex;
	
	// Weapons are sorted by name, so get the array index first.
	_weaponValue = lbValue[IDC_BRFR_PlayerLoadout_Combo_Weapon, BRFR_Dialog_PlayerLoadout_Weapon_LastIndex];
	_weapon = G_WEAPON_OPTIONS select _weaponValue;
	
	_opticArray = [_weapon,201] call CBA_fnc_compatibleItems ;	// Can try CBA_fnc_compatibleItems
	_opticIndex = BRFR_Dialog_PlayerLoadout_Optic_LastIndex; //lbValue[IDC_BRFR_PlayerLoadout_Combo_Optic, BRFR_Dialog_PlayerLoadout_Optic_LastIndex];
	_optic = "";
	if (_opticIndex > 0) then {
		_optic = lbData[IDC_BRFR_PlayerLoadout_Combo_Optic, _opticIndex];
	};
	
	_ammoArray = (configFile >> "CfgWeapons" >> _weapon >> "magazines") call BIS_fnc_getCfgData;
	_ammo = _ammoArray select BRFR_Dialog_PlayerLoadout_Ammo_LastIndex;
	
	_supArray = [_weapon,101] call CBA_fnc_compatibleItems ;	// Can try CBA_fnc_compatibleItems
	_suppressor = "";
	if (BRFR_PlayerLoadout_Combo_Suppressor_LastIndex > 0) then {
		_suppressor = _supArray select (BRFR_PlayerLoadout_Combo_Suppressor_LastIndex - 1);	// add 1 since we have a "no suppressor item"
	};
	
	// do stuff
	//diag_log format ["U=%1, V=%2, H=%3, B=%4, D=%5", _uniform, _vest, _headgear, _backpack, _distance];
	
	[_uniform, _vest, _headgear, _backpack, _weapon, _optic, _ammo, _suppressor] call BRFR_PlayerLoadout;
	
	closeDialog 0;
};
//###############################
// Player Loadout
//###############################
 BRFR_PlayerLoadout = 
 {
	_uniform =  _this select 0;
	_vest =  _this select 1;
	_headgear =  _this select 2;
	_backpack =  _this select 3;
	_weapon =  _this select 4;
	_optic =  _this select 5;
	_ammo = _this select 6;
	_suppressor = _this select 7;

	//diag_log format ["OK   U=%1, V=%2, H=%3, B=%4, D=%5", _uniform, _vest, _headgear, _backpack, _distance];
	removeAllWeapons player;
	removeUniform player;
	removeVest player;
	
	[player] spawn {
		_pl = _this select 0;
		sleep .5;		// Give time for weapons to be removed.
		_pl addWeapon "RangeFinder";
		//_pl addWeapon "NVGoggles";
		_pl addWeapon "ItemGPS";
	};
	
	player addUniform _uniform;
	// Custom hook for rangemaster, which is skinned in BR.
	if (_uniform == 'U_Rangemaster') then {player setObjectTexture [0,'a3\characters_f_kart\civil\data\c_poloshirtpants_2_co.paa'];};
	
	player addVest _vest;
	player addheadgear _headgear;
	player addBackpack _backpack;
	
	// Magazines
	player addMagazines [_ammo,5];
	
	// Weapon
	player addWeapon _weapon;
	//removeAllPrimaryWeaponItems player;
	
	// Optic
	player addPrimaryWeaponItem _optic;
	
	// Suppressor
	player addPrimaryWeaponItem _suppressor;

};
