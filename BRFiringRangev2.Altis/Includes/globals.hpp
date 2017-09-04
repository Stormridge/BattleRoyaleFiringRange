/*

	Description: Global definitions
	Created By: Stormridge
	
*/
//##################################
// Global Variables
//##################################

if (isNil "BRFR_Globals_defined") then 
{
	BRFR_Globals_defined = true;
	// ["HitFace","HitNeck","HitHead","HitPelvis","HitAbdomen","HitDiaphragm","HitChest","HitBody","HitArms","HitHands","HitLegs"],



	//####################################################
	// Stormridge's custom damage model for Arma3 BR
	//   This is hacked into the Firing Range, and not
	//		guaranteed to be what I'm running in BR LIVE.
	//####################################################
	//####################################################
	// Variables
	//####################################################
	////////// HELMETS
	BR_GEAR_HELMET_TIER5 = [
		"H_HelmetLeaderO_ocamo",	//Defender Helmet (Hex)
        "H_HelmetLeaderO_oucamo" 	//Defender Helmet (Urban)
	];
	BR_GEAR_HELMET_TIER4 = [
		"H_HelmetSpecB_blk",    //Enhanced Combat Helmet (Black)
		"H_HelmetSpecB_paint2", //Enhanced Combat Helmet (Desert)
		"H_HelmetSpecO_blk" 	//Assassin Helmet
	];
	BR_GEAR_HELMET_TIER3 = [
		"H_HelmetCrew_B",   		//Crew Helmet (NATO
		"H_HelmetCrew_I", 			// AAF
		"H_PilotHelmetFighter_I"	//Pilot
	];
	BR_GEAR_HELMET_TIER2 = [
		"H_HelmetB_paint",      //Combat Helmet (Spraypaint)
		"H_HelmetIA_net",       //MICH (Camo)
		"H_HelmetB_camo",       //Combat helmet (Camo)          
		"H_CrewHelmetHeli_B", 	// Heli Crew Helmet
		"H_CrewHelmetHeli_O" 	// Heli Crew Helmet
	];
	BR_GEAR_HELMET_TIER1 = [ ];
	////////// VESTS
	BR_GEAR_VEST_TIER45 = [
		"V_PlateCarrierSpec_rgr",	//Carrier Special Rig (Green)
		"V_PlateCarrierSpec_blk"	//Carrier Special Rig (Black)
	];
	BR_GEAR_VEST_TIER3 = [
		"V_PlateCarrier1_blk",		//Carrier Lite (Black)  
        "V_PlateCarrierIA1_dgtl",   //GA Carrier Lite (Digi)
        "V_PlateCarrierL_CTRG"		//CTRG Plate Carrier Rik Mk.1 [Light]
	];
	BR_GEAR_VEST_TIER2 = [
        "V_TacVest_blk_POLICE",	//Tactical Vest (Police)
        "V_Press_F"				//Vest (Press)
	];
	BR_GEAR_VEST_TIER1 = [
		"V_TacVestIR_blk",      //Raven Vest
	    "V_TacVest_oli",        //Tactical Vest (Olive)
        "V_TacVest_blk",        //Tactical Vest (Black)
        "V_TacVest_brn",		//Tactical Vest (Brown)
        "V_TacVestCamo_khk",    //Camouflaged Vest
        "V_TacVest_camo",       //Tactical Vest (Camo)
        "V_TacVest_khk",        //Tactical Vest (Khaki)
		"V_RebreatherB"   		//Rebreather [NATO]
    ];
	BR_GEAR_VEST_TIER0_NOTCHECKED = [
		"V_Chestrig_blk",       //Fighter Chestrig (Black)
        "V_HarnessO_brn",       //LBV Harness
        "V_HarnessOSpec_brn",	//ELBV Harness
        "V_HarnessOGL_brn",     //LBV Grenadier Harness
        "V_BandollierB_blk",    //Slash Bandolier (Black)
        "V_BandollierB_oli"     //Slash Bandolier (Olive)
	];
	////////// AMMO
	BR_AMMO_ROUND_TYPE_EXPLOSIVE_CFGTYPES = ["FuelExplosion",
												"G_40mm_HEDP",
												"G_40mm_HE",
												"mini_Grenade",
												"GrenadeHand",
												"APERSMine_Range_Ammo",
												"APERSBoundingMine_Range_Ammo",
												"APERSTripMine_Wire_Ammo",
												"CUP_PipeBomb_Ammo",
												"ClaymoreDirectionalMine_Remote_Ammo",
												"SLAMDirectionalMine_Wire_Ammo",
												"CUP_R_PG7VR_AT"
	];
	BR_AMMO_ROUND_TYPE_SNIPER_CFGTYPES = [
											"CUP_B_762x67_noTracer_Ball",		// G22
											"B_127x108_APDS",
											"B_127x108_Ball",					// Lynx
											"CUP_B_86x70_Ball_noTracer", 		// Lapua
											"CUP_B_127x108_Ball_Green_Tracer"	// KSVK
	];
	BR_AMMO_ROUND_TYPE_762_CFGTYPES = [ 
										"CUP_B_762x51_Tracer_White",			// LMG
										"CUP_B_762x51_noTracer",				// LMG
										"CUP_B_762x51_Tracer_Yellow",			// LMG
										"CUP_B_762x51_Tracer_Red",				// LMG
										"CUP_B_762x54_Ball_Green_Tracer",		// LMG PKP
										"CUP_B_762x54_Ball_Red_Tracer",			// LMG
										"CUP_B_762x54_Ball_White_Tracer",		// LMG, SVD
										"CUP_B_762x54_Ball_Yellow_Tracer", 		// LMG
										"CUP_B_762x54_Ball_Green_Tracer",		// PKM, UK59
										"B_762x51_Ball", 						// CZ805, FAL, MK17 and others
										"CUP_B_762x39_Ball_Tracer_Green", 		// SA58, AKM, AKS
										"CUP_B_762x39_Ball", 					// SA58, AKM, AKS
										"SMA_B_762x35_BLK_EPR",					// SMA 762
										"SMA_B_762x35_SS"						// SMA 762
	];
	BR_AMMO_ROUND_TYPE_655_CFGTYPES = [
										"B_65x39_Caseless_green", 				// Katiba, MX
										"B_65x39_Caseless"
	];
	BR_AMMO_ROUND_TYPE_556_CFGTYPES = ["B_556x45_Ball",				 		// 556 Stanag
										"B_556x45_Ball_Tracer_Red",			// 556 Stanag Tracer
										"FHQ_B_556x45_Ball_Tracer_IR",		// 556 Tracer IR
										"B_556x45_dual",					// 556 Under Water
										"CUP_B_545x39_Ball",				// AK
										"CUP_B_545x39_Ball_Tracer_White" 	// AK White Tracer
	];
	BR_AMMO_ROUND_TYPE_SMG_CFGTYPES = [ "CUP_B_9x18_Ball",				// Bizon
										"CUP_B_9x19_Ball",				// Uzi, MP5, Evo
										"B_45ACP_Ball",					// SMG 1 Vermin, some pistols
										"B_45ACP_Ball_Green",			// SMG 1 Green
										"B_9x21_Ball",					// SMGs and pistols (Scorpion, PDW, Sting, Protector)
										"CUP_B_765x17_Ball"				// Sa61
	];
	BR_AMMO_ROUND_TYPE_SHOTGUN_CFGTYPES = ["CUP_B_12Gauge_Pellets"];
	BR_AMMO_ROUND_TYPE_HUNTING_CFGTYPES = [
										"CUP_B_303_Ball", 						//Lee
										"CUP_B_93x64_Ball"			 			// Hunting
	];

	BR_ENUM_AMMO_ROUND_TYPE_EXPLOSIVE = 0;
	BR_ENUM_AMMO_ROUND_TYPE_SNIPER = 1;
	BR_ENUM_AMMO_ROUND_TYPE_762 = 2;
	BR_ENUM_AMMO_ROUND_TYPE_655 = 3;
	BR_ENUM_AMMO_ROUND_TYPE_556 = 4;
	BR_ENUM_AMMO_ROUND_TYPE_SMG = 5;
	BR_ENUM_AMMO_ROUND_TYPE_SHOTGUN = 6;
	BR_ENUM_AMMO_ROUND_TYPE_EMPTY = 7;
	BR_ENUM_AMMO_ROUND_TYPE_HUNTING = 8;

	BR_ENUM_HITBOX_HEAD = 0;
	BR_ENUM_HITBOX_BODY = 1;
	BR_ENUM_HITBOX_LEGS = 2;
	BR_ENUM_HITBOX_OVERALL = 3;

	BR_HITBOX_HEAD_HITPART_REFERENCES = [0,1,2];
	BR_HITBOX_BODY_HITPART_REFERENCES = [3,4,5,6,7,8,9,11];
	BR_HITBOX_LEGS_HITPART_REFERENCES = [10];
	BR_HITBOX_SPECIAL_HITPART_REFERENCES = [-1];

	BR_PLAYER_HIT_EVENT_TRACKER = "BRHITEVENT1";
	BR_PLAYER_HIT_LAST_IMPACT = "BRHITLAST";
	BR_PLAYER_HIT_LAST_IMPACT_KILLEDME = "BRHITLAST_KILL";

	BR_DMG_BULLET_SEPARATION_MIN_TIME = .04;	// Arma can't keep up with lower values

	br_lastHitEventTickTime = 0;
	br_lastExplosionTime = 0;

	/*---------------------------------------------------------------------------
	STRM: Look up ammo types based on projectile.
	---------------------------------------------------------------------------*/
	BR_DamageHandler_AmmoTypeLookup = 
	{
		if (_this in BR_AMMO_ROUND_TYPE_556_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_556};
		if (_this in BR_AMMO_ROUND_TYPE_655_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_655};
		if (_this in BR_AMMO_ROUND_TYPE_SMG_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_SMG};
		if (_this in BR_AMMO_ROUND_TYPE_SNIPER_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_SNIPER};
		if (_this in BR_AMMO_ROUND_TYPE_762_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_762};
		if (_this in BR_AMMO_ROUND_TYPE_EXPLOSIVE_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_EXPLOSIVE};
		if (_this in BR_AMMO_ROUND_TYPE_SHOTGUN_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_SHOTGUN};
		if (_this in BR_AMMO_ROUND_TYPE_HUNTING_CFGTYPES) exitWith {BR_ENUM_AMMO_ROUND_TYPE_HUNTING};
		BR_ENUM_AMMO_ROUND_TYPE_EMPTY
	};
	/*---------------------------------------------------------------------------
	STRM: Determine which hitbox was affected by this bullet.
	---------------------------------------------------------------------------*/
	BR_DamageHandler_HitBoxLookup = 
	{
		if (_this in BR_HITBOX_HEAD_HITPART_REFERENCES) exitWith {BR_ENUM_HITBOX_HEAD};
		if (_this in BR_HITBOX_BODY_HITPART_REFERENCES) exitWith {BR_ENUM_HITBOX_BODY};
		if (_this in BR_HITBOX_LEGS_HITPART_REFERENCES) exitWith {BR_ENUM_HITBOX_LEGS};
		if (_this in BR_HITBOX_SPECIAL_HITPART_REFERENCES) exitWith {BR_ENUM_HITBOX_OVERALL};
		BR_ENUM_HITBOX_BODY
	};
	/*---------------------------------------------------------------------------
	STRM: Get hitbox string name
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetHitBoxNameStringFromIndex = 
	{
		switch (_this) do 
		{
			case 0 : { "head" };
			case 1 : { "body" };
			case 2 : { "legs" };
			case 3 : { "core body" };
			default { "unknown" };
		};
	};
	/*---------------------------------------------------------------------------
	STRM: Get ammo generic name
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetAmmoGenericName = 
	{
		switch (_this) do 
		{
			case BR_ENUM_AMMO_ROUND_TYPE_556 : { "assault rifle ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_655 : { "6.55mm ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_SMG : { "small arms ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_762 :  { "large caliber ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_SNIPER :  { "sniper ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_EXPLOSIVE :  { "an explosion" };
			case BR_ENUM_AMMO_ROUND_TYPE_SHOTGUN :  { "shutgun pellets" };
			case BR_ENUM_AMMO_ROUND_TYPE_HUNTING : { "bolt-action rifle ammo" };
			case BR_ENUM_AMMO_ROUND_TYPE_EMPTY : { "the environment" };
			default { "unknown" };
		};
	};
	/*---------------------------------------------------------------------------
	STRM: Gets helmet tier - pass in player object
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetHelmetTier = 
	{
		private _hg = headgear _this;
		if (_hg in BR_GEAR_HELMET_TIER5) exitWith {5};
		if (_hg in BR_GEAR_HELMET_TIER4) exitWith {4};
		if (_hg in BR_GEAR_HELMET_TIER3) exitWith {3};
		if (_hg in BR_GEAR_HELMET_TIER2) exitWith {2};
		if (_hg isEqualTo "") exitWith {0};
		1
	};
	/*---------------------------------------------------------------------------
	STRM: Gets vest tier - pass in player object
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetVestTier = 
	{
		private _vest = vest _this;
		if (_vest in BR_GEAR_VEST_TIER45) exitWith {5};
		if (_vest in BR_GEAR_VEST_TIER3) exitWith {3};
		if (_vest in BR_GEAR_VEST_TIER2) exitWith {2};
		if (_vest in BR_GEAR_VEST_TIER1) exitWith {1};
		0
	};	
	/*---------------------------------------------------------------------------
	STRM: Get damage reduction from helmet
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetHelmetDmgReduction =
	{
		private _hg = headgear _this; // .001ms - optimize
		if (_hg in BR_GEAR_HELMET_TIER5) exitWith {.7};
		if (_hg in BR_GEAR_HELMET_TIER4) exitWith {.45};
		if (_hg in BR_GEAR_HELMET_TIER3) exitWith {.4};
		if (_hg in BR_GEAR_HELMET_TIER2) exitWith {.2};
		0
	};
	/*---------------------------------------------------------------------------
	STRM: Get damage reduction from Vest
	---------------------------------------------------------------------------*/
	BR_DamageHandler_GetVestDmgReduction =
	{
		private _hg = vest _this; // .001ms - optimize
		if (_hg in BR_GEAR_VEST_TIER45) exitWith {.71};
		if (_hg in BR_GEAR_VEST_TIER3) exitWith {.64};
		if (_hg in BR_GEAR_VEST_TIER2) exitWith {.51};
		if (_hg in BR_GEAR_VEST_TIER1) exitWith {.45};
		0
	};
	// BR_ENUM_AMMO_ROUND_TYPE_BASEDAMAGE_VALUES = [ 	// Must match ENUM above.  Value of hit against unarmored player, to CHEST.
	// 	0, 		// Explosive, NOT USED.
	// 	3,		// Sniper
	// 	.58, 	// 762
	// 	.5,		// 655
	// 	.4,		// 556
	// 	.35,	// SMG
	// 	3,		// SHOTGUN @ short range, but must fall off
	// 	0,		// Environment, NOT USED.
	// 	1.2 	// Lee, CZ550 Hunting rifle
	// ];
	BR_ENUM_AMMO_ROUND_TYPE_BASEDAMAGE_VALUES = [ 	// Must match ENUM above.  Value of hit against unarmored player, to CHEST.
		0, 		// Explosive, NOT USED.
		3,		// Sniper
		.65, 		// 762
		.6,		// 655
		.51,	// 556
		.35,	// SMG
		3,		// SHOTGUN @ short range, but must fall off
		0,		// Environment, NOT USED.
		1 	// Lee, CZ550 Hunting rifle
	];
	BR_HEAD_DAMAGE_MULTIPLIER = 3;
	BR_LEG_DAMAGE_MULTIPLIER = .5;
	BR_EMPTY_DAMAGE_MULTIPLIER = .5;

	/*---------------------------------------------------------------------------
	STRM: Apply base damage to a hitbox
	---------------------------------------------------------------------------*/
	BR_DamageHandler_ApplyRawDamageToHitbox = 
	{
		params [
			"_unit",
			"_hitboxIndex",
			"_projectileBaseDamageAmount",
			"_instigator"
		];
		private _resultDamageTotalDone = 0;
		private _armorDmgReductionPercent = 0;

		switch (_hitboxIndex) do 
		{
			case BR_ENUM_HITBOX_HEAD :
				{
					_resultDamageTotalDone = BR_HEAD_DAMAGE_MULTIPLIER * _projectileBaseDamageAmount * ( 1 - ( _unit call BR_DamageHandler_GetHelmetDmgReduction ) );
				};
			case BR_ENUM_HITBOX_BODY :
				{
					_resultDamageTotalDone = _projectileBaseDamageAmount * ( 1 - ( _unit call BR_DamageHandler_GetVestDmgReduction ) );
				};
			case BR_ENUM_HITBOX_LEGS :
				{
					_resultDamageTotalDone = BR_LEG_DAMAGE_MULTIPLIER * _projectileBaseDamageAmount * ( 1 - (( _unit call BR_DamageHandler_GetVestDmgReduction ) * .5) );	// Vest affects legs by 50%
				};
			case BR_ENUM_HITBOX_OVERALL :
				{
					_resultDamageTotalDone = _projectileBaseDamageAmount * ( 1 - (( _unit call BR_DamageHandler_GetVestDmgReduction ) ) );
				};
			default
				{
					_resultDamageTotalDone = _projectileBaseDamageAmount;
				};
		};
		_resultDamageTotalDone
	};
	/*---------------------------------------------------------------------------
	STRM: Apply damage to a BR HitBox
	---------------------------------------------------------------------------*/
	BR_DamageHandler_ApplyHitBoxDamage = 
	{
		params [
			"_unit",
			"_instigator", // Can be objNull:CarCrash|CoreBody, FallDamage|Body
		    "_hitbox",
		    "_projectile",
		    "_engineProposedDamageValue",
		    "_unitHealthNow"
		];
		private _resultDamageTotalDone = 0; // How much dmg bullet did to player

		// DEBUG ONLY
		private _hitboxStringName = _hitbox call BR_DamageHandler_GetHitBoxNameStringFromIndex;
		//diag_log format["[HIT_BOX_DAMAGE] _hitbox=%1 	name=%2 	_projectile=%3 	", _hitbox, _hitboxStringName, _projectile];

		private _ammoType = _projectile call BR_DamageHandler_AmmoTypeLookup;

		// DEBUG ONLY
		private _ammoTypeGenericName = (_ammoType call BR_DamageHandler_GetAmmoGenericName);
		//diag_log format["[HIT_BOX_DAMAGE] _ammoType=%1 	_ammoTypeGenericName=%2", _ammoType,_ammoTypeGenericName];
		//systemChat format["%1 hit target in %2 from %3m with %4", name (vehicle _instigator), _hitboxStringName, _instigator distance _unit, _ammoTypeGenericName];

		switch (_ammoType) do 
		{ 
			case BR_ENUM_AMMO_ROUND_TYPE_EXPLOSIVE : // player additem "minigrenade"; 
				{
					_resultDamageTotalDone = _engineProposedDamageValue;
				};
			case BR_ENUM_AMMO_ROUND_TYPE_SHOTGUN :
				{
					private _distanceToShooter = _unit distance _instigator;
					private _shotgunDamage = 0;
					if (_distanceToShooter < 3) then { _shotgunDamage = 1; };			
					if (_distanceToShooter >= 3 && _distanceToShooter < 7) then  { _shotgunDamage = .6 * ( 1 - ( .6 * (_unit call BR_DamageHandler_GetVestDmgReduction ) ) ); };
					if (_distanceToShooter >= 7 && _distanceToShooter < 12) then { _shotgunDamage = .45 * ( 1 - (  1 * (_unit call BR_DamageHandler_GetVestDmgReduction ) ) ); };
					if (_distanceToShooter >= 12 && _distanceToShooter < 25) then 
					{
						_shotgunDamage = linearConversion [15, 25, _distanceToShooter,				.45 * ( 1 - (  1 * (_unit call BR_DamageHandler_GetVestDmgReduction ) ) ), 0, true];
					};
					_resultDamageTotalDone = _shotgunDamage;
				};
			case BR_ENUM_AMMO_ROUND_TYPE_EMPTY :
				{
					_resultDamageTotalDone = ((_engineProposedDamageValue - _unitHealthNow) * BR_EMPTY_DAMAGE_MULTIPLIER);
				};
			default 
				{
					_resultDamageTotalDone = [_unit, _hitbox, BR_ENUM_AMMO_ROUND_TYPE_BASEDAMAGE_VALUES select _ammoType, _instigator] call BR_DamageHandler_ApplyRawDamageToHitbox;
				}; 
		};

		_unitHealthNow = _unitHealthNow + _resultDamageTotalDone;

		_unit setDamage _unitHealthNow;

		// if (_unitHealthNow >= .8) then
		// {
		// 	_unit setHitIndex[9,.3];
		// }
		// else
		// {
			_unit setHitIndex[9,0];	 // hands
			_unit setHitIndex[10,0]; // legs
		//};

		if (_unitHealthNow >= 1) then
		{
			_unit setVariable [BR_PLAYER_HIT_LAST_IMPACT_KILLEDME, [_instigator, _hitbox, _ammoType] ];
		};

		_unit setVariable [BR_PLAYER_HIT_LAST_IMPACT, [_instigator, _hitbox, _ammoType] ];

		systemChat format["You did %1 damage to target.", _resultDamageTotalDone];
		//diag_log format["	[RESULT RESULT RESULT]  IMPACT caused damage = %1", _resultDamageTotalDone];
	};
	//####################################################
	// Event Definition
	//####################################################
	player addEventHandler ["HandleDamage", {_this call BR_DamageHandler} ];

	br_hit_array = [];
	
	BR_DamageHandler =
	{ 

		params [
		    "_unit",						// 0
		    "_selection",					// 1
		    "_engineProposedDamageValue",	// 2
		    "_source", 						// 3
		    "_projectile",					// 4
		    "_hitPartIndex",				// 5
		    "_instigator",					// 6
		    "_hitPointCfgName"				// 7
		];

		private _unitHealthNow = damage _unit;
		diag_log format["[HIT_POINT] TIME:%8 		hitSel: %1 	engineProposedDmg: %2 	source: %3 	proj: %4 	hitPartIndex: %5 	inst: %6 	point: %7 	unit: %9", _selection, _engineProposedDamageValue, _source, _projectile, _hitPartIndex, _instigator, _hitPointCfgName, diag_tickTime, _unit];
		if ((_hitPartIndex == -1)  || (_hitPointCfgName == "Incapacitated") || (isNull _instigator)) exitWith {_unitHealthNow;};
		//|| (_engineProposedDamageValue == _unitHealthNow)
		if (diag_tickTime - br_lastHitEventTickTime > (BR_DMG_BULLET_SEPARATION_MIN_TIME) ) then
		{
			timer_start = diag_tickTime;

			br_lastHitEventTickTime = diag_tickTime;
			br_hit_array = [];
			br_hit_array set  [_hitPartIndex, [_engineProposedDamageValue, _unit, _selection, _source, _projectile, _instigator]];
			hit_loops = 0;

			diag_log format["[FIRST_DETECTED_HITBOX] TIME:%8 		hitSel: %1 	engineProposedDmg: %2 	source: %3 	proj: %4 	hitPartIndex: %5 	inst: %6 	point: %7 	unit: %9", _selection, _engineProposedDamageValue, _source, _projectile, _hitPartIndex, _instigator, _hitPointCfgName, diag_tickTime, _unit];
		}
		else
		{
			if (isNil {br_hit_array select _hitPartIndex} ) then
			{
				br_hit_array set [_hitPartIndex, [_engineProposedDamageValue, _unit, _selection, _source, _projectile, _instigator]];
				hit_loops = hit_loops + 1;
				diag_log format["[SECONDARY_HITBOXES] TIME:%8 		hitSel: %1 	engineProposedDmg: %2 	source: %3 	proj: %4 	hitPartIndex: %5 	inst: %6 	point: %7 	unit: %9", _selection, _engineProposedDamageValue, _source, _projectile, _hitPartIndex, _instigator, _hitPointCfgName, diag_tickTime, _unit];

			}
			else // just ignore any additional hits
			{
				if (true) exitWith {hit_loops = hit_loops + 1;};
			};
			//	if ( ((br_hit_array select _hitPartIndex) select 0) > _engineProposedDamageValue ) then
			//	{
			//		systemChat format["Second hit detected"];
			//		systemChat format["Old %1",((br_hit_array select _hitPartIndex) select 0)];
			//		systemChat format["New %1",_engineProposedDamageValue];
			//
			//		br_hit_array = br_hit_array set [_hitPartIndex,objNull];
			//		br_hit_array = br_hit_array - [objNull];
			//		br_hit_array set [_hitPartIndex, [_engineProposedDamageValue, _unit, _selection, _source, _projectile, _instigator]];
			//		
			//	};
			//};
			//
		};


		if (hit_loops == 10) then //execute when we got data from every hitbox
		{

			br_hit_array sort false; //sort array with largest value at top 
			_hitbox = ((br_hit_array select 0) select 2);
			
			systemChat format ["Target %1 hit in %2 with %3 (%4 damage)",_unit, _hitbox, _projectile, _engineProposedDamageValue];
			//{
			//systemChat format ["%1",_x];
			//} forEach br_hit_array;
			timer_end = diag_tickTime;
			systemChat format ["Hit processing time = %1",timer_end - timer_start];

		};		
		_unitHealthNow
	};
	/////////////////////////////////////////////////////////////////////////////////////



	BRFR_HINT_PAUSE=false;

	BRFROracleObject=objNull;
	BRFROracleAction1=-1;
	
	//##################################
	// Global Variables
	//##################################	
	GROUP_AI_DRIVERS = CreateGroup Civilian;

	BRFR_Dialog_CreateSoldier_Uniform_LastIndex					= 0;
	BRFR_Dialog_CreateSoldier_Vest_LastIndex						= 0;
	BRFR_Dialog_CreateSoldier_Headgear_LastIndex				= 0;
	BRFR_Dialog_CreateSoldier_Backpack_LastIndex				= 0;
	BRFR_Dialog_CreateSoldier_Distance_LastIndex				= 0;
	BRFR_Dialog_CreateSoldier_DamageReport_OnOff				= 0;

	BRFR_Dialog_PlayerLoadout_Uniform_LastIndex				= 0;
	BRFR_Dialog_PlayerLoadout_Vest_LastIndex						= 0;
	BRFR_Dialog_PlayerLoadout_Headgear_LastIndex				= 0;
	BRFR_Dialog_PlayerLoadout_Backpack_LastIndex				= 0;
	BRFR_Dialog_PlayerLoadout_Weapon_LastIndex				= 0;
	BRFR_Dialog_PlayerLoadout_Optic_LastIndex					= 0;
	BRFR_Dialog_PlayerLoadout_Ammo_LastIndex					= 0;
	//BRFR_PlayerLoadout_Combo_Suppressor_LastIndex			= 0;

	//##################################
	// Uniform and Weapon Configs
	//##################################
	G_CLOTHING_OPTIONS = [
		// "U_O_V_Soldier_Viper_F",						//Special Purpose suit (Hex)		(Apex DLC)
		// "U_O_T_FullGhillie_tna_F",   						//Full Ghillie (Jungle) [CSAT]				(Apex DLC)
		// "U_B_T_FullGhillie_tna_F",   						//Full Ghillie (Jungle) [NATO]				(Apex DLC)
		// "U_B_T_Sniper_F",   									//Ghillie Suit (Tropic) [NATO]				(Apex DLC)
		// "U_B_T_Soldier_SL_F",	   							//Recon Fatigues (Tropic)				(Apex DLC)
		// "U_O_T_Officer_F",	   								//Officer Fatigues (Green Hex) [CSAT]	(Apex DLC)
		// "U_O_T_Soldier_F",	   								//Fatigues (Green Hex) [CSAT]			(Apex DLC)
		// "U_O_OfficerUniform_ocamo",	   						//Officer Fatigues (Hex)
		// "U_O_SpecopsUniform_ocamo",	   						//Recon Fatigues (Hex)
		// "U_O_CombatUniform_oucamo",	   						//Fatigues (Urban) [CSAT]
		// "U_B_CTRG_Soldier_F",	   							//CTRG Stealth Uniform					(Apex DLC)
		// "U_B_CTRG_Soldier_3_F",	   							//CTRG Stealth Uniform (Rolled-up)		(Apex DLC)
		// "U_I_C_Soldier_Para_2_F",	   						//Paramilitary Garg (Jacket)			(Apex DLC)
		// "U_B_GEN_Commander_F",	   							//Gendarmerie Commander Uniform			(Apex DLC)
		// "U_B_GEN_Soldier_F",	   							//Gendarmerie Uniform					(Apex DLC)
		// "U_B_T_Soldier_F", 	 	   						//Combat Fatigues (Tropic)				(Apex DLC)
		// "U_B_T_Soldier_AR_F",	   						//Combat Fatigues (Tropic, Tee)			(Apex DLC)
		// "U_B_SpecopsUniform_sgg",	   					//Specop Fatigues (Sage)
		// "U_I_C_Soldier_Para_1_F", 	   					//Paramilitary Garb (Tee)				(Apex DLC)
		// "U_I_C_Soldier_Para_5_F", 	   					//Paramilitary Garb (Shorts)			(Apex DLC)
		// "U_I_C_Soldier_Para_3_F",	   					//Paramilitary Garb (Shirt)				(Apex DLC)
		// "U_C_man_sport_2_F",	 	 	   				//Sport Clothes (Orange)				(Apex DLC)
		// "U_C_man_sport_3_F",	   						//Sport Clothes (Blue)					(Apex DLC)
		// "U_O_T_Soldier_F",	   							//Fatigues (Green Hex) [CSAT]			(Apex DLC)
		// "U_B_T_Soldier_F",	   							//Combat Fatigues (Tropic)				(Apex DLC)
		// "U_B_CTRG_Soldier_urb_1_F", 	 	   			//CTRG Urban Uniform					(Apex DLC)
		// "U_B_CTRG_Soldier_urb_3_F",	   					//CTRG Urban Uniform (Rolled-up)		(Apex DLC)
		// "U_B_CTRG_Soldier_urb_2_F",	   					//CTRG Urban Uniform (Tee)				(Apex DLC)
		"U_I_CombatUniform",	   							//Combat Fatigues [AAF]
		"U_I_CombatUniform_tshirt",	   						//Combat Fatigues [AAF] (Officer)
		"U_I_CombatUniform_shortsleeve",	   				//Combat Fatigues [AAF] (Rolled-up)
		"U_B_CombatUniform_mcam_tshirt",	   				//Combat Fatigues (MTP) (Tee)
		"U_KerryBody",	   									//Combat Fatigues (Kerry)			THESE HAVE NO INVENTORY SPACE
		"U_MillerBody",	   									//Combat Fatigues (Miller)			THESE HAVE NO INVENTORY SPACE
		"IRA_Soldier_Outfit_4",	   							//DPM Combat Jacket (Brown trousers)(Northern Ireland Insurgents pack)
		"U_O_CombatUniform_oucamo",	   						//Fatigues (Urban) [CSAT]
		"U_B_GhillieSuit",   								//Ghillie Suit [NATO]
		"U_I_GhillieSuit",   								//Ghillie Suit [AAF]
		"U_O_GhillieSuit",   								//Ghillie Suit [CSAT]
		"U_OG_Guerilla1_1",	   								//Guerilla Garment
		"U_BG_leader",	   									//Guerilla Uniform
		"U_OG_Guerilla3_2", 	   						//Guerilla Smocks 1
		"U_OG_Guerilla3_1",	   		   					//Guerilla Smocks
		"IRA_Soldier_Outfit_7",	   							//Guinness T-Shirt (Black)			(Northern Ireland Insurgents pack)
		"U_C_HunterBody_grn",	   						//Hunting Clothes
		"U_OrestesBody",	   								//Jacket and Shorts
		"U_C_Journalist",	   							//Journalist Clothes
		"U_NikosBody",	 	 	   						//Nikos Clothes
		"U_O_OfficerUniform_ocamo",	   						//Officer Fatigues (Hex)
		"U_O_SpecopsUniform_ocamo",	   						//Recon Fatigues (Hex)
		"U_B_SpecopsUniform_sgg",	   						//Specop Fatigues (Sage)
		"IRA_Soldier_Outfit_9",	   							//Shirt w/Rolled Sleeves (Green)	(Northern Ireland Insurgents pack)
		"U_NikosAgedBody",	   							//Underwear 1
		"IRA_Soldier_Outfit_6",		   						//Woolly Pully (Brown)				(Northern Ireland Insurgents pack)
		"IRA_Soldier_Outfit_8",	   							//Woolly Pully (Green)				(Northern Ireland Insurgents pack)
		"U_O_Wetsuit",   								//Wetsuit [CSAT]
		"U_B_Wetsuit"	   									//Wetsuit [NATO]
	];

	G_VEST_OPTIONS = [

		// "V_PlateCarrierSpec_tna_F",   						//Carrier Special Rig (Tropic)				(Apex DLC)
		// "V_PlateCarrier2_tna_F	",   						//Carrier Rig (Tropic)						(Apex DLC)				//Level4, PELVIS FIX!!!!!!!

		// "V_PlateCarrier1_tna_F",	   						//Carrier Lite (Tropic)					(Apex DLC)
		// "V_TacChestrig_oli_F",	   							//Tactical Chest Rig (Olive)			(Apex DLC)
		// "V_TacVest_gen_F",									//Gendarmerie Vest						(Apex DLC)
		// "V_HarnessO_ghex_F",	   							//LBV Harness (Green Hex)				(Apex DLC)
		// "V_HarnessOGL_ghex_F",	   						//LBV Grenadier Harness (Green Hex)		(Apex DLC)
		// "V_BandollierB_cbr",	   						//Slash Bandolier (Coyote)
		// "V_BandollierB_ghex_F",	   						//Slash Bandolier (Green Hex)			(Apex DLC)

		"V_TacVestCamo_khk",	   						//Camouflaged Vest
		"V_PlateCarrierSpec_rgr",   					//Carrier Special Rig (Green)
		"V_PlateCarrier1_blk",	   							//Carrier Lite (Black)	
		"V_Chestrig_blk",	   							// Chestrig (Black)
		// "V_PlateCarrierH_CTRG",								//CTRG Plate Carrier Rik Mk.2 [Heavy]
		"V_PlateCarrierL_CTRG",							//CTRG Plate Carrier Rik Mk.2 [Light]
		"V_HarnessOSpec_brn",	   						//ELBV Harness
		"V_PlateCarrierIA1_dgtl",							//GA Carrier Lite (Digi)
		"V_HarnessO_brn",	   		   					//LBV Harness
		"V_HarnessOGL_brn",	   							//LBV Grenadier Harness
		"V_TacVestIR_blk",	   							//Raven Vest
		"V_RebreatherB",   								//Rebreather [NATO]
		"V_BandollierB_blk",	   						//Slash Bandolier (Black)
		"V_BandollierB_oli",	   						//Slash Bandolier (Olive)
		// "Specter_MBSS_BLK",	   							//SG MBSS (Black)					(Specter Armaments Pack)
		// "Specter_MBSS_TAN",	   							//SG MBSS (Tan)						(Specter Armaments Pack)	
		// "Specter_MBSS_light",	   							//SG MBSS Light (Green)				(Specter Armaments Pack)
		// "Specter_MBSS_light_BLK",	   					//SG MBSS Light (Black)				(Specter Armaments Pack)
		// "Specter_MBSS_PACA_l",   							//SG MBSS + PACA light (Green)			(Specter Armaments Pack)
		// "Specter_RAV_BLK",   								//SG RAV (Black))						(Specter Armaments Pack)		
		"V_TacVest_blk_POLICE",								//Tactical Vest (Police)
		"V_TacVest_camo",	   							//Tactical Vest (Camo)
		"V_TacVest_khk",	   							//Tactical Vest (Khaki)
		"V_TacVest_oli",	   							//Tactical Vest (Olive)
		"V_TacVest_blk",	   							//Tactical Vest (Black)
		"V_TacVest_brn",	   								//Tactical Vest (Brown)		
		"V_Press_F"	   		   								//Vest (Press)
	];

	G_HEADGEAR_OPTIONS = [
		// "H_Booniehat_tna_F", 	   						//Booniehat (Tropic)					(Apex DLC)
		// "H_HelmetB_Light_tna_F", 	   					//Light Combat Helmet (Tropic)			(Apex DLC)
		// "H_Beret_gen_F",	   								//Beret (Gendarmerie)					(Apex DLC)
		// "H_MilCap_gen_F",	   								//Military Cap (Gendarmerie)			(Apex DLC)
		// "H_MilCap_ghex_F",	   								//Military Cap (Green Hex)				(Apex DLC)
		// "H_MilCap_tna_F",	   								//Military Cap (Tropic)					(Apex DLC)
		// "H_Shemag_khk",	   									//Shemag mask (Khaki)
		// "H_HelmetLeaderO_ghex_F",							//Defender Helmet (Green Hex)			(Apex DLC)
		// "H_HelmetLeaderO_oucamo",							//Defender Helmet (Urban)
		// "H_HelmetCrew_O_ghex_F",	   						//Crew Helmet (Green Hex) [CSAT]		(Apex DLC)
		// "H_HelmetB_TI_tna_F",	   							//Stealth Combat Helmet					(Apex DLC)
		// "H_HelmetB_Enh_tna_F",	   							//Enhanced Combat Helmet (Tropic)		(Apex DLC)
		// "H_HelmetSpecB_blk", 	   							//Enhanced Combat Helmet (Black)
		// "H_HelmetSpecB_paint2", 	   						//Enhanced Combat Helmet (Desert)
		// "H_HelmetB_snakeskin",	   							//Combat Helmet (Snakeskin)
		// "H_HelmetO_ghex_F",	   								//Protector Helmet (Green Hex)			(Apex DLC)
		// "H_Helmet_Skate",	// apex
		"H_Bandanna_camo", 	   							//Bandanna (Camo)
		"H_BandMask_demon", 	   						//Bandanna Mask (Demon)
		"H_Watchcap_blk", 	   							//Beanie
		"H_Watchcap_camo",	   							//Beanie (Green)
		"H_Watchcap_khk", 	   							//Beanie (Khaki)
		"H_Beret_blk_POLICE",	   							//Beret (Police)
		"H_Beret_brn_SF",	   								//Beret (SAS)
		"H_Beret_grn_SF",	   							//Beret (SF)
		"H_TurbanO_blk", 	   							//Black Turban
		"H_Booniehat_dirty", 	   						//Booniehat (Dirty)
		"H_Booniehat_grn", 	   							//Booniehat (Green)
		"H_Booniehat_mcamo",	   						//Booniehat (MTP)
		"H_Booniehat_tan",	   							//Booniehat (Tan)
		"H_HelmetCrew_I",	   							//Crew Helmet [AAF]
		"H_HelmetB_camo",	   								//Combat helmet (Camo)			
		"H_HelmetB_paint",	   								//Combat Helmet (Spraypaint)
		"H_HelmetLeaderO_ocamo",							//Defender Helmet (Hex)
		"H_HelmetLeaderO_oucamo",							//Defender Helmet (Urban)
		"H_HelmetSpecB_blk", 	   						//Enhanced Combat Helmet (Black)
		"H_HelmetSpecB_paint2", 	   					//Enhanced Combat Helmet (Desert)
		"H_Hat_camo", 	   								//Hat (Camo)
		"H_HelmetIA_net",	   								//MICH (Camo)		
		"H_MilCap_rucamo",	   								//Military Cap (Russia)
		"H_MilCap_oucamo",	   								//Military Cap (Urban)
		"H_PilotHelmetFighter_I",	   						//Pilot Helmet [AAF]		
		"H_Shemag_olive", 	   							//Shemag (Olive)
		"H_Shemag_khk",	   								//Shemag mask (Khaki)
		"H_StrawHat"	   								//Straw Hat
		// "H_Titan_Helmet",									//SG Titan helmet					(Specter Armaments Pack)
		// "H_Titan_Helmet_O"									//SG Titan helmet(open visor)		(Specter Armaments Pack)
	];

	G_BACKPACK_OPTIONS = [
		// "B_Carryall_ghex_F",	   							//Carryall Backpack (Green Hex)		(Apex DLC)			!!!ADD TO WHITELIST
		// "B_Carryall_cbr",	   								//Carryall Backpack (Coyote)
		// "B_Carryall_khk",	   								//Carryall Backpack (Khaki)
		// "B_ViperHarness_blk_F",	   							//Viper Harness (Black)				(Apex DLC)			!!!ADD TO WHITELIST
		// "B_ViperHarness_ghex_F",	   						//Viper Harness (Green Hex)			(Apex DLC)			!!!ADD TO WHITELIST
		// "B_ViperHarness_khk_F",	   							//Viper Harness (Khaki)				(Apex DLC)			!!!ADD TO WHITELIST
		// "B_Kitbag_sgg",	   									//Kitbag (Sage)											!!!ADD TO WHITELIST
		// "B_Kitbag_mcamo",	   								//Kitbag (MTP)
		// "B_FieldPack_ghex_F",	   							//Field Pack (Green Hex)			(Apex DLC)			!!!ADD TO WHITELIST
		// "B_AssaultPack_tna_F",   						//Assault Pack (Tropic)					(Apex DLC)			!!!ADD TO WHITELIST
		// "B_ViperLightHarness_oli_F",   					//Viper Light Harness (Olive)			(Apex DLC)			!!!ADD TO WHITELIST
		// "B_ViperLightHarness_hex_F",		   				//Viper Light Harness (Hex)				(Apex DLC)			!!!ADD TO WHITELIST
		"B_AssaultPack_blk",   							//Assault Pack (Black)				
		"B_AssaultPack_cbr",   							//Assault Pack (Coyote)
		"B_AssaultPack_dgtl",   						//Assault Pack (Digi)
		"B_AssaultPack_rgr",   							//Assault Pack (Green)
		"B_AssaultPack_khk",   							//Assault Pack (Khaki)
		"B_AssaultPack_mcamo",   						//Assault Pack (MTP)
		"B_AssaultPack_sgg",   							//Assault Pack (Sage)
		"B_Bergen_blk",	   									//Bergen (Black)
		"B_Bergen_rgr",	   									//Bergen (Green)
		"B_Bergen_mcamo",	   								//Bergen (MTP)
		"B_Bergen_sgg",	   									//Bergen (Sage)
		"B_Carryall_cbr",	   								//Carryall Backpack (Coyote)
		"B_Carryall_khk",	   								//Carryall Backpack (Khaki)
		"B_Carryall_mcamo",	   								//Carryall Backpack (MTP
		"B_Carryall_oucamo",	   							//Carryall Backpack (Urban)
		"B_FieldPack_blk",	   								//Field Pack (Black)
		"B_FieldPack_oucamo",	   							//Field Pack (Urban)
		"B_HuntingBackpack",   							//Hunting Backpack			
		"B_Kitbag_mcamo",	   								//Kitbag (MTP)
		"B_OutdoorPack_blu"   							//Outdoor Pack (Blue)
	];

	G_DISTANCE_OPTIONS = [
		5,25,50,75,100,150,200,300,400,500,600,700,800,900,1000,1200,1500
	];

	G_WEAPON_OPTIONS = [
		"CUP_srifle_G22_des",
		//"CUP_srifle_AWM_des",
		"CUP_arifle_XM8_Compact_Rail",
		"CUP_launch_RPG7V",
		"CUP_l85a2_ugl",
		// "LMG_03_F",										//LIM-85 5.56 mm					(Apex DLC)

		// "arifle_AK12_F",									//AK-12								(Apex DLC)
		// "arifle_AK12_GL_F",									//AK-12 GL							(Apex DLC)
		// "arifle_SPAR_03_blk_F",								//SPAR-17 7.62 mm (Black)			(Apex DLC)
		// "arifle_SPAR_03_khk_F",								//SPAR-17 7.62 mm (Khaki)			(Apex DLC)
		// "arifle_SPAR_03_snd_F",								//SPAR-17 7.62 mm (Sand)			(Apex DLC)

		// "srifle_LRR_tna_F", 								//M320 LRR .408 (Tropic)				(Apex DLC)
		// "arifle_TRG21_GL_F",									//TRG-21 EGLM 5.56 mm
		// "arifle_Mk20_GL_F",										//Mk20 EGLM 5.56 mm (Camo)
		// "arifle_SPAR_01_GL_blk_F",								//SPAR-16 GL 5.56 mm (Black)			(Apex DLC)
		// "arifle_SPAR_01_GL_khk_F",								//SPAR-16 GL 5.56 mm (Khaki)			(Apex DLC)
		// "arifle_SPAR_01_GL_snd_F",								//SPAR-16 GL 5.56 mm (Sand)				(Apex DLC)
		// "arifle_SPAR_01_blk_F",							//SPAR-16 5.56 mm (Black)			(Apex DLC)
		// "arifle_SPAR_01_khk_F",	   							//SPAR-16 5.56 mm (Khaki)			(Apex DLC)
		// "arifle_SPAR_01_snd_F",									//SPAR-16 5.56 mm (Sand)			(Apex DLC)
		// "hgun_P07_khk_snds_F",   						//P07 9 mm (Khaki)	(with suppressor)	(Apex DLC)
		// "hgun_Pistol_01_F",   							//PM 9 mm								(Apex DLC)
		// "SMG_05_F",												//Protector 9 mm					(Apex DLC)
		// //5.8 mm Guns
		// "arifle_CTAR_blk_F",									//CAR-95 5.8 mm (Black)					(Apex DLC)
		// "arifle_CTAR_GL_blk_F",								//CAR-95 GL 5.8 mm (Black)				(Apex DLC)			
		// //6.5mm Guns
		// "srifle_DMR_07_ghex_F",								//CMR-76 6.5 mm (Green Hex)				(Apex DLC)
		// "arifle_MX_GL_khk_F",									//MX 3GL 6.5 mm (Khaki)					(Apex DLC)
		// "arifle_MX_khk_F",										//MX 6.5 mm (Khaki)						(Apex DLC)
		// "arifle_MXM_khk_F",									//MXM 6.5 mm (Khaki)					(Apex DLC)

		//"FHQ_M4A1_M203_BLK",									//M4A1 M203 (Black)						(FHQ M4 Pack)
		"CUP_arifle_M4A1_BUIS_GL",								//M4A1 M203 (Black)						(CUP Weapons Pack)
		"CUP_arifle_M4A1_BUIS_camo_GL",							//M4A1 M203 (Woodland)					(CUP Weapons Pack)
		"CUP_arifle_G36A",										//G36A									(CUP Weapons Pack)
		"CUP_arifle_G36C",										//G36C									(CUP Weapons Pack)
		//"CUP_arifle_G36K",										//G36K									(CUP Weapons Pack)
		"CUP_arifle_CZ805_A1",									//CZ 805 A1								(CUP Weapons Pack)
		"CUP_arifle_CZ805_A2",									//CZ 805 A2								(CUP Weapons Pack)
		"CUP_arifle_CZ805_GL",									//CZ 805 A1 GL							(CUP Weapons Pack)
		// "CUP_arifle_L85A2",										//L85A2 Assault Rifle					(CUP Weapons Pack)
		// "CUP_arifle_L85A2_GL",									//L85A2 Assault Rifle  (GL)				(CUP Weapons Pack)
		// "CUP_arifle_L86A2",										//L86A2 LSW								(CUP Weapons Pack)
		"CUP_arifle_Mk16_CQC",									//Mk16 Mod 0 CQC						(CUP Weapons Pack)
		"CUP_arifle_Mk16_STD",									//Mk16 Mod 0 Standard					(CUP Weapons Pack)
		"CUP_arifle_Mk16_STD_EGLM",								//Mk16 Mod 0 Standard EGLM				(CUP Weapons Pack)
		"CUP_arifle_Mk16_SV",									//Mk16 Mod 0 SV							(CUP Weapons Pack)
		"CUP_arifle_AK74_GL",									//AK-74 GP-25							(CUP Weapons Pack)
		"arifle_Katiba_F",										//Katiba 6.5 mm
		"arifle_Katiba_GL_F",									//Katiba GL 6.5 mm
		"arifle_Katiba_C_F",									//Katiba Carbine 6.5 mm
		"arifle_MX_GL_F",										//MX 3GL 6.5 mm
		"arifle_MX_F",											//MX 6.5 mm
		// "Trixie_Enfield_Rail", 									//Lee Enfield Mk III (Rail)				(Trixie's Rifle Pack)
		// "Trixie_CZ550_Rail", 									//CZ 550 w/Rail							(Trixie's Rifle Pack)
		"CUP_srifle_LeeEnfield_rail",
		"CUP_srifle_CZ550_rail",

		"CUP_smg_bizon", 										//PP-19 Bizon							(CUP Weapons Pack)

		"CUP_arifle_M4A1_black",
		"CUP_arifle_M4A1_camo",
		"arifle_SDAR_F",	   								//SDAR 5.56 mm
		"arifle_TRG20_F",	   								//TRG-20 5.56 mm
		"arifle_Mk20C_F",	   								//Mk20C 5.56 mm (Camo)
		"CUP_arifle_AKS74",	   								//AKS-74							(CUP Weapons Pack)
		"CUP_arifle_AKS74U",	   							//AKS-74U							(CUP Weapons Pack)
		"CUP_arifle_AK74",	   								//AK-74								(CUP Weapons Pack)
		"SMG_01_F",	   										//Vermin SMG .45 ACP
		"SMG_02_F",	   										//Sting 9 mm
		"CUP_smg_MP5SD6",	   								//MP5 SD6							(CUP Weapons Pack)
		"CUP_smg_EVO",	   									//Scorpion EVO						(CUP Weapons Pack)
		"CUP_sgun_M1014",	   								//M1014								(CUP Weapons Pack)
		"CUP_sgun_Saiga12K",	   							//Saiga12K							(CUP Weapons Pack)
		
		"arifle_TRG21_F",	   							//TRG-21 5.56 mm
		"hgun_PDW2000_F",   							//PDW2000 9 mm
		"hgun_ACPC2_snds_F",   							//ACP-C2 .45	(with suppressor)
		"hgun_P07_snds_F",   							//P07 9 mm		(with suppressor)
		"hgun_Rook40_snds_F",   						//Rook-40 9 mm	(with suppressor)
		"hgun_Pistol_heavy_02_F",   					//Zubr .45
		"hgun_Pistol_heavy_01_F",   					//4-five .45
		// "KPFS_Walther_PP",	   							//Walther PP						(German Weapon Pack A3)
		// "KPFS_p2104",   								//SIG P210-4						(German Weapon Pack A3)
		"CUP_hgun_Colt1911",   							//M1911								(CUP Weapons Pack)
		"CUP_hgun_Compact",   							//CZ 75 P-07 Compact				(CUP Weapons Pack)
		"CUP_hgun_Duty",   								//CZ 75 P-07 Duty					(CUP Weapons Pack)
		"CUP_hgun_Phantom",   							//CZ 75 SP-01 Phantom				(CUP Weapons Pack)
		"CUP_hgun_M9",   								//M9								(CUP Weapons Pack)
		"CUP_hgun_Makarov",   							//Makarov							(CUP Weapons Pack)
		"CUP_hgun_MicroUzi",   							//Micro UZI PDW						(CUP Weapons Pack)
		"CUP_hgun_TaurusTracker455_gold",   			//Taurus Tracker Model 455 (Gold) 	(CUP Weapons Pack)
		"CUP_hgun_SA61",   								//SA-61								(CUP Weapons Pack)
		"CUP_hgun_Glock17",   							//Glock 17							(CUP Weapons Pack)

		// "Trixie_CZ750",									//CZ750 w/ Harris Bipod (Painted)		(Trixie's Sniper/Marksman Pack)	
		// "Trixie_CZ750_Black",							//CZ750 w/ Harris Bipod (Black)			(Trixie's Sniper/Marksman Pack)	
		// "Trixie_CZ750_Ghillie",							//CZ750 w/ Camo Net						(Trixie's Sniper/Marksman Pack)	
		// "Trixie_AWM338",								//AWM .338 w/ Harris Bipod (Green)		(Trixie's Sniper/Marksman Pack)	
		// "Trixie_AWM338_Black",							//AWM .338 w/ Harris Bipod (Black)		(Trixie's Sniper/Marksman Pack)	
		// "Trixie_AWM338_Ghillie",						//AWM .338 w/ Camo Net					(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M40A3_NG",								//M40A3 w/ Harris Bipod (Green)			(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M40A3_Clean",							//M40A3 (Green)							(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M24",									//M24 w/ Harris Bipod (Camo)			(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M24_Clean",								//M24 (Camo)							(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M24_Black",								//M24 w/ Harris Bipod (Black)			(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M24_Black_Clean",						//M24 (Black)							(Trixie's Sniper/Marksman Pack)	
		// "Trixie_M24_Ghillie",							//M24 w/ Camo Net						(Trixie's Sniper/Marksman Pack)	
		"CUP_srifle_SVD",								//Dragunov SVD							(CUP Weapons Pack)
		"CUP_srifle_ksvk",								//KSVK									(CUP Weapons Pack)		
		
		"CUP_arifle_Sa58RIS1",								//Sa-58 RIS1						(CUP Weapons Pack)
		"CUP_arifle_Sa58RIS1_des",							//Sa-58 RIS1 (Desert)				(CUP Weapons Pack)
		"CUP_arifle_Sa58RIS2",								//Sa-58 RIS2						(CUP Weapons Pack)
		"CUP_arifle_Sa58RIS2_camo",							//Sa-58 RIS2 (Desert)				(CUP Weapons Pack)
		"CUP_arifle_FNFAL_railed",							//FN FAL (railed)					(CUP Weapons Pack)
		"CUP_arifle_Mk17_CQC",								//Mk17 CQC							(CUP Weapons Pack)
		"CUP_arifle_Mk17_STD",								//Mk17 Standard						(CUP Weapons Pack)
		"CUP_arifle_Mk20",									//Mk17 Sniper						(CUP Weapons Pack)
		"CUP_arifle_AKM",									//AKM								(CUP Weapons Pack)
		"CUP_arifle_AKS",									//AKS								(CUP Weapons Pack)
		"CUP_arifle_AKS_Gold",								//AKS		(golden)				(CUP Weapons Pack)
		"CUP_arifle_CZ805_B_GL",							//CZ 805 Bren B1 GL					(CUP Weapons Pack)
		"CUP_arifle_CZ805_B",								//CZ 805 Bren B1					(CUP Weapons Pack)
		
		//"CUP_lmg_M60A4",								//M60E4								(CUP Weapons Pack)
		"CUP_lmg_M240",									//M240								(CUP Weapons Pack)
		"CUP_lmg_PKM",									//PKM								(CUP Weapons Pack)
		"CUP_lmg_UK59",									//UK59								(CUP Weapons Pack)
		"CUP_lmg_Pecheneg",								//PKP Pecheneg						(CUP Weapons Pack)
		"CUP_lmg_Mk48_wdl",								//Mk48 Mod 0 (woodland)				(CUP Weapons Pack)
		"CUP_lmg_L7A2",									//L7A2								(CUP Weapons Pack)
		"CUP_glaunch_Mk13",								//Mk13 EGLM 						(CUP Weapons Pack)
		"CUP_glaunch_M32"								//M32 (the 6-round revolver type)	(CUP Weapons Pack)
	];

	G_MAGAZINE_OPTIONS = [
		"20Rnd_556x45_UW_mag",
		"FHQ_30Rnd_556x45_Stanag_Tracer_Ir",   					//30 Rnd STANAG Tracer IR				(FHQ M4 Pack)
		"30Rnd_556x45_Stanag_Tracer_Red",   					//5.56mm 30rnd Tracer (Red) Mag
		"30Rnd_556x45_Stanag_Tracer_Green",   					//5.56mm 30rnd Tracer (Green) Mag
		"30Rnd_556x45_Stanag_Tracer_Yellow",   					//5.56mm 30rnd Tracer (Yellow) Mag
		"30Rnd_65x39_caseless_green",							//6.5mm 30Rnd Caseless Mag 			  	Katiba Rifles Magazine
		"30Rnd_65x39_caseless_green_mag_Tracer",				//6.5mm 30Rnd Tracer (Green) Mag 		Katiba Rifles Magazine
		"30Rnd_65x39_caseless_mag",								//6.5mm 30Rnd STANAG Mag 				MX Rifles Magazine
		"30Rnd_65x39_caseless_mag_Tracer",						//6.5mm 30Rnd Tracer (Red) Mag  		MX Rifles Magazine
		"CUP_30Rnd_545x39_AK_M",								//30 Rnd AK Magazine
		"CUP_30Rnd_TE1_Green_Tracer_545x39_AK_M",				//30 Rnd AK Magazine (Green Tracers)	(CUP Weapons Pack)
		"CUP_30Rnd_TE1_Red_Tracer_545x39_AK_M",					//30 Rnd AK Magazine (Red Tracers)		(CUP Weapons Pack)	
		"CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",				//30 Rnd AK Magazine (Yellow Tracers)	(CUP Weapons Pack)
		"CUP_30Rnd_Sa58_M",										//SA58 Mag.								(CUP Weapons Pack)
		"CUP_30Rnd_Sa58_M_TracerR",								//SA58 Mag. (green)						(CUP Weapons Pack)				
		"CUP_30Rnd_762x39_AK47_M",								//30 Rnd AK-47 Magazine					(CUP Weapons Pack)
		"CUP_20Rnd_762x51_FNFAL_M",								//20 Rnd FN FAL Magazine				(CUP Weapons Pack)
		"CUP_20Rnd_762x51_B_SCAR",								//20 Rnd Mk17							(CUP Weapons Pack)
		"CUP_20Rnd_TE1_Red_Tracer_762x51_SCAR",					//20 Rnd Mk17 Red Tracer				(CUP Weapons Pack)
		"CUP_20Rnd_TE1_Green_Tracer_762x51_SCAR",				//20 Rnd Mk17 Green Tracer				(CUP Weapons Pack)
		"CUP_20Rnd_762x51_CZ805B",								//20 Rnd CZ805B							(CUP Weapons Pack)
		"CUP_20Rnd_TE1_Red_Tracer_762x51_CZ805B",				//20 Rnd CZ805B Red Tracer				(CUP Weapons Pack)
		"CUP_64Rnd_9x19_Bizon_M",								//64 Rnd Bizon Magazine					(CUP Weapons Pack)
		"CUP_64Rnd_Green_Tracer_9x19_Bizon_M",					//64 Rnd Bizon Magazine (Green Tracers)	(CUP Weapons Pack)
		// "Trixie_CZ550_Mag",										//5Rnd 9.3x62mm							(Trixie's Rifle Pack)
		// "Trixie_10x762_Mag",									//10Rnd 7.62x51m						(Trixie's Sniper/Marksman Pack)			
		// "Trixie_5x338_Mag",										//5Rnd .338 Lapua Magnum				(Trixie's Sniper/Marksman Pack)
		// "Trixie_5x762_Mag",										//5Rnd 7.62x51mm						(Trixie's Sniper/Marksman Pack)
		"CUP_10Rnd_762x54_SVD_M",								//SVD Dragunov Mag.						(CUP Weapons Pack)
		"CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",      //100Rnd. M240							(CUP Weapons Pack)
		"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",       	//100Rnd. M240	(red tracers)			(CUP Weapons Pack)
		"CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M",		//PKM Mag.								(CUP Weapons Pack)
		"CUP_50Rnd_UK59_762x54R_Tracer",						//50rnd UK59							(CUP Weapons Pack)
		"CUP_30Rnd_9x19_EVO",								//30 Rnd EVO							(CUP Weapons Pack)
		"CUP_8Rnd_B_Saiga12_74Slug_M",						//8 Rnd Saiga Slug						(CUP Weapons Pack)
		// "Trixie_Enfield_Mag",							//10Rnd 7.7mm							(Trixie's Rifle Pack)
		"11Rnd_45ACP_Mag",								//.45 ACP 11Rnd Mag
		"6Rnd_45ACP_Cylinder",							//.45 ACP 6Rnd Cylinder
		"9Rnd_45ACP_Mag",								//.45 ACP 9Rnd Mag
		"30Rnd_9x21_Mag",								//9mm 30Rnd Mag
		"16Rnd_9x21_Mag",								//9mm 16Rnd Mag
		// "KPFS_8Rnd_765x17_PP",							//Walther PP magazine					(German Weapon Pack A3)
		// "KPFS_9Rnd_9x19_p210",   						//P210 Magazine							(German Weapon Pack A3)
		"CUP_30Rnd_9x19_UZI",   						//30 Rnd 9x19 MicroUzi					(CUP Weapons Pack)
		"CUP_6Rnd_45ACP_M",   							//6 Rnd ACP								(CUP Weapons Pack)
		"CUP_8Rnd_9x18_Makarov_M",   					//8 Rnd 9x18 Makarov					(CUP Weapons Pack)
		"CUP_8Rnd_9x18_MakarovSD_M",   					//Makarov SD mag						(CUP Weapons Pack)
		"CUP_17Rnd_9x19_glock17",   					//17 Rnd Glock 17 Magazine 				(CUP Weapons Pack)
		"CUP_7Rnd_45ACP_1911",   						//7Rnd M1911							(CUP Weapons Pack)
		"CUP_10Rnd_9x19_Compact",   					//10 Rnd 9x19 Compact					(CUP Weapons Pack)
		"CUP_18Rnd_9x19_Phantom",   					//18 Rnd 9x19 Phantom					(CUP Weapons Pack)
		"CUP_15Rnd_9x19_M9",   							//15 Rnd 9x19 M9						(CUP Weapons Pack)
		"30Rnd_45ACP_Mag_SMG_01",						//.45 ACP 30Rnd Vermin Mag
		"30Rnd_45ACP_Mag_SMG_01_tracer_green",			//.45 30Rnd Vermin Tracers (Green) Mag
		"CUP_30Rnd_9x19_MP5",							//30 Rnd MP5							(CUP Weapons Pack)
		"CUP_8Rnd_B_Beneli_74Slug",					//8 Rnd Slugs							(CUP Weapons Pack)
		"CUP_5Rnd_127x108_KSVK_M"
	];
	
	G_OPTIC_OPTIONS = [

		// "optic_LRPS_tna_F",									//LRPS (Tropic)								(Apex DLC)
		// "optic_DMS_ghex_F",									//DMS (Green Hex)							(Apex DLC)
		// "optic_SOS_khk_F",									//MOS (Khaki)								(Apex DLC)

		// "optic_Arco_blk_F",   								//ARCO (Black)								(Apex DLC)
		// "optic_Arco_ghex_F",   								//ARCO (Green Hex)							(Apex DLC)
		// "optic_ERCO_blk_F",   								//ERCO (Black)								(Apex DLC)
		// "optic_ERCO_khk_F",   								//ERCO (Khaki)								(Apex DLC)
		// "optic_ERCO_snd_F",   								//ERCO (Sand)								(Apex DLC)		
		// "optic_Hamr",										//RCO
		// "optic_Hamr_khk_F",									//RCO (Khaki)								(Apex DLC)
		// "optic_Holosight_khk_F",							//MK17 Holosight (Khaki)					(Apex DLC)
		// "optic_Holosight_blk_F",							//MK17 Holosight (Black)					(Apex DLC)
		// "optic_Holosight_smg_blk_F",						//Mk17 Holosight SMG (Black)				(Apex DLC)
		"FHQ_optic_AC11704",
		"optic_aco",									//ACO (Red)
		"optic_ACO_grn",								//ACO (Green)
		"optic_aco_smg",								//ACO SMG (Red)
		"FHQ_optic_ACOG",   								//ACOG (black)								(FHQ Accessories Pack)
		"FHQ_optic_ACOG_tan",   							//ACOG (tan)								(FHQ Accessories Pack)
		"CUP_optic_CompM4",									//Aimpoint CompM4 (black)					(CUP Weapons Pack)
		"optic_Arco",   									//ARCO
		"optic_DMS",										//DMS
		"CUP_optic_HoloDesert",							//EoTech Holo (black)					(CUP Weapons Pack)
		"acc_flashlight",								//Flashlight
		"acc_pointer_IR",								//IR Laser Pointer
		"CUP_optic_Kobra",   								//Kobra Reflex Sight						(CUP Weapons Pack)
		"CUP_optic_Leupold_VX3",							//Leupold VX-3 4.5-14x50mm					(CUP Weapons Pack)
		"CUP_optic_LeupoldMk4",								//Leupold Mk4								(CUP Weapons Pack)
		"CUP_optic_LeupoldM3LR",							//Leupold Mark 4 3-9x36mm MR/T				(CUP Weapons Pack)
		"CUP_optic_LeupoldMk4_10x40_LRT_Desert",			//Leupold Mark 4 10x40mm LR/T (Desert)		(CUP Weapons Pack)
		"CUP_optic_LeupoldMk4_10x40_LRT_Woodland",			//Leupold Mark 4 10x40mm LR/T (Woodland)	(CUP Weapons Pack)
		"CUP_optic_LeupoldMk4_CQ_T",						//Leupold Mk4 CQ/T 1-3x14mm					(CUP Weapons Pack)
		"optic_LRPS",										//LRPS
		// "trixie_m68cco",								//M68 CCO								(Trixie's Sniper/Marksman Pack)
		// "trixie_m68cco_net",							//M68 CCO w/ Camo Net					(Trixie's Sniper/Marksman Pack)
		"optic_SOS",										//MOS
		"optic_MRCO",   									//MRCO
		"optic_MRD",									//MRD
		"optic_Holosight",								//MK17 Holosight
		"optic_Holosight_smg",							//Mk17 Holosight SMG
		"optic_hamr",										//RCO
		"CUP_optic_PechenegScope",						//Pecheneg Scope							(CUP Weapons Pack)
		"CUP_optic_PSO_1",								//PSO-1 Scope						(CUP Weapons Pack)
		"CUP_optic_PSO_3",								//PSO-3 Scope						(CUP Weapons Pack)
		"CUP_optic_SB_11_4x20_PM",						//Schmidt & Bender 1.1-4x20 PM ShortDot		(CUP Weapons Pack)
		"CUP_optic_ACOG",								//Trijicon ACOG TA31F				(CUP Weapons Pack)
		"CUP_optic_RCO",								//Trijicon ACOG								(CUP Weapons Pack)
		"CUP_optic_RCO_desert",							//Trijicon ACOG (desert)					(CUP Weapons Pack)
		"optic_Yorris"										//Yorris J2
	];

	G_SUPPRESSORS_OPTIONS = [
		"CUP_muzzle_snds_M16",
		// "Trixie_Cyclone",									//AAC Cyclone 7.62						(Trixie's Sniper/Marksman Pack)	
		// "Trixie_Cyclone_Camo",								//AAC Cyclone 7.62 (Camo)				(Trixie's Sniper/Marksman Pack)	
		// "Trixie_Cyclone_Net",								//AAC Cyclone 7.62 (Ghillie)			(Trixie's Sniper/Marksman Pack)		
		"CUP_muzzle_snds_G36_black",						//G36 Silencer (black)						(CUP Weapons Pack)
		//"CUP_muzzle_snds_L85",								//L85 Silencer								(CUP Weapons Pack)
		"CUP_muzzle_snds_SCAR_L",							//Mk16 Silencer								(CUP Weapons Pack)
		"CUP_muzzle_mfsup_SCAR_L",							//Mk16 Flash Hider							(CUP Weapons Pack)
		"CUP_muzzle_snds_SCAR_H",							//Mk17 Silencer								(CUP Weapons Pack)
		"CUP_muzzle_mfsup_SCAR_H",							//Mk17 Flash Hider							(CUP Weapons Pack)
		"CUP_muzzle_PBS4",									//PBS4 silencer								(CUP Weapons Pack)
		"CUP_muzzle_bizon",   								//PP-19 Bizon silencer						(CUP Weapons Pack)
		//"FHQ_M4_muzzle_snds_556_blk",				//Silencer M4 (Black)						(FHQ M4 Pack)
		"muzzle_snds_L",   									//Sound Suppressor (9 mm) 
		"muzzle_snds_acp",   								//Sound Suppressor (.45 ACP)
		"muzzle_snds_M",   									//Sound Suppressor (5.56 mm)
		"muzzle_snds_H",	   								//Sound Suppressor (6.5 mm)
		"muzzle_snds_B",   									//Sound Suppressor (7.62 mm)
		"muzzle_snds_58_blk_F",   							//Sound Suppressor (5.8 mm, Black)			(Apex DLC)
		"muzzle_snds_58_wdm_F",   							//Sound Suppressor (5.8 mm, Green Hex)		(Apex DLC)
		"muzzle_snds_m_khk_F",   							//Sound Suppressor (5.56 mm, Khaki)			(Apex DLC)
		"muzzle_snds_m_snd_F",   							//Sound Suppressor (5.56 mm, Sand)			(Apex DLC)
		"muzzle_snds_H_khk_F",	   							//Sound Suppressor (6.5 mm, Khaki)			(Apex DLC)
		"muzzle_snds_H_snd_F"	   							//Sound Suppressor (6.5 mm, Sand)			(Apex DLC)
	];

	G_CAR_OPTIONS = [
	"C_Van_01_box_F",
	"BAF_Offroad_D",
	"C_Offroad_01_repair_F",
	"beetle_bleufonce",
	"C_Van_01_transport_F"
		// "C_Hatchback_01_F",
		// "C_Hatchback_01_sport_F",
		// "C_Offroad_01_F",
		// "C_SUV_01_F",
		// "C_Van_01_box_F",
		// "C_Van_01_transport_F",
		// "C_Quadbike_01_F",
		// "I_Truck_02_covered_F",

		// //"B_Boat_Transport_01_F","C_Boat_Civil_01_police_F","C_Boat_Civil_01_F","C_Boat_Civil_01_rescue_F","O_Lifeboat",
		// "BAF_Offroad_D" //, "BAF_Offroad_W", "LandRover_CZ_EP1", "LandRover_ACR", "LandRover_TK_CIV_EP1"

	];


};

