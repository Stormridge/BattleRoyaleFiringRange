/*
	File: SpawnSoldiersLoadout.sqf
	Description: AI configuration on spawned soldiers
	Created By: Stormridge
*/

nul = [_this select 0, _this select 1, _this select 2] spawn {

	_unit = _this select 0;
	_specifiedItemType = _this select 1;
	_specifiedItemName = _this select 2;
		
	// Remove default items
	removeAllWeapons _unit;
	removeUniform _unit;
	removeVest _unit;
	removeHeadgear _unit;

	sleep 1;	// Avoid timing issues.

	_uniform = "U_I_CombatUniform"; //"IRA_Soldier_Outfit_8"
	_headgear = "H_StrawHat";
	_vest = "V_HarnessO_brn";

	switch(_specifiedItemType) do {
		case "headgear": {
			_headgear = _specifiedItemName;
			_unit addHeadgear _headgear;
		};
		case "vest": {
			_vest = _specifiedItemName;
			//_unit addUniform _uniform;
			_unit addVest _vest;
		};
		case "uniform": {
			_uniform = _specifiedItemName;
			_unit addUniform _uniform;
			
			// Custom hook for rangemaster, which is skinned in BR.
			if (_uniform == 'U_Rangemaster') then {_unit setObjectTexture [0,'a3\characters_f_kart\civil\data\c_poloshirtpants_2_co.paa'];};
		};
	};
};