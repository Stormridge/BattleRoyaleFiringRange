/*
	File: SpawnSoldiers.sqf
	Description: Action Methods for creating soldiers
	Created By: Stormridge
*/
SpawnConfigure = {
	_newUnit = _this select 0;
	_actionType = _this select 1;
	_actionItem = _this select 2;
	_dirSoldier = _this select 3;
	_thisSoldierPos = _this select 4;
	
	[_newUnit] execVM "Functions\SpawnSoldiers\SpawnSoldiers_AutoRemoveTimer.sqf";
	_newUnit addEventHandler ["Killed", {[_this] execVM "Functions\SpawnSoldiers\SpawnSoldiers_KilledEvent.sqf"}];
	_newUnit setVariable ['BIS_enableRandomization', false]; 
	_newUnit disableCollisionWith player; 
	[_newUnit,_actionType,_actionItem] execVM "Functions\SpawnSoldiers\SpawnSoldiersLoadout.sqf"; 
	_newUnit disableAI 'MOVE'; 
	_newUnit disableAI 'TARGET';
	_newUnit disableAI 'ANIM'; 
	_newUnit setDir _dirSoldier;
	_newUnit setPos _thisSoldierPos;
};

_target = _this select 0;
_caller = _this select 1;
_id = _this select 2;
_actionType = _this select 3 select 0;

_grp = 0;
_startDistFromPlayer = 5;

_playerPosition = getPos player;
_playerDirection = getDir player;
_playerVectorDir = vectorDir player;

_type = "B_BattleRoyalePlayer_F";	// C_man_1
_distanceModifier = 3;

_dirSoldier = _playerDirection + 90;
_posSoldier = _playerPosition;

createcenter Civilian;
_grp = createGroup Civilian;

switch (_actionType) do {
	case "headgear" : {
		{
			_vNext = _playerVectorDir vectorMultiply (_startDistFromPlayer + _distanceModifier * _foreachIndex);
			_thisSoldierPos = _vNext vectorAdd _playerPosition;
			//_type createUnit [_thisSoldierPos, _grp, "[this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_AutoRemoveTimer.sqf'; this addEventHandler ['Killed', {[_this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_KilledEvent.sqf'}]; this setVariable ['BIS_enableRandomization', false]; this disableCollisionWith player; nul = [this,'headgear',_x]execVM 'Functions\SpawnSoldiers\SpawnSoldiersLoadout.sqf'; this disableAI 'MOVE'; this disableAI 'TARGET';this disableAI 'ANIM'; this setDir _dirSoldier; this setPos _pos;"];
			_newUnit = _grp createUnit [_type, _thisSoldierPos, [], 0, "NONE"];
			[_newUnit,_actionType, _x, _dirSoldier, _thisSoldierPos] call SpawnConfigure;
		} foreach (G_HEADGEAR_OPTIONS);
	};
	case "vest" : {
		{
			_vNext = _playerVectorDir vectorMultiply (_startDistFromPlayer + _distanceModifier * _foreachIndex);
			_thisSoldierPos = _vNext vectorAdd _playerPosition;
			//_type createUnit [_thisSoldierPos, _grp, "[this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_AutoRemoveTimer.sqf'; this addEventHandler ['Killed', {[_this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_KilledEvent.sqf'}]; this setVariable ['BIS_enableRandomization', false]; this disableCollisionWith player; nul = [this,'vest',_x]execVM 'Functions\SpawnSoldiers\SpawnSoldiersLoadout.sqf'; this disableAI 'MOVE'; this disableAI 'TARGET';this disableAI 'ANIM'; this setDir _dirSoldier; this setPos _pos;"];
			_newUnit = _grp createUnit[_type, _thisSoldierPos, [], 0, "NONE"];
			[_newUnit,_actionType, _x, _dirSoldier, _thisSoldierPos] call SpawnConfigure;
		} foreach (G_VEST_OPTIONS);
	};
	case "uniform" : {
		{
			_vNext = _playerVectorDir vectorMultiply (_startDistFromPlayer + _distanceModifier * _foreachIndex);
			_thisSoldierPos = _vNext vectorAdd _playerPosition;
			//_type createUnit [_thisSoldierPos, _grp, "[this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_AutoRemoveTimer.sqf'; this addEventHandler ['Killed', {[_this] execVM 'Functions\SpawnSoldiers\SpawnSoldiers_KilledEvent.sqf'}]; this setVariable ['BIS_enableRandomization', false]; this disableCollisionWith player; nul = [this,'uniform',_x]execVM 'Functions\SpawnSoldiers\SpawnSoldiersLoadout.sqf'; this disableAI 'MOVE'; this disableAI 'TARGET';this disableAI 'ANIM'; this setDir _dirSoldier; this setPos _pos;"];
			_newUnit = _grp createUnit[_type, _thisSoldierPos, [], 0, "NONE"];
			[_newUnit,_actionType, _x, _dirSoldier, _thisSoldierPos] call SpawnConfigure;
		} foreach (G_CLOTHING_OPTIONS);
	};
};