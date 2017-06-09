/*
	Created By: Stormridge
*/
#include "..\..\includes\globals.hpp"

private ["_ammountItem","_refreshTime"];
_amountItem = 5;
_refreshTime = 300;  //refill every 5 minutes

_this allowDamage false;

if (isServer) then {

	while {true} do
	{
		// clear box
		clearWeaponCargoGlobal _this;
		clearMagazineCargoGlobal _this;
		clearItemCargoGlobal _this;
		
		{
			_this addWeaponCargoGlobal[_x,_amountItem];
		} forEach (G_WEAPON_OPTIONS);
		sleep _refreshTime;
	};
};