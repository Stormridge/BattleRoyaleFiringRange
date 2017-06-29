/*
	Created By: Stormridge
*/
#include "..\..\includes\globals.hpp"

private ["_ammountItem","_refreshTime"];
_amountItem = 10;
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
			_this addItemCargoGlobal [_x,_amountItem];
		} forEach (G_VEST_OPTIONS);
		
		sleep _refreshTime;
	};
};