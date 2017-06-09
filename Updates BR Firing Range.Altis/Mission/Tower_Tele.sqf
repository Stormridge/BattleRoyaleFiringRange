c = 0;
	
while {true} do
{
	
	if (player distance Tower_1 < 15 && c != 1) then
	{
	TTele = player addAction["Teleport to top of Tower", {TowerTop = getPos Tower_1; player setVelocity [0, 0, 0];player setPos [TowerTop select 0, ((TowerTop select 1)-1),22];}];
	
	c = 1;
	};
	
	if (player distance Tower_1 > 15 && c != 0) then
	{
	
		player removeAction TTele;
		c = 0;
	
	};
	
	sleep 0.5;
	
};