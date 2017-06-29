/*

	Description: AI Setup and Events, for moving targets.  Called by mission.sqm Inits, per unit
	Created By: Stormridge
	
*/

if (isServer) then {

	_unit = _this select 0;

	[_unit] execVM "Functions\Spawn\changeAILoadout.sqf";
	_unit disableAI "TARGET";
	_unit allowFleeing 0;

	_unit addEventHandler [
		"Killed",
		{
			_ai = _this select 0;
			_type = (typeOf _ai);
			_grp = group _ai;
			_pos = getPos _ai;
			hideBody _ai;
			
			[_pos, _grp, _ai, _this, _type] spawn {
				_pos = _this select 0;
				_grp = _this select 1;
				_ai = _this select 2;
				this = _this select 3;
				_type = _this select 4;
				sleep 5.0;
				//_type createUnit [_pos, _grp, "this disableCollisionWith _ai; this setVariable ['BIS_enableRandomization', false]; _grp setBehaviour 'CARELESS'; this allowFleeing 0;this disableAI 'TARGET'; nul=[this] execVM 'Functions\Spawn\AISpawnInit_Moving.sqf';"];
				_newUnit = _grp createUnit [_type, _pos, [], 0, "NONE"];
				_newUnit disableCollisionWith _ai; 
				_newUnit setVariable ['BIS_enableRandomization', false];
				_grp setBehaviour 'CARELESS';
				_newUnit allowFleeing 0;
				_newUnit  disableAI 'TARGET'; 
				[_newUnit] execVM 'Functions\Spawn\AISpawnInit_Moving.sqf';

			};	
		}
	];
	
	_unit addEventHandler ['HandleDamage', {_this call BR_DamageHandler}];

	// Hit parts do not work in multiplayer, here....
	_unit addEventHandler ['Killed', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_KilledEvent.sqf'}];
	_unit addEventHandler ['HitPart', {[_this] execVM 'Functions\CreateSoldier\CreateSoldier_HitPartEvent.sqf'}];

};