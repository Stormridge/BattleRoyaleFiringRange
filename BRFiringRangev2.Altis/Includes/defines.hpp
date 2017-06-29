/*

	Description: Defines
	Created By: Stormridge
	
*/
#define IDD_BRFR_CreateSoldier					9000
#define IDD_BRFR_PlayerLoadout					9001
#define IDD_CreateSolider_DamageReport			9002
#define IDD_BRFR_Orace_ArmorReport				9003
#define IDD_BRFR_CreateVehicle					9004


#define IDC_BRFR_Combo_Uniform 				2100
#define IDC_BRFR_Combo_Vest 					2101
#define IDC_BRFR_Combo_Headgear 			2102
#define IDC_BRFR_Combo_Backpack 			2103
#define IDC_BRFR_Combo_Distance 			2104
#define IDC_BRFR_Button_Create 				1600
#define IDC_BRFR_Button_Cancel					1601
#define IDC_BRFR_Text_CreateSoldier			1100
#define IDC_BRFR_Text_Distance					1101


#define IDC_BRFR_PlayerLoadout_Text									2200
#define IDC_BRFR_PlayerLoadout_Combo_Uniform 				2201
#define IDC_BRFR_PlayerLoadout_Combo_Vest 					2202
#define IDC_BRFR_PlayerLoadout_Combo_Headgear 			2203
#define IDC_BRFR_PlayerLoadout_Combo_Backpack 			2204
#define IDC_BRFR_PlayerLoadout_Combo_Weapon				2205
#define IDC_BRFR_PlayerLoadout_Combo_Optic					2206
#define IDC_BRFR_PlayerLoadout_Button_Create 				2207
#define IDC_BRFR_PlayerLoadout_Button_Cancel					2208
#define IDC_BRFR_PlayerLoadout_Text_Weapon					2209
#define IDC_BRFR_PlayerLoadout_Combo_Ammo				2210
#define IDC_BRFR_PlayerLoadout_Combo_Suppressor			2211
#define IDC_BRFR_PlayerLoadout_Picture_Weapon				2212
#define IDC_BRFR_Button_DetailedReport						2213
#define IDC_BRFR_Text_DetailedReport						2214
#define IDC_CreateSolider_DamageReport_Button_Close			2215
#define IDC_CreateSolider_DamageReport_TreeView				2216
#define IDC_BRFR_CreateSolider_DamageReport_Frame1			2217
#define IDC_BRFR_CreateSolider_DamageReport_Instructions	2218
#define IDC_BRFR_Oracle_ArmorReport_Frame1					2219
#define IDC_BRFR_Oracle_ArmorReport_Instructions			2220
#define IDC_BRFR_Oracle_ArmorReport_Message					2221

#define IDC_BRFR_CreateVehicle_Button_Create 				2222
#define IDC_BRFR_CreateVehicle_Combo_Vehicle				2223
#define IDC_BRFR_CreateVehicle_Button_Cancel				2224
#define IDC_BRFR_CreateVehicle_Text							2225

///////////////////////////////////////////////////////////////////////////
/// GUI
///////////////////////////////////////////////////////////////////////////
#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)

// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102
#define CT_CHECKBOX         77

///////////////////////////////////////////////////////////////////////////
/// Styles
///////////////////////////////////////////////////////////////////////////
// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar 
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4

#define GUI_FONT_NORMAL			PuristaMedium
#define GUI_FONT_BOLD			PuristaSemibold
#define GUI_FONT_THIN			PuristaLight
#define GUI_FONT_MONO			EtelkaMonospacePro
#define GUI_FONT_NARROW			EtelkaNarrowMediumPro
#define GUI_FONT_CODE			LucidaConsoleB
#define GUI_FONT_SYSTEM			TahomaB
