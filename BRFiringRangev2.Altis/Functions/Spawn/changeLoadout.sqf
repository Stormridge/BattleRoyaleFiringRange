/*
	Description: Players loadout, on spawn
	Created By: Majarkin
	Updated By: Stormridge
*/

private ["_unit"];
_unit = _this select 0;

// Remove the unit's default weapons
removeAllWeapons _unit;
removeUniform _unit;
removeVest _unit;

sleep .5;	// Give time for removal to work.

// Add Binoculars and Night Vision Goggles
_unit addWeapon "Rangefinder";
//_unit addWeapon "NVGoggles";
_unit addWeapon "ItemGPS";

// Add backpack, chest piece, and clothing
_unit addBackpack "B_Carryall_oli";
_unit addVest "V_PlateCarrierSpec_rgr";
_unit addUniform "U_O_SpecopsUniform_ocamo";

// Stormridge - Fixed Additem for FirstAidKit
_unit addItem "FirstAidKit";
_unit addItem "ItemRedgull";
_unit addItem "ItemPainkiller";
