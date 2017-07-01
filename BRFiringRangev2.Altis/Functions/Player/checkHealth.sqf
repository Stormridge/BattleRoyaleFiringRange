/*
	
	Description: UI to display target information
	Updated By: Stormridge
	
*/
private ["_unit", "_health", "_head", "_body", "_legs", "_hands", "_pelvis", "_neck", "_spine3", "_spine1", "_uspeed",
			"_current_target", "_healtht", "_headt", "_bodyt", "_legst", "_handst", "_pelvist", "_neckt", "_spine1t", 
			"_spine3t","_vestt", "_uniformt", "_helmett", "_engineType", "_enginet", "_hullt", "_fuelType", "_fuelt", "_allHitPtsDmgArray"];

// Added by Stormridge so we always have good data...
BRFR_GetHealthStats = {
	private _result = format["Health = %1\n", ceil((1 - (damage _this)) * 100)];
	// _allHitPtsDmgArray = getAllHitPointsDamage _this;
	// if ((count _allHitPtsDmgArray) > 0) then 
	// {
	// 	{
	// 		_result = _result + format["%1 = %2\n",([(_allHitPtsDmgArray select 0) select _forEachIndex, 3] call BIS_fnc_trimString), if (_x>0) then {_x} else {0}];
	// 	} foreach (_allHitPtsDmgArray select 2);
	// };
	_result = _result + format["Speed = %1 km/h\n", floor (speed _this)];
	_result
};

_unit = player;

while {alive _unit} do {

	if !(BRFR_HINT_PAUSE) then 
	{
		_current_target = cursorTarget;
		
		_playerInfo = _unit call BRFR_GetHealthStats;

		//_line1 = format["Your Health = %1\nHead = %2\nFace = %3\nNeck = %4\nBody = %5\nArms = %6\nHands = %7\nLegs = %8\nPelvis = %9\nSpine1 = %10\nSpine2 = %11\nSpine3 = %12\nSpeed = %13 km/h\n-------------------------------------------------\n",
		//					_health,_head,_face,_neck,_body,_arms,_hands,_legs,_pelvis,_spine1,_spine2,_spine3, _uspeed ];

		switch (true) do
		{
			case (_current_target isKindof "Man"): 
			{
				_target = _current_target;
				
				_vestT = gettext(configfile >> "CfgWeapons" >> (vest _target) >> "displayname");
				_uniformT = gettext(configfile >> "CfgWeapons" >> (uniform _target) >> "displayname");
				_helmetT = gettext(configfile >> "CfgWeapons" >> (headgear _target) >> "displayname");
				if (_helmett == "") then {
					_helmett = "None";
				};
				if (_uniformt == "") then {
					_uniformt = "None";
				};
				if (_vestt == "") then {
					_vestt = "None";
				};

				_targetInfo = format["Target = %1\nUniform = %2\nVest = %3\nHelmet = %4\n", name _target,_uniformt,_vestt,_helmett];
				_targetInfo = _targetInfo + (_target call BRFR_GetHealthStats);

				// _line2 = format["Target = %1\nUniform = %2\nVest = %3\nHelmet = %4\nTarget Health = %5\n", _target,_uniformt,_vestt,_helmett,_healtht];
				// _line3 = format["Head = %1\nFace = %2\nNeck = %3\nBody = %4\nArms = %5\nHands = %6\nLegs = %7\nPelvis = %8\nSpine1 = %9\nSpine2 = %10\nSpine3 = %11\n", _headT,_faceT,_neckT,_bodyT,_armsT,_handsT,_legsT,_pelvisT,_spine1T,_spine2T,_spine3T];
				
				hintSilent format["%1-------------------------------------------------\nDistance =%3m\n%2", _playerInfo, _targetInfo, floor (player distance _target)];
			};
			// Stormridge - Start Car Changes - Removed per-car differences
			case (GetText(configfile >> "CfgVehicles" >> (TypeOf(vehicle cursorTarget)) >> "vehicleClass") == "Car"):
			{
				_target = _current_target;
				
				// _engineType = "motor";
				// if (isNil {_target getHit _engineType}) then {_engineType = "engine"};
				// _enginet = _target getHit _engineType;
				_enginet = _target getHitPointDamage "hitengine";
				
				_hullt = _target getHit "karoserie";
				
				_fuelType = "fuel";
				if (isNil {_target getHit _fuelType}) then {_fuelType = "palivo"};
				_fuelt = _target getHit _fuelType;
				// Stormridge - End Car Changes

				_leftfront = _target getHit "wheel_1_1_steering";
				_rightfront = _target getHit "wheel_2_1_steering";
				_leftrear = _target getHit "wheel_1_2_steering";
				_rightrear = _target getHit "wheel_2_2_steering";
			
				_targetInfo = format["Target = %1\nEngine = %2\nHull = %3\nFuelTank = %4\nLeft Front = %5\nRight Front = %6\nLeft Rear = %7\nRight Rear = %8", _target,_enginet,_hullt,_fuelt,_leftfront,_rightfront,_leftrear,_rightrear];

				//hintSilent format ["%1Current Target = %2\n Engine = %3\nHull = %4\nFuel = %5\nLeft Front Tire = %6\nRight Front Tire = %7\nLeft Rear Tire = %8\nRight Rear Tire = %9", 				_enginet,_hullt,_fuelt,_leftfront,_rightfront,_leftrear,_rightrear];
				hintSilent format["%1-------------------------------------------------\n%2", _playerInfo, _targetInfo];

			};
			default 
			{
				hintSilent _playerInfo;
				//hintSilent format["%1", _line1]; //Health = %1\nHead = %2\nChest = %3\nLegs = %4\nHands = %5\nPelvis = %6\nNeck = %7\nspine3 = %8\nspine1 = %9\nSpeed = %10 km/h\n-------------------------------------------------\n",_health,_head,_body,_legs,_hands,_pelvis,_neck,_spine3,_spine1,_uspeed];
			};
		};
	} 
	else {
		hintSilent "";
	};

	sleep 1.5;
};