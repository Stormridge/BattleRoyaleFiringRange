// if !(isNil "brTestExpEH") then
// {
// 	player removeEventHandler ["Explosion", brTestExpEH];
// };
// if !(isNil "brTestMPEH") then
// {
// 	player removeMPEventHandler ["MPKilled", brTestMPEH];
// };
// if !(isNil "brTestHitEH") then
// {
// 	player removeMPEventHandler ["HandleDamage", brTestHitEH];
// };


// BR_Test_onExplosion =
// {
// 	params ["_veh", "_dmgValue"];

// 	// diag_log format["[ON EXPLOSION] V:%1 	DMG:%2", _veh, _dmgValue];
// };

// BR_Test_onMPKilled = 
// {
// 	params ["_unit", "_killer", "_instigator"];

// 	// diag_log format["[ON MP KILLED] Unit:%1 	Killer:%2 	Instigator:%3", _unit, _killer, _instigator];
// };

// BR_Test_onHit =
// {
// 	params [
// 	    "_unit",
// 	    "_selection",
// 	    "_engineProposedDamageValue",
// 	    "_source", 
// 	    "_projectile",
// 	    "_hitPartIndex"
// 	];
// 	// diag_log format["[ON HandleDamage] Unit:%1 	_selection:%2 	_source:%3 _projectile:%4 _hitPartIndex:%5", _unit, _selection, _source, _projectile, _hitPartIndex];
// };

// brTestExpEH = player addEventHandler ["Explosion", {_this call BR_Test_onExplosion;}];

// brTestMPEH = player addMPEventHandler ["MPKilled", {_this call BR_Test_onMPKilled}]; 

// brTestHitEH = player addEventHandler ["HandleDamage", {_this call BR_Test_onHit;}];