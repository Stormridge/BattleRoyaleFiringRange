/*
	
	Description: Cleans up created soldier, after killed
	Created By: Stormridge
	
*/

_unit = _this select 0 select 0;

systemChat "Your target is dead.";

[_unit] spawn {
	sleep 10;
	_unit = _this select 0;
	// Remove any attached objects from this AI
	{
		detach _x;
		deleteVehicle _x;
	} foreach (attachedObjects _unit);
	deleteVehicle _unit;
};

///////// HISTORY //////////
private _targetHistoryArray = _unit getVariable["CreateSoldierDamageHistory",[]];
if (count _targetHistoryArray > 0) then 
{
	private _hitPartOrderedTitles = ["Face","Neck","Head","Pelvis","Abdomen","Diaphragm","Chest","Body","Arms","Hands","Legs", "Overall Modifier"];

	
	//diag_log "Waiting 2 seconds for Arma to finalize damage...";
	systemChat "Waiting for Arma to finalize damage events...";
	sleep 1;
	systemChat "Proceeding with damage analysis.";
	//diag_log "Proceeding with damage analysis.";

	// _outputString = "";

	BRFR_HINT_PAUSE=true;

	disableSerialization;
	createDialog "BRFR_CreateSolider_DamageReport"; 
	waitUntil {!isNull findDisplay 9002};
	private _display = uiNameSpace getVariable ["BRFR_CreateSolider_DamageReport", displayNull];
	private _tree = _display displayCtrl 2216;
	setMousePosition [0.5, 0.5];
 
	{
		private ["_fingerprint", "_fingerprintValues", "_dmgArrays", "_health", "_dmgArrays", "_thisHitIndex"];
		_fingerprint = _x select 0;
		_fingerprintValues = _x select 1;
		_health = _x select 2;
		_dmgArrays = _x select 3;
		_thisHitIndex = _forEachIndex;

		// _outputString = _outputString + format["Hit #%1, with player health at %2\n", _thisHitIndex + 1, _health];

		_tree tvAdd[[], format["Target Hit #%1  (Resulting health: %2 / 100)", _thisHitIndex + 1, ceil ((1-_health) * 100)] ];

		{
			// _outputString = _outputString + format["   %1 = %2\n", _hitPartOrderedTitles select _forEachIndex, _x];
			_tree tvAdd[ [_thisHitIndex], format["   Damage to %1: %2", _hitPartOrderedTitles select _forEachIndex, _x] ];
		} foreach _fingerprintValues;

		// _outputString = _outputString +  "		That number was based on Damage Propagation affecting these parts:\n";

		_tree tvAdd[ [_thisHitIndex], "Damage Propagation data, which resulted in the total damage applied for this Hit -"];

		{
			_hitPartIndex = _x select 0;
			_damageToSelection = _x select 1;
			_damageBeforeEvent = _x select 2;
			_hitPartLookupTitleIndex = _hitPartIndex;
			if (_hitPartLookupTitleIndex < 0) then 
			{
				_hitPartLookupTitleIndex = (count _hitPartOrderedTitles) - 1;
			};
			// _outputString = _outputString + format["			%1 took %2 damage\n", _hitPartOrderedTitles select _hitPartLookupTitleIndex, _damageToSelection];
			_tree tvAdd[ [_thisHitIndex, count _fingerprintValues], format["%1 took %2 damage", _hitPartOrderedTitles select _hitPartLookupTitleIndex, _damageToSelection] ];
		} foreach _dmgArrays;
	} foreach _targetHistoryArray;

	// if !(isMultiplayer) then 
	// {
	// 	copyToClipboard _outputString;
	// 	systemChat "==> Damage information has been copied to Clipboard.";
	// };
};