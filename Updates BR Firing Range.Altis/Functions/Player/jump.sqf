// Script by @majarkin 
// for PLAYERUNKNOWN's Battle Royale
// fixed by @RyanCheeky

if (isNull player) exitwith {};

"BR_Animation" addPublicVariableEventHandler {
	(_this select 1) spawn fn_Animation;
};

fn_Animation =
{    
    private ["_unit","_anim"];
    _unit = _this select 0;
    _anim = _this select 1;
    _unit switchMove _anim;
};

br_dokeyDown = {
    private ["_r","_height","_vel","_dir","_speed"];
    _r = false;    
    if ((inputAction "getOver" > 0) && (((inputAction "Turbo" > 0)) || ((inputAction "MoveFastForward" > 0)) || ((speed player > 15)))) then {
        _r = true;        
        if  (player == vehicle player && player getvariable ["jump",true] && isTouchingGround player && stance player == "STAND") then  {
            
            player setvariable ["jump",false];
            _height = 3.5-((load player));            
            _vel = velocity player;
            _dir = direction player;
            _speed = 0.4;            
            player setVelocity [(_vel select 0)+(sin _dir*_speed),(_vel select 1)+(cos _dir*_speed),_height];    
			BR_Animation = [player,"AovrPercMrunSrasWrflDf"];
			_lastAnim = animationState player;
			publicVariable "BR_Animation";
			player switchMove "AovrPercMrunSrasWrflDf";
            _lastAnim spawn {uiSleep 0.73;player switchMove _this;player setvariable ["jump",true];};
        };        
    };
};

waituntil {!(IsNull (findDisplay 46))};
(FindDisplay 46) displayAddEventHandler ["keydown","nul = player call br_dokeyDown"];
