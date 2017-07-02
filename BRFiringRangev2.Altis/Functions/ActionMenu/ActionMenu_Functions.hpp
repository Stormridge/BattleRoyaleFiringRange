/*
	
	Description: Sets up player action menu
	Created By: Stormridge
	
*/

BRFR_Temp_CreateCarWithOccupant = {
	private ["_pos", "_vehClass", "_newVehicle", "_unit", "_group"];

	_pos = (getPosATL player) vectorAdd[2,2,0];
	
	_vehClass = G_CAR_OPTIONS select floor random count G_CAR_OPTIONS;

	_newVehicle = _vehClass createVehicle _pos;

	_newVehicle setVariable["PLAYER_MADE",true,true];		// Do this so it doesn't get cleaned up.

	_group = createGroup WEST;
	_unit = _group createUnit ["B_BattleRoyalePlayer_F", [random 100,random 100,0], [], 0, "CAN_COLLIDE"];

	_unit forceAddUniform "U_Rangemaster";
	_unit addVest "V_Press_F";
	_unit addHeadgear "H_HelmetLeaderO_oucamo";

	_unit setVelocity[0,0,0];
	_unit setPosATL (_pos vectorAdd [4,4,0]);
	{_unit disableAI _x} forEach ["AUTOTARGET", "FSM", "MOVE", "TARGET"];
	_unit allowFleeing 0;
	_unit moveinDriver _newVehicle;

	_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];
	_unit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];

	systemChat "AI Created with Tier 2 vest + T5 helm.";
};

//###############################
// Initialize player action menu
//###############################
BRFR_Actions_InitializeActions = {
	
	removeAllActions player;	// If player dies we need to remove these first...
	
	player addAction["=> Change My Loadout", { call BRFR_Actions_PlayerLoadout_Init;}, nil, 1.5, false];
	player addAction["=> Create Test Soldier", { call BRFR_Actions_CreateSoldier_Init;}, nil, 1.5, false];
	player addAction["Tracing Enable", {[player,10] spawn BIS_fnc_traceBullets;}, nil, 1.5, false];
	player addAction["Tracing Disable", {[player,0] spawn BIS_fnc_traceBullets;}, nil, 1.5, false];
	player addAction["=> Create Vehicle", { call BRFR_Actions_CreateVehicle_Init;}, nil, 1.5, false];
	player addAction["Return to Spawn", {player setVelocity [0, 0, -5]; player setPos ([getPos teleportTo select 0,getPos teleportTo select 1,(getPos teleportTo select 2)]);}, nil, 1.5, false];
	player addAction["=> Virtual Arsenal (Non BR gear)", {["Open",true] spawn BIS_fnc_arsenal}, nil, 1.5, false];


	player addAction["=> Create car with occupant", { call BRFR_Temp_CreateCarWithOccupant;}, nil, 1.5, false];

};