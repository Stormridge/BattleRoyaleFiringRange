/*

	Description: Battle Royale Firing Range Init
	Created By: Majarkin & Nutty
	Updated By: Stormridge
	
*/
#include "Includes\defines.hpp"	// defines are not global
#include "Includes\globals.hpp"		// global variables
#include "Functions\functions.hpp"	// global functions		

//##################################
// Player setup
//##################################
if (!isDedicated) then {
	diag_log "=== Not Dedicated  ===";
	// Wait for JIP
	waitUntil {!(isNull player)};
	activateKey "stormridge_BRFR";
	markAsFinishedOnSteam;
	
	// TO DO - Put into br updates init.sqf  DONE
	[] spawn {
		disableSerialization;
		waitUntil {! (isnull (uiNamespace getVariable ["BR_GUI_status", objNull]))};
		if ((profileNamespace getVariable ["HPBarInitializedPositionV1", -1]) < 1) then {
			diag_log "User has NOT initialized HP Bar yet.";
			1 cutText ["", "PLAIN"];
			profilenamespace setvariable ["IGUI_GRID_AVCAMERA_X", 1];
			profilenamespace setvariable ["IGUI_GRID_AVCAMERA_Y", 1];
			1 cutRsc ["br_RscDisplayPlayerStatus","PLAIN"];
			profileNamespace setVariable ["HPBarInitializedPositionV1", 1];
			systemChat "Please Note:  You can move the HP bar by going into Configure-Game-Layout, and adjusting the 'AV Camera' position.";
			systemChat "The changes will take effect in the next game you join.";
		} else {
			diag_log "User has already initialized the HB Bar";
		};
	};

	[player] execVM "Functions\Spawn\PlayerSpawnInit.sqf";

} else {
	// Dedicated Server setup
	diag_log "=== Dedicated Server Detected ===";
};

// Server setup
if (isServer) then {[] execVM "Functions\Server\Server_Init.sqf"};
