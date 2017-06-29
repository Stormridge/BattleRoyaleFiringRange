_unit = _this select 0;

removebackpack _unit;
_unit addBackpack "B_Parachute"; 

x = [3000,23150,15498,14100,13000,9000,12800,16100,4800,17200,16800,5500];
y = [13200,18900,16282,11560,12500,12000,16700,17000,22000,13000,12700,15000];

slot = floor random count x;

_unit setPos [x select slot, y select slot, 1000];

_unit removeAction Para;

