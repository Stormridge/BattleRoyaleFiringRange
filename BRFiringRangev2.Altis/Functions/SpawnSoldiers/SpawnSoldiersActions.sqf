/*
	File: SpawnSoldiersActions.sqf
	Description: Actions for creating soldiers
	Created By: Stormridge
*/
_run = true;

actionEnabled = false;
	
while {_run} do
{
	
	if (player distance Arrow_SpawnSoliders < 15 && !actionEnabled) then
	{
		SpawnSoldersAction_Headgear = player addAction["Create Soldiers to Test Headgear", "Functions\SpawnSoldiers\SpawnSoldiers.sqf", ["headgear"], 1.5, false];
		SpawnSoldersAction_Vests = player addAction["Create Soldiers to Test Vests", "Functions\SpawnSoldiers\SpawnSoldiers.sqf", ["vest"], 1.5, false];
		SpawnSoldersAction_Uniforms = player addAction["Create Soldiers to Test Uniforms", "Functions\SpawnSoldiers\SpawnSoldiers.sqf", ["uniform"], 1.5, false];
		actionEnabled = true;
		
		nul = ["<t color='#EEEEEE' size = '.6'>Action menu (mousewheel) items added for creating units only in this area of the map."] spawn BIS_fnc_dynamicText;

	};
	
	if (player distance Arrow_SpawnSoliders > 15 && actionEnabled) then
	{
		player removeAction SpawnSoldersAction_Headgear;
		player removeAction SpawnSoldersAction_Vests;
		player removeAction SpawnSoldersAction_Uniforms;
		actionEnabled = false;
	};
	
	sleep 1;	
};
