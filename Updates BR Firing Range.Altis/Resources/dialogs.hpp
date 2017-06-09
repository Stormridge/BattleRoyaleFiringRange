/*
	
	Description: Dialog definition
	Created By: Stormridge
	
	To view in GUI editor, import confi via:
			missionConfigFIle >> "BRFR_Dialog_CreateSoldier"
			missionConfigFIle >> "BRFR_Dialog_PlayerLoadout"

*/
#include "..\Includes\defines.hpp"

class BRFR_Dialog_CreateSoldier
{    
	idd = IDD_BRFR_CreateSoldier;
	class controlsBackground
	{
		class mainframe
		{
			idc = 3256;
			type = CT_STATIC;
			text = "";
			style = ST_LEFT;
			moving=0;
			colorText[] = {0,0,0,0};
			font = GUI_FONT_NORMAL;
			sizeEx = GUI_GRID_CENTER_H;
			x = 0 * GUI_GRID_W + GUI_GRID_X; // - (.5*GUI_GRID_W);
			y = 0 * GUI_GRID_H + GUI_GRID_Y;// - (.5 * GUI_GRID_H);
			w = 12 * GUI_GRID_W + (1*GUI_GRID_W);
			h = 15 * GUI_GRID_H;			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,0,.6};
		};
	};
	class controls
	{
		// START
		class BRFR_Combo_Uniform : RscCombo
		{
			idc = IDC_BRFR_Combo_Uniform;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 2 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Combo_Vest: RscCombo
		{
			idc = IDC_BRFR_Combo_Vest;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Combo_Headgear: RscCombo
		{
			idc = IDC_BRFR_Combo_Headgear;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Combo_Backpack: RscCombo
		{
			idc = IDC_BRFR_Combo_Backpack;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Combo_Distance: RscCombo
		{
			idc = IDC_BRFR_Combo_Distance;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Text_Distance: RscStructuredText
		{
			idc = IDC_BRFR_Text_Distance;
			text = "Distance"; //--- ToDo: Localize;
			x = 7.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 5.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {-1,-1,-1,0};
		};
		class BRFR_Text_CreateSoldier: RscStructuredText
		{
			idc = IDC_BRFR_Text_CreateSoldier;
			text = "Create Soldier"; //--- ToDo: Localize;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,.4,.4};
		};
		class BRFR_Button_Create: RscButton
		{
			idc = IDC_BRFR_Button_Create;
			text = "Create"; //--- ToDo: Localize;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			//action="closeDialog 0;";
		};
		class BRFR_Button_Cancel: RscButton
		{
			idc = IDC_BRFR_Button_Cancel;
			action = "closeDialog 0;";
			text = "Cancel"; //--- ToDo: Localize;
			x = 7.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_Checkbox_DetailedReport: RscCheckBox
		{
			type=77;
			idc = IDC_BRFR_Button_DetailedReport;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 12.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.5 * GUI_GRID_W;
			h = 1.5 * .75 * GUI_GRID_H;
			checked=0;
			color[] = {1,1,1,0.7}; // Texture color
			colorFocused[] = {1,1,1,1}; // Focused texture color
			colorHover[] = {1,1,1,1}; // Mouse over texture color
			colorPressed[] = {1,1,1,1}; // Mouse pressed texture color
			colorDisabled[] = {1,1,1,0.2}; // Disabled texture color

			//Background colors
			colorBackground[] = {.1,.1,.1,.6}; // Fill color
			colorBackgroundFocused[] = {0,0,0,.5}; // Focused fill color
			colorBackgroundHover[] = {0,0,0,.5}; // Mouse hover fill color
			colorBackgroundPressed[] = {0,0,0,.5}; // Mouse pressed fill color
			colorBackgroundDisabled[] = {0,0,0,0}; // Disabled fill color

		};
		class BRFR_Text_DetailedReport: RscStructuredText
		{
			idc = IDC_BRFR_Text_DetailedReport;
			text = "<t size='.8' font='PuristaMedium'>Produce detailed damage reports?</t>"; //--- ToDo: Localize;
			x = 2.2 * GUI_GRID_W + GUI_GRID_X;
			y = 12.25 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 2.25 * GUI_GRID_H;
			colorBackground[] = {.1,.1,.1,.4};
		};
	// END
	};	
};

class BRFR_Dialog_PlayerLoadout
{
	idd = IDD_BRFR_PlayerLoadout;
	
	class controlsBackground
	{
		class mainframe
		{
			idc = 3255;
			type = CT_STATIC;
			text = "";
			style = ST_LEFT;
			moving=0;
			colorText[] = {0,0,0,0};
			font = GUI_FONT_NORMAL;
			sizeEx = GUI_GRID_CENTER_H;
			x = 0 * GUI_GRID_W + GUI_GRID_X - (.5*GUI_GRID_W);
			y = 0 * GUI_GRID_H + GUI_GRID_Y - (.5 * GUI_GRID_H);
			w = 12 * GUI_GRID_W + (1*GUI_GRID_W);
			h = 17 * GUI_GRID_H;			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,0,.4};
		};
	};

	class controls
	{
		// START
		class BRFR_PlayerLoadout_Text: RscStructuredText
		{
			idc = IDC_BRFR_PlayerLoadout_Text;
			text = "Change Loadout"; //--- ToDo: Localize;    ///////// FINISH MENU
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,.4,.4};
		};
		class BRFR_PlayerLoadout_Combo_Uniform : RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Uniform;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Vest: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Vest;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Headgear: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Headgear;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Backpack: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Backpack;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 6 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		// TXT
		class BRFR_PlayerLoadout_Text_Weapon: RscStructuredText
		{
			idc = IDC_BRFR_PlayerLoadout_Text_Weapon;

			text = "Weapon"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0.4,0.4};
		};
		class BRFR_PlayerLoadout_Combo_Weapon: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Weapon;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 9 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Optic: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Optic;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Ammo: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Ammo;

			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Combo_Suppressor: RscCombo
		{
			idc = IDC_BRFR_PlayerLoadout_Combo_Suppressor;

			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		////// Buttons

		class BRFR_PlayerLoadout_Button_Create: RscButton
		{
			idc = IDC_BRFR_PlayerLoadout_Button_Create;
			text = "Create"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 15 * GUI_GRID_H + GUI_GRID_Y;
			w = 6 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			//action="closeDialog 0;";
		};
		class BRFR_PlayerLoadout_Button_Cancel: RscButton
		{
			idc = IDC_BRFR_PlayerLoadout_Button_Cancel;
			action = "closeDialog 0;";
			text = "Cancel"; //--- ToDo: Localize;
			x = 7 * GUI_GRID_W + GUI_GRID_X;
			y = 15 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class BRFR_PlayerLoadout_Picture_Weapon: RscPicture
		{
			idc = IDC_BRFR_PlayerLoadout_Picture_Weapon;
			text = "";
			x = 14 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
			w = 21 * GUI_GRID_W;
			h = 14 * GUI_GRID_H;
		};
	// END
	};	
};

class BRFR_CreateSolider_DamageReport
{
	idd = IDD_CreateSolider_DamageReport;
	onLoad = "uiNamespace setVariable ['BRFR_CreateSolider_DamageReport', _this select 0]";
	onUnload = "uiNamespace setVariable ['BRFR_CreateSolider_DamageReport', displayNull]; missionNamespace setVariable['BRFR_HINT_PAUSE',false];";
	class controlsBackground
	{
		class mainframe: RscFrame
		{
			idc = IDC_BRFR_CreateSolider_DamageReport_Frame1;
			//text = "After-Action Damage Report";
			style = ST_LEFT; // + ST_UP;
			x = "safeZoneX + 160 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 60 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (160*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "safeZoneH - (120*2) * (safeZoneH / (getResolution select 1))";
			sizeEx = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {1,1,1,1};
			font = GUI_FONT_THIN;
		};
	};
	class controls
	{
		class CreateSolider_DamageReport_Instructions : RscStructuredText
		{
			idc = IDC_BRFR_CreateSolider_DamageReport_Instructions;
			text = "<t size='1.3'>AFTER ACTION DAMAGE REPORT</t><br /><t font='PuristaMedium' size='0.8'>The damage report is ordered by Hit events, and resulting damage to body parts. (0=healthy, 1=fully damaged)    Hit Escape to close.</t>";
			//Expand each 'Hit Event' to view each hit's details.<br />
			x = "safeZoneX + 180 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 80 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (180*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "90 * (safeZoneH / (getResolution select 1))";
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {1,1,1,1};
			font = GUI_FONT_NORMAL;
			sizeEx=1 * GUI_GRID_H;
		};
		class BRFR_CreateSolider_DamageReport_TreeView
		{
			access = 3; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = IDC_CreateSolider_DamageReport_TreeView; // Control identification (without it, the control won't be displayed)
			type = CT_TREE; // Type
			style = ST_LEFT; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = "safeZoneX + 180 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 180 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (180*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "safeZoneH - (185*2) * (safeZoneH / (getResolution select 1))";

			colorBorder[] = {0,0,0,1}; // Frame color

			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorSelect[] = {1,0.5,0,1}; // Selected item fill color (when multiselectEnabled is 0)
			colorMarked[] = {1,0.5,0,0.5}; // Marked item fill color (when multiselectEnabled is 1)
			colorMarkedSelected[] = {1,0.5,0,1}; // Selected item fill color (when multiselectEnabled is 1)

			sizeEx = 1 * GUI_GRID_H; // Text size
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 1; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text color
			colorSelectText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 0)
			colorMarkedText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 1)

			tooltip = "CT_TREE"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			multiselectEnabled = 1; // Allow selecting multiple items while holding Ctrl or Shift
			expandOnDoubleclick = 1; // Expand/collapse item upon double-click
			hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa"; // Expand icon
			expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa"; // Collapse icon
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it
			class ScrollBar
			{
				width = 1; // Unknown?
				height = 1; // Unknown?
				scrollSpeed = 0.01; // Unknown?

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
			colorDisabled[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
			colorArrow[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
		};
		// class BRFR_CreateSolider_DamageReport_Button_Close : RscButton
		// {
		// 	idc = IDC_CreateSolider_DamageReport_Button_Close;
		// 	action = "BRFR_HINT_PAUSE=false;closeDialog 0;";
		// 	text = "CLOSE"; //--- ToDo: Localize;
		// 	x = "safeZoneX + 180 * (safeZoneWAbs / (getResolution select 0))";
		// 	y = "safeZoneY + safeZoneH  - (210 * (safeZoneH / (getResolution select 1)))";
		// 	w = 5 * GUI_GRID_W;
		// 	h = 1 * GUI_GRID_H;
		// };
	};
};

class BRFR_Oracle_ArmorReport
{
	idd = IDD_BRFR_Orace_ArmorReport;
	onLoad = "uiNamespace setVariable ['BRFR_Oracle_ArmorReport', _this select 0]";
	onUnload = "uiNamespace setVariable ['BRFR_Oracle_ArmorReport', displayNull]; missionNamespace setVariable['BRFR_HINT_PAUSE',false];";
	class controlsBackground
	{
		class mainframe: RscFrame
		{
			idc = IDC_BRFR_Oracle_ArmorReport_Frame1;
			style = ST_LEFT; // + ST_UP;
			x = "safeZoneX + 160 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 60 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (160*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "safeZoneH - (120*2) * (safeZoneH / (getResolution select 1))";
			sizeEx = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {1,1,1,1};
			font = GUI_FONT_THIN;
		};
	};
	class controls
	{
		class Instructions : RscStructuredText
		{
			idc = IDC_BRFR_Oracle_ArmorReport_Instructions;
			text = "<t size='1.3'>ARMOR REPORT</t><br /><t font='PuristaMedium' size='0.8'>by the Oracle.   (Press Esc. to close)</t>";
			x = "safeZoneX + 180 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 80 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (180*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "90 * (safeZoneH / (getResolution select 1))";
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {1,1,1,1};
			font = GUI_FONT_NORMAL;
			sizeEx=1 * GUI_GRID_H;
		};
		class OracleMessage : RscStructuredText
		{
			idc = IDC_BRFR_Oracle_ArmorReport_Message; // Control identification (without it, the control won't be displayed)
			x = "safeZoneX + 180 * (safeZoneWAbs / (getResolution select 0))";
			y = "safeZoneY + 180 * (safeZoneH / (getResolution select 1))";
			w = "safeZoneWAbs - (180*2) * (safeZoneWAbs / (getResolution select 0))";
			h = "safeZoneH - (185*2) * (safeZoneH / (getResolution select 1))";
			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorText[] = {1,1,1,1};
			font = GUI_FONT_NORMAL;
			sizeEx=1 * GUI_GRID_H;
		};
	};
};

class BRFR_Dialog_CreateVehicle
{
	idd = IDD_BRFR_CreateVehicle;
	
	class controlsBackground
	{
		class mainframe
		{
			idc = 3255;
			type = CT_STATIC;
			text = "";
			style = ST_LEFT;
			moving=0;
			colorText[] = {0,0,0,0};
			font = GUI_FONT_NORMAL;
			sizeEx = GUI_GRID_CENTER_H;
			x = 0 * GUI_GRID_W + GUI_GRID_X - (.5*GUI_GRID_W);
			y = 0 * GUI_GRID_H + GUI_GRID_Y - (.5 * GUI_GRID_H);
			w = 12 * GUI_GRID_W + (1*GUI_GRID_W);
			h = 5 * GUI_GRID_H;			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,0,.4};
		};
	};

	class controls
	{
		// START
		class BRFR_CreateVehicle_Text: RscStructuredText
		{
			idc = IDC_BRFR_CreateVehicle_Text;
			text = "Create Vehicle"; //--- ToDo: Localize;    ///////// FINISH MENU
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;			//colorBackground[] = {-1,-1,-1,.7};
			colorBackground[] = {0,0,.4,.4};
		};
		class BRFR_CreateVehicle_Combo_Vehicle : RscCombo
		{
			idc = IDC_BRFR_CreateVehicle_Combo_Vehicle;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 12 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};

		////// Buttons
		class BRFR_CreateVehicle_Button_Create: RscButton
		{
			idc = IDC_BRFR_CreateVehicle_Button_Create;
			text = "Create"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 6 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			//action="closeDialog 0;";
		};
		class BRFR_CreateVehicle_Button_Cancel: RscButton
		{
			idc = IDC_BRFR_CreateVehicle_Button_Cancel;
			action = "closeDialog 0;";
			text = "Cancel"; //--- ToDo: Localize;
			x = 7 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
	// END
	};	
};


/////////SPECTATOR START//////////////
class RscDisplaySTRMSpectator
{
	idd = 32961;
	scriptName = "RscDisplaySTRMSpectator";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscDisplaySTRMSpectator"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplaySTRMSpectator"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
};





/////////////////////////////////////