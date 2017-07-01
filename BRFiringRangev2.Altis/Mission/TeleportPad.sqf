_run = true;

	b = 0;
	
while {_run} do
{
	
	if (player distance TelePad < 10 && b != 1) then
	{
	Para = player addAction["Teleport to Parachuting Practice", "Functions\Player\Parachute.sqf"];
	
	b = 1;
	};
	
	if (player distance TelePad > 10 && b != 0) then
	{
	
	player removeAction Para;
	b = 0;
	
	};
	
	sleep 1;
	
};
