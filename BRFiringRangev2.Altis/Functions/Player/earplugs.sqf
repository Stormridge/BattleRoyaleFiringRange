	
	private ["_unit"];
	_unit = _this select 0;
	
	e = 0;
	
	1 fadeSound 1;
	
	while {alive _unit} do
	{
	
	if (soundVolume != 1 && e == 1) then {
		EOUT = _unit addAction["Remove EarPlugs", {1 fadeSound 1;}];
		_unit removeAction EIN;
		e = 0;
	};
	if (soundVolume == 1 && e == 0) then {
		EIN = _unit addAction["Insert EarPlugs", {1 fadeSound 0.05;}];
		if (!isNil "EOUT") then {_unit removeAction EOUT;};
		e = 1;
	};

	sleep 2;
	
	}