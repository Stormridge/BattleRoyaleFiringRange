/*
	File: ChangeAILoadout.sqf
	Description: AI Change Loadout Script
	Created By: Majarkin
	Updated By: Stormridge
*/
#include "..\..\Includes\globals.hpp"		// global variables, these are included early in the mission so AI can be spawned with globals.  

private ["_unit","_clothing","_vest","_selcloth","_selvest","_helmet","_selhelmet"];
_unit = _this select 0;

// Remove the unit's default weapons
removeAllWeapons _unit;
removeUniform _unit;
removeVest _unit;
removeHeadgear _unit;

_selcloth = G_CLOTHING_OPTIONS select floor random count G_CLOTHING_OPTIONS;
_selvest = G_VEST_OPTIONS select floor random count G_VEST_OPTIONS;
_selhelmet = G_HEADGEAR_OPTIONS select floor random count G_HEADGEAR_OPTIONS;

_unit unassignItem "NVGoggles_OPFOR";
_unit removeItem "NVGoggles_OPFOR";	

_unit addHeadgear _selhelmet;	
_unit addVest _selvest;
_unit addUniform _selcloth;

// Custom hook for rangemaster, which is skinned in BR.
if (_selcloth == 'U_Rangemaster') then {_unit setObjectTexture [0,'a3\characters_f_kart\civil\data\c_poloshirtpants_2_co.paa'];};

if (random 100 < 50) then {
	// assign weapon
	_randomWeapon = G_WEAPON_OPTIONS select floor random count G_WEAPON_OPTIONS;
	_magsSupported = getArray(configFile >> "CfgWeapons" >> _randomWeapon >> "magazines");
	if (count _magsSupported > 0) then
	{
		_unit addMagazineCargoGlobal [_magsSupported select (floor(random (count _magsSupported))), 2];
	};
	_unit addWeaponGlobal _randomWeapon;
};

// Stormridge - Commenting out Wooly, by default.  
//_unit addUniform "IRA_Soldier_Outfit_8";
