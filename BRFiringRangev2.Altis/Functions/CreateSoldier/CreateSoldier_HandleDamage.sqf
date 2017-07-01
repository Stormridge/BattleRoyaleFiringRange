/*
	
	Description: UI to display target information
	By: Stormridge
	
*/
private ["_unit", "_selection", "_damageToSelection", "_source", "_projectile","_hitPartIndex", "_curDamage", "_sourceName", "_tickFingerprintVariance", "_eventTick"];
_eventTick = diag_tickTime;

_unit = _this select 0; 				// me
_selection = _this select 1; 			// could be "" or ?   convert to body
_damageToSelection = _this select 2; 	// #
_source	= _this select 3; 				// object
_projectile = _this select 4; 			// Round type string
_hitPartIndex = _this select 5;			// Can be -1

_curDamage=0;
_tickFingerprintVariance = .2;

///////// HISTORY //////////
private _targetHistoryArray = _unit getVariable["CreateSoldierDamageHistory",[]];
if (count _targetHistoryArray < 1) then 
{
	_targetHistoryArray = [];
	_unit setVariable["CreateSoldierDamageHistory", _targetHistoryArray];
};
///////// SOURCE //////////
// Source can be null if you jump of a rock, for instance.
// Source can also be yourself, from jumping off rocks
_sourceName = "(unknown)";
if !(isNull _source) then 
{
	if (isPlayer _source) then 
	{
		_sourceName = name _source;
	}
	else
	{
		_sourceName = _source;
	};
};
///////// PROJECTILE //////////
///////// LOG //////////
// diag_log format ["Stats about Damage being Applied:  Selection=%1, DmgToSelection=%2, Src=%3, Proj=%4, HitParIndex=%5", 
// 	_selection, _damageToSelection, _sourceName, _projectile, _hitPartIndex];
_allHitPtsDmgArray = getAllHitPointsDamage _unit;
///////// LOG //////////
// {
// 	diag_log format ["		getAllHitPointsDamage: %1", _x];
// } foreach _allHitPtsDmgArray;
///////// FINGERPRINT //////////
_fingerprintMatchIndex = -1;
_damageFingerprint = str (_allHitPtsDmgArray select 2);
//diag_log format ["		_damageFingerprint: %1 and tick=%2", _damageFingerprint, diag_tickTime];
{
	if ((_x select 0) isEqualTo _damageFingerprint && 
		abs((_x select 4) - _eventTick) <= _tickFingerprintVariance) exitWith {_fingerprintMatchIndex=_forEachIndex};
} foreach _targetHistoryArray;
_thisHandleDamagePropagationArray=[];
if (_fingerprintMatchIndex < 0) then 
{
	_fingerprintMatchIndex = _targetHistoryArray pushback [_damageFingerprint,(_allHitPtsDmgArray select 2),damage _unit,[], _eventTick];	// fingerprint string, fingerprint actual values, arrays of events, timestamp
};
_thisHandleDamagePropagationArray = (_targetHistoryArray select _fingerprintMatchIndex) select 3;
0=_thisHandleDamagePropagationArray pushBack [_hitPartIndex, _damageToSelection];
true