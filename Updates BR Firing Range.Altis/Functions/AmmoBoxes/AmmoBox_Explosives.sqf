/*
	Created By: Stormridge
*/
private["_amountWeapon","_amountItem","_amountGrenade","_amountGrenade6","_refreshTime"];

_amountWeapon = 20;
_amountItem = 30;
_amountGrenade = 30;
_amountGrenade6 = 20;
_refreshTime = 300;  //refill every 5 minutes

_this allowDamage false;

_BR_MAGS_1RND = [
	"ItemRedgull",
	"FirstAidKit",
	"1Rnd_HE_Grenade_shell",								//40mm HE Grenade Round
	"3Rnd_HE_Grenade_shell",								//40mm 3Rnd HE Grenade
	"3Rnd_Smoke_Grenade_shell",								//3Rnd 3GL Smoke Rounds (White)
	"3Rnd_SmokeRed_Grenade_shell",							//3Rnd 3GL Smoke Rounds (Red)
	"HandGrenade",											//RGO Grenade
	"MiniGrenade",											//RGN Grenade			
//	"KPFS_HGr_dm41",											//DM41 frag grenade						(German Weapon Pack A3)
	"1Rnd_Smoke_Grenade_shell",						//Smoke Round (White)
	"1Rnd_SmokeRed_Grenade_shell",					//Smoke Round (Red)
	"1Rnd_SmokeGreen_Grenade_shell",				//Smoke Round (Green)
	"1Rnd_SmokeBlue_Grenade_shell",					//Smoke Round (Blue)
	"CUP_1Rnd_HE_GP25_M",							//VOG-25 (HE)							(CUP Weapons Pack)
	"CUP_1Rnd_SmokeRed_GP25_M",						//GP-25 Smoke Shell (Red)				(CUP Weapons Pack)
	"CUP_1Rnd_SmokeGreen_GP25_M",					//GP-25 Smoke Shell (Green)				(CUP Weapons Pack)
	"CUP_1Rnd_SmokeYellow_GP25_M",					//GP-25 Smoke Shell (Yellow)			(CUP Weapons Pack)
	"APERSBoundingMine_Range_Mag",					//APERS Bounding Mine
	"APERSMine_Range_Mag",					 		//APERS Mine
	"APERSTripMine_Wire_Mag",								//APERS Tripwire Mine
	"ClaymoreDirectionalMine_Remote_Mag",			//Claymore Charge
	"SatchelCharge_Remote_Mag",						//Explosive Satchel
	"SLAMDirectionalMine_Wire_Mag",					//M6 SLAM Mine
	"Chemlight_blue",									//Chemlight (Blue)
	"Chemlight_green",									//Chemlight (Green)
	"Chemlight_red",									//Chemlight (Red)
	"Chemlight_yellow",									//Chemlight (Yellow)
	"acc_flashlight",
	"acc_pointer_IR"
];
_BR_MAGS_6RND = [
	"CUP_6Rnd_HE_M203"
];

if (isServer) then {
	while {true} do
	{
		// clear box
		clearWeaponCargoGlobal _this;
		clearMagazineCargoGlobal _this;
		clearItemCargoGlobal _this;

		// Fill box
		//Explosives
		{
			if (_x == "ItemRedgull" || _x == "FirstAidKit" || _x == "acc_flashlight" || _x == "acc_pointer_IR") then
			{
				_this addItemCargoGlobal[_x, _amountItem];
			} 
			else 
			{
				_this addMagazineCargoGlobal[_x,_amountItem];
			};
		} forEach (_BR_MAGS_1RND);

		{
			_this addMagazineCargoGlobal[_x,_amountGrenade6];
		} forEach (_BR_MAGS_6RND);
		sleep _refreshTime;
	};
};