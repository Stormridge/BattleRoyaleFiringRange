/*---------------------------------------------------------------------------
By Stormridge, after spectating a match of losers
---------------------------------------------------------------------------*/
BRFR_IsPositionASLIndoors =
{
	private _surfaces = lineIntersectsSurfaces [_this, _this vectorAdd [0,0,50], player, objNull, true, 1, "GEOM", "NONE"];
	if (count _surfaces > 0) exitWith {(_surfaces select 0 select 3) isKindOf "House"};
	false
};

BRFR_GetWallIntersections = 
{
	private ["_camCheck", "_eyeCheck", "_tempArray", "_camPositionASL", "_playerPositionASL"];
	_tempArray = [];
	_playerPositionASL =  getposASL player;
	_eyeCheck = lineIntersectsSurfaces [eyePos player, _playerPositionASL vectorAdd [0,0,2], player, objNull, true, 2, "GEOM", "NONE"];
	if (count _eyeCheck > 0) then 
	{
		{
			_tempArray pushBack [(_x select 3),1];	// Pushback with glitch type = 1
			diag_log format["//////////////////////   Found Object=%1, Type = %2", (_x select 3), typeof (_x select 3)];
		} foreach (_eyeCheck);
	};

	_camPositionASL = AGLToASL positionCameraToWorld [0,0,0];
	if ( (!(_camPositionASL call BRFR_IsPositionASLIndoors)) && 
		_playerPositionASL call BRFR_IsPositionASLIndoors) then 
	{
		diag_log "Cam is outdoors, Player indoors.  Checking for intersections...";
		_camCheck = lineIntersectsSurfaces [_camPositionASL, _playerPositionASL vectorAdd [0,0,2], player, objNull, true, 2, "GEOM", "NONE"];
		if (count _camCheck > 0) then 
		{
			{
				_tempArray pushBack [(_x select 3),2]; // pushback with glitch type = 2
				diag_log format["//////////////////////  Smart CamCheck -  Found Object=%1, Type = %2",(_x select 3), typeof (_x select 3)];
			} foreach (_camCheck);
		};
	}
	else
	{
		diag_log "Cam is NOT outdoors WITH Player indoors.  Checking for intersections...";
		_camCheck = lineIntersectsSurfaces [_camPositionASL, _playerPositionASL vectorAdd [0,0,2], player, objNull, true, 2, "GEOM", "NONE"];
		if (count _camCheck > 0) then 
		{
			{
				_tempArray pushBack [(_x select 3),3]; // Pushback with glitch type = 3
				diag_log format["//////////////////////  Basic CamCheck -  Found Object=%1, Type = %2",(_x select 3), typeof (_x select 3)];
			} foreach (_camCheck);
		};
	};
	_tempArray
};

BRFR_LeaningActions = actionKeys "leanLeft" + actionKeys "leanRight"; //actionKeys "leanLeftToggle" + actionKeys "leanRightToggle";
BRFR_ObjectTypesIgnore = ["Land_Slum_House01_F","Land_Slum_House02_F","Land_Slum_House03_F", "Land_u_Shop_02_V1_F", "Land_i_Shop_02_V1_F", "Land_Offices_01_V1_F", "Land_Airport_Tower_F"];
BRFR_IsPlayerLeaning = false;

[] spawn
{
	private ["_isScreenUp", "_objectList" ,"_isGlitching", "_animState"];
	_isScreenUp=false;
	while {alive player} do 
	{
		_animState = animationState player;
		if (vehicle player == player &&
			 cameraView == "EXTERNAL" &&
			 //BRFR_IsPlayerLeaning &&
			 !(_animState isEqualTo "aovrpercmrunsraswrfldf")) then 
		{
			_objectList = call BRFR_GetWallIntersections;
			if (count _objectList > 0) then 
			{
				while {true} do
				{
					diag_log format["//////////////////////   _objectList is %1", _objectList];
					_isGlitching = false;
					{
						_intersectionObject = _x select 0;
						_intersectionType = _x select 1;
						if (_intersectionObject isKindOf "House") then 
						{
							if !(typeOf _intersectionObject in BRFR_ObjectTypesIgnore) then 
							{
								if (_intersectionType == 3) then // Weaker detection.
								{
									diag_log "Weak detection triggered.  Sleeping";
									//sleep (random 4 max 2);
									// Check again.
									if (count (call BRFR_GetWallIntersections) > 0) then
									{
										cutText["Stop poking your head through walls!","BLACK FADED",4];
										_isScreenUp = true;
										_isGlitching = true;
									};
								}
								else
								{
									diag_log "Stronger detection triggered.  Sleeping";
									//sleep (random 2 max 1);
									// Check again.
									if (count (call BRFR_GetWallIntersections) > 0) then
									{
										cutText["Stop poking your head through walls!","BLACK FADED",4];
										_isScreenUp = true;
										_isGlitching = true;
									};
								};
							};
						};
						if (_isGlitching) exitWith {};
					} foreach _objectList;

					if !(_isGlitching) exitWith{if (_isScreenUp) then {cutText ["","PLAIN"]; _isScreenUp=false;}};
					sleep 3;
					_objectList = call BRFR_GetWallIntersections;
					diag_log format["//////////////////////   _objectList is %1", _objectList];					
				};
			};
		};
		sleep 2;
	};
};

	// _eh = (findDisplay 46) displayAddEventHandler ["KeyDown",{
	// 	if((_this select 1) in BRFR_LeaningActions) then {
	// 		BRFR_IsPlayerLeaning = true;
	// 	};
	// 	false
	// }];
	// _eh = (findDisplay 46) displayAddEventHandler ["KeyUp",{
	// 	if((_this select 1) in BRFR_LeaningActions) then {
	// 		BRFR_IsPlayerLeaning = false;
	// 	};
	// 	false
	// }];