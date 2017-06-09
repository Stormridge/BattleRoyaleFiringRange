/*---------------------------------------------------------------------------
Created by Stormridge.  In 30 mins.

It's late and I don't care.
---------------------------------------------------------------------------*/
BRFR_LRN2Equipment = {
	switch (_this) do 
	{
		case "vest_armor":
		{
			private ["_playerVestName", "_vestDisplayName", "_vestHitPoints", "_cfgName", "_hpName" , "_hpArmor", "_hpPassthrough"];
			_playerVestName = vest player;
			if !(_playerVestName isEqualTo "") then {
				if (isClass (configFile >> "CfgWeapons" >> _playerVestName)) then 
				{
					_vestDisplayName = getText (configFile >> "CfgWeapons" >> _playerVestName >> "displayName");
					_vestHitPoints = "true" configClasses (configFile >> "CfgWeapons" >> _playerVestName >> "ItemInfo" >> "HitpointsProtectionInfo");
					if (count _vestHitPoints > 0) then
					{
						disableSerialization;
						createDialog "BRFR_Oracle_ArmorReport"; 
						waitUntil {!isNull findDisplay 9003};
						private _display = uiNameSpace getVariable ["BRFR_Oracle_ArmorReport", displayNull];
						private _messageCtrl = _display displayCtrl 2221;
						setMousePosition [0.5, 0.5];

						_firstTime=true;
						private _output = format["Your vest, the %1, has armor. <br/><br/>", _vestDisplayName];

						{
							_cfgName = configName _x;
							_hpName = getText(_x >> "hitpointName");
							_hpName = [_hpName, 3] call BIS_fnc_trimString;
							_hpArmor = getNumber(_x >> "armor");
							_hpPassthrough = getNumber(_x >> "passThrough");
							_hpPassthrough = _hpPassthrough * 100;
							_hpImpact = 100 - _hpPassthrough;
							if (_firstTime) then {
								_firstTime=false;
								_output = _output + format["For your %1, your vest has %2 armor, and offers a %4 percent reduction in damage before the bullet passes on to other hitboxes. <br/>", _hpName,_hpArmor,_hpPassthrough, _hpImpact];
							}
							else 
							{
								_output = _output + format["For %1, %2 armor, %4 percent passthrough reduction.<br/>", _hpName,_hpArmor,_hpPassthrough, _hpImpact];
							};
							// sleep 1.5
						} foreach _vestHitPoints;

						_messageCtrl ctrlSetStructuredText parseText _output;
					}
					else
					{
						systemChat format["Your vest, %1, has no armor.  I suggest you don't get shot at.", _vestDisplayName];
					};
				}
				else
				{
					systemChat "I don't know anything about that particular vest.";
				};
			}
			else
			{
				systemChat "Equip a vest, then perhaps I'll tell you about it.";
			};
		};
		
		case "uniform_armor":
		{
			private ["_playerUniformName", "_uniformDisplayName", "_uniformVehClassText", "_uniformHitPoints", "_cfgName", "_hpName" , "_hpArmor", "_hpPassthrough"];		
			
			_playerUniformName = uniform player;

			if !(_playerUniformName isEqualTo "") then {

				if (isClass (configFile >> "CfgWeapons" >> _playerUniformName)) then 
				{
					_uniformDisplayName = getText (configFile >> "CfgWeapons" >> _playerUniformName >> "displayName");
					_uniformVehClassText = getText (configFile >> "CfgWeapons" >> _playerUniformName >> "ItemInfo" >> "uniformClass");
					_uniformHitPoints =  "true" configClasses (configFile >> "CfgVehicles" >> _uniformVehClassText >> "HitPoints");
					if (count _uniformHitPoints > 0) then
					{
						disableSerialization;
						createDialog "BRFR_Oracle_ArmorReport"; 
						waitUntil {!isNull findDisplay 9003};
						private _display = uiNameSpace getVariable ["BRFR_Oracle_ArmorReport", displayNull];
						private _messageCtrl = _display displayCtrl 2221;
						setMousePosition [0.5, 0.5];

						_firstTime=true;
						private _output = format["Your uniform, the %1, has armor.  <br/><br/>", _uniformDisplayName];
						{
							_cfgName = configName _x;
							_hpName = [_cfgName, 3] call BIS_fnc_trimString;
							_hpArmor = getNumber(_x >> "armor");
							_hpPassthrough = getNumber(_x >> "passThrough");
							_hpPassthrough = _hpPassthrough * 100;
							_hpImpact = 100 - _hpPassthrough;
							if (_firstTime) then {
								_firstTime=false;
								_output = _output + format["For your %1, your uniform has %2 armor, and offers a %4 percent reduction in damage before the bullet passes on to other hitboxes.<br/>", _hpName,_hpArmor,_hpPassthrough, _hpImpact];
							}
							else 
							{
								_output = _output + format["For %1, %2 armor, %4 percent passthrough reduction.<br/>", _hpName,_hpArmor,_hpPassthrough, _hpImpact];
							};
						} foreach _uniformHitPoints;

						_messageCtrl ctrlSetStructuredText parseText _output;
					}
					else
					{
						systemChat format["Your uniform, %1, has no armor.  I suggest you don't get shot at.", _uniformDisplayName];
					};
				}
				else
				{
					systemChat "I don't know anything about that particular uniform.";
				};
			}
			else
			{
				systemChat "Equip a uniform, then perhaps I'll tell you about it.";
			};
		};

	};

};
