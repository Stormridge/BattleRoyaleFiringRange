/*
	
	Description: Sets up the loadout, for this new soldier
	Created By: Stormridge
	
*/
[_this select 0, _this select 1, _this select 2, _this select 3, _this select 4, _this select 5] spawn {

	_unit = _this select 0;
	_uniform =  _this select 1;
	_vest =  _this select 2;
	_headgear =  _this select 3;
	_backpack =  _this select 4;
	_distance =  _this select 5;

	// Remove default items
	removeAllWeapons _unit;
	removeUniform _unit;
	removeVest _unit;
	removeHeadgear _unit;

	sleep 1;	// Avoid timing issues.

	if (!isNil "_uniform") then {
		_unit addUniform _uniform;
	};
	if (!isNil "_vest") then {
		_unit addVest _vest;
	};
	if (!isNil "_headgear") then {
		_unit addHeadgear _headgear;
	};
	if (!isNil "_backpack") then {
		_unit addBackpack _backpack;
	};
	
	// Custom hook for rangemaster, which is skinned in BR.
	if (_uniform == 'U_Rangemaster') then {_unit setObjectTexture [0,'a3\characters_f_kart\civil\data\c_poloshirtpants_2_co.paa'];};

};