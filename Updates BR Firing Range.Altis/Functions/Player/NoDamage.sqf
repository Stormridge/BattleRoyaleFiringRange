/*
	Created By: Stormridge
	
*/
sleep 30;
_vulnerable = false;
while {alive player} do
{
	sleep 3;
	if (player distance teleportTo < 200) then
	{
		player allowDamage False;
		if (_vulnerable) then {
			_vulnerable = false;
			nul = ["<t color='#EEEEEE' size = '.5'>You are back in the safe area."] spawn BIS_fnc_dynamicText;
		};
	}
	else 
	{
		player allowDamage true;
		if (!_vulnerable) then {
			_vulnerable = true;
			nul = ["<t color='#EEEEEE' size = '.5'>You have moved outside the safe area and are vulnerable to damage."] spawn BIS_fnc_dynamicText;
		};
	};	
};