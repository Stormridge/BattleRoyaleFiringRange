_run = true;

	d = 0;
	g = 0;
	
while {_run} do
{
	/*
	if (player distance ATC_1 < 12 && d != 1) then
	{
	ATCTele = player addAction["Teleport to top of ATC", {ATCTop = getPos ATC_1; player setVelocity [0, 0, 0]; player setPos [ATCTop select 0, ((ATCTop select 1) - 5), 12.0];}];
	
	d = 1;
	};
	
	if (player distance ATC_1 > 12 && d != 0) then
	{
	
	player removeAction ATCTele;
	d = 0;
	
	};
	*/
	
	if (player distance ATC_2 < 12 && g != 1) then
	{
	ATCTele2 = player addAction["Teleport to top of ATC", {ATCTop = getPos ATC_2; player setVelocity [0, 0, 0]; player setPos [((ATCTop select 0)+5), ATCTop select 1, 12.0];}];
	
	g = 1;
	};
	
	if (player distance ATC_2 > 12 && g != 0) then
	{
	
	player removeAction ATCTele2;
	g = 0;
	
	};
	
	sleep 1;
	
};