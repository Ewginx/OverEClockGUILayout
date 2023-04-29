// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: OverEClocks

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
// Settings Screen Objects
lv_obj_t *lastScreen = NULL;
lv_obj_t *ui_SettingsScreen;
lv_obj_t *ui_SettingsPanel;
lv_obj_t *ui_DarkmodeLabel;
lv_obj_t *ui_DarkmodeSwitch;
lv_obj_t *ui_SettingsCityEdit;
lv_obj_t *ui_SettingsCityLabel;
lv_obj_t *ui_SettingsSSIDLabel;
lv_obj_t *ui_SettingsSSIDEdit;
lv_obj_t *ui_SettingsPasswordLabel;
lv_obj_t *ui_SettingsPasswordEdit;
lv_obj_t *ui_SettingsKeyboard;
lv_obj_t *ui_SettingsHomeBtn;
lv_obj_t *ui_SettingsHomeBtnLabel;
lv_obj_t * ui_SettingsAPLabel;
lv_obj_t * ui_SettingsIPLabel;
// Settings Screen Events
void ui_event_SettingsPasswordEdit(lv_event_t *e);
void ui_event_SettingsSSIDEdit(lv_event_t *e);
void ui_event_SettingsCityEdit(lv_event_t *e);
void ui_event_SettingsHomeBtn(lv_event_t *e);
void ui_event_SettingsKeyboard(lv_event_t *e);

// Alarm Screen Objects
lv_obj_t *ui_AlarmScreen;
lv_obj_t *ui_AlarmPanel;
lv_obj_t *ui_Label1;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Label3;
lv_obj_t *ui_Switch1;
lv_obj_t *ui_Switch2;
lv_obj_t *ui_Switch3;
lv_obj_t *ui_Button6;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Button1;
lv_obj_t *ui_Label7;
lv_obj_t *ui_Button4;
lv_obj_t *ui_Label8;
lv_obj_t *ui_AlarmModalPanel;
lv_obj_t *ui_AlarmHourRoller;
lv_obj_t *ui_AlarmMinuteRoller;
lv_obj_t *ui_AlarmModalCancelButton;
lv_obj_t *ui_Label15;
lv_obj_t *ui_AlarmModalOkButton;
lv_obj_t *ui_Label16;
lv_obj_t * ui_AlarmSettingsBtn;
lv_obj_t * ui_AlarmSettingsBtnLabel;
// Alarm Screen Events
void ui_event_AlarmModalOkButton(lv_event_t *e);
void ui_event_AlarmModalCancelButton(lv_event_t *e);
void ui_event_AlarmScreen(lv_event_t *e);
void ui_event_Button4(lv_event_t *e);
void ui_event_Button1(lv_event_t *e);
void ui_event_Button6(lv_event_t *e);

// Analog Clock Objects
lv_obj_t *ui_AnalogClockScreen;
lv_obj_t *ui_AnalogPanel;
lv_obj_t *ui_AnalogSettingsBtn;
lv_obj_t *ui_AnalogMeter;
lv_obj_t *ui_AnalogSettingsLabel;

// Digital Clock Objects
lv_obj_t *ui_DigitalClockScreen;
lv_obj_t *ui_DigitalClockPanel;
lv_obj_t *ui_DigitalClockLabel;
lv_obj_t *ui_DigitalClockBatteryLbl;
lv_obj_t *ui_DigitalClockSecondLabel;
lv_obj_t *ui_DigitalClockDateLabel;
lv_obj_t *ui_DigitalClockSettingsBtn;
lv_obj_t *ui_DigitalClockSettingsBtnLabel;
// Digital Clock Events
void ui_event_DigitalClockScreen(lv_event_t *e);
void ui_event_DigitalClockSettingsBtn(lv_event_t *e);

// Weather Objects
lv_obj_t *ui_Weather;
lv_obj_t *ui_WeatherPanel;
lv_obj_t *ui_WeatherImage;
lv_obj_t *ui_WeatherCity;
lv_obj_t *ui_WeatherTemperatureLbl;
lv_obj_t *ui_WeatherBriefingLbl;
lv_obj_t *ui_WeatherMiscLabel;
lv_obj_t *ui_WeatherTimesLbl;
lv_obj_t *ui_WeatherThirdTempLbl;
lv_obj_t *ui_WeatherSecondTempLbl;
lv_obj_t *ui_WeatherFourthTempLbl;
lv_obj_t *ui_WeatherFirstTempLbl;
lv_obj_t *ui_Label13;
// Weather Events
void ui_event_Weather(lv_event_t *e);

lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SettingsKeyboard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CANCEL || event_code == LV_EVENT_READY)
    {
        _ui_flag_modify(ui_SettingsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_basic_set_property(ui_SettingsPanel, _UI_BASIC_PROPERTY_HEIGHT, 320);
    }
}
void ui_event_SettingsCityEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        _ui_keyboard_set_target(ui_SettingsKeyboard, ui_SettingsCityEdit);
        _ui_flag_modify(ui_SettingsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_basic_set_property(ui_SettingsPanel, _UI_BASIC_PROPERTY_HEIGHT, 160);
    }
    if (event_code == LV_EVENT_READY)
    {
        lv_textarea_set_text(ui_SettingsCityEdit, "ABOBA");
    }
}
void ui_event_SettingsSSIDEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        _ui_keyboard_set_target(ui_SettingsKeyboard, ui_SettingsSSIDEdit);
        _ui_flag_modify(ui_SettingsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_basic_set_property(ui_SettingsPanel, _UI_BASIC_PROPERTY_HEIGHT, 160);
    }
    if (event_code == LV_EVENT_READY)
    {
        lv_textarea_set_text(ui_SettingsSSIDEdit, "ABOBA");
    }
}
void ui_event_SettingsPasswordEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        _ui_keyboard_set_target(ui_SettingsKeyboard, ui_SettingsPasswordEdit);
        _ui_flag_modify(ui_SettingsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_basic_set_property(ui_SettingsPanel, _UI_BASIC_PROPERTY_HEIGHT, lv_pct(50));
    }
    if (event_code == LV_EVENT_READY)
    {
        lv_textarea_set_text(ui_SettingsPasswordEdit, "ABOBA");
    }
}

// Dark mode event
void ui_event_DarkmodeSwitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        if (lv_obj_has_state(target, LV_STATE_CHECKED))
        {
            lv_disp_t *dispp = lv_disp_get_default();
            lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_CYAN), lv_palette_main(LV_PALETTE_NONE),
                                                      false, LV_FONT_DEFAULT);
            lv_disp_set_theme(dispp, theme);
            lv_obj_set_style_text_color(ui_DigitalClockSettingsBtnLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AnalogSettingsLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_DigitalClockSettingsBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_AnalogSettingsBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else
        {
            lv_disp_t *dispp = lv_disp_get_default();
            lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_CYAN), lv_palette_main(LV_PALETTE_NONE),
                                                      true, LV_FONT_DEFAULT);
            lv_disp_set_theme(dispp, theme);
            lv_obj_set_style_text_color(ui_DigitalClockSettingsBtnLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AnalogSettingsLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void ui_event_Button6(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Button1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}

void ui_event_Button4(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_AlarmModalCancelButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_AlarmModalOkButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_AlarmSettingsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lastScreen = lv_event_get_user_data(e);
        _ui_screen_change(ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
// Screen change on GESTURES
void ui_event_AlarmScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        _ui_screen_change(ui_AnalogClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_DigitalClockScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        _ui_screen_change(ui_Weather, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
        
    }
    else if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        _ui_screen_change(ui_AnalogClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void ui_event_Weather(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        _ui_screen_change(ui_DigitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void ui_event_AnalogClockScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        _ui_screen_change(ui_DigitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    else if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        _ui_screen_change(ui_AlarmScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

// Screen change on Button
void ui_event_DigitalClockSettingsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lastScreen = lv_event_get_user_data(e);
        _ui_screen_change(ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_AnalogSettingsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lastScreen = lv_event_get_user_data(e);
        _ui_screen_change(ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SettingsHomeBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(lastScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

///////////////////// SCREENS INIT////////////////////
// SETTING SCREEN INIT
void ui_Settings_screen_init(void)
{
    ui_SettingsScreen = lv_obj_create(NULL);
    lv_obj_add_flag(ui_SettingsScreen, LV_OBJ_FLAG_IGNORE_LAYOUT); /// Flags
    lv_obj_set_scroll_dir(ui_SettingsScreen, LV_DIR_VER);

    ui_SettingsPanel = lv_obj_create(ui_SettingsScreen);
    lv_obj_set_size(ui_SettingsPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_style_bg_color(ui_SettingsPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DarkmodeLabel = lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_DarkmodeLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_DarkmodeLabel, 35,15);
    lv_obj_set_align(ui_DarkmodeLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_DarkmodeLabel, "Dark Mode");
    lv_obj_set_style_text_font(ui_DarkmodeLabel, &lv_font_montserrat_18, LV_PART_MAIN);

    ui_DarkmodeSwitch = lv_switch_create(ui_SettingsPanel);
    lv_obj_set_size(ui_DarkmodeSwitch, 50, 25);
    lv_obj_set_pos(ui_DarkmodeSwitch, 175, 15);
    lv_obj_set_align(ui_DarkmodeSwitch, LV_ALIGN_TOP_LEFT);

    ui_SettingsCityEdit = lv_textarea_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsCityEdit, 250, LV_SIZE_CONTENT); /// 33
    lv_obj_set_pos(ui_SettingsCityEdit, 180, 65);
    lv_obj_set_align(ui_SettingsCityEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(ui_SettingsCityEdit, 100);
    lv_textarea_set_placeholder_text(ui_SettingsCityEdit, "City, country code ISO-81118");
    lv_textarea_set_one_line(ui_SettingsCityEdit, true);

    ui_SettingsCityLabel = lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsCityLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsCityLabel, 20, 65);
    lv_obj_set_align(ui_SettingsCityLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsCityLabel, "City and\ncountry code");
    lv_obj_set_style_text_font(ui_SettingsCityLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SettingsCityLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsSSIDLabel = lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsSSIDLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsSSIDLabel, 40, 135);
    lv_obj_set_align(ui_SettingsSSIDLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsSSIDLabel, "WiFi SSID");
    lv_obj_set_style_text_font(ui_SettingsSSIDLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsSSIDEdit = lv_textarea_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsSSIDEdit, 250, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_SettingsSSIDEdit, 180, 125);
    lv_obj_set_align(ui_SettingsSSIDEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(ui_SettingsSSIDEdit, 50);
    lv_textarea_set_placeholder_text(ui_SettingsSSIDEdit, "WiFi SSID");
    lv_textarea_set_one_line(ui_SettingsSSIDEdit, true);

    ui_SettingsPasswordLabel = lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsPasswordLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsPasswordLabel, 20, 195);
    lv_obj_set_align(ui_SettingsPasswordLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsPasswordLabel, "WiFi Password");
    lv_obj_set_style_text_font(ui_SettingsPasswordLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsPasswordEdit = lv_textarea_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsPasswordEdit, 250, LV_SIZE_CONTENT); /// 33
    lv_obj_set_pos(ui_SettingsPasswordEdit, 180, 185);
    lv_obj_set_align(ui_SettingsPasswordEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(ui_SettingsPasswordEdit, 100);
    lv_textarea_set_placeholder_text(ui_SettingsPasswordEdit, "WiFi Password");
    lv_textarea_set_one_line(ui_SettingsPasswordEdit, true);
    lv_textarea_set_password_mode(ui_SettingsPasswordEdit, true);

    ui_SettingsAPLabel = lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsAPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsAPLabel, 80, 250);
    lv_obj_set_align(ui_SettingsAPLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsAPLabel, "AccessPoint IP:");
    lv_obj_set_style_text_font(ui_SettingsAPLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsIPLabel= lv_label_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsIPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsIPLabel, 230, 250);
    lv_obj_set_align(ui_SettingsIPLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsIPLabel, "192.120.12.99");
    lv_obj_set_style_text_font(ui_SettingsIPLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsKeyboard = lv_keyboard_create(ui_SettingsScreen);
    lv_obj_set_size(ui_SettingsKeyboard, lv_pct(100), 150);
    lv_obj_set_pos(ui_SettingsKeyboard, 1, 80);
    lv_obj_set_align(ui_SettingsKeyboard, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingsKeyboard, LV_OBJ_FLAG_HIDDEN); /// Flags

    ui_SettingsHomeBtn = lv_btn_create(ui_SettingsPanel);
    lv_obj_set_size(ui_SettingsHomeBtn, 35, 35);
    lv_obj_set_pos(ui_SettingsHomeBtn, 401, -6);
    lv_obj_set_align(ui_SettingsHomeBtn, LV_ALIGN_TOP_LEFT);

    ui_SettingsHomeBtnLabel = lv_label_create(ui_SettingsHomeBtn);
    lv_obj_set_align(ui_SettingsHomeBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsHomeBtnLabel, LV_SYMBOL_HOME);
    lv_obj_set_style_text_align(ui_SettingsHomeBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_DarkmodeSwitch, ui_event_DarkmodeSwitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsCityEdit, ui_event_SettingsCityEdit, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsSSIDEdit, ui_event_SettingsSSIDEdit, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsPasswordEdit, ui_event_SettingsPasswordEdit, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsHomeBtn, ui_event_SettingsHomeBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsKeyboard, ui_event_SettingsKeyboard, LV_EVENT_ALL, NULL);
}
// ALARM SCREEN INIT
void ui_Alarm_screen_init(void)
{
    ui_AlarmScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AlarmScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_AlarmPanel = lv_obj_create(ui_AlarmScreen);
    lv_obj_set_size(ui_AlarmPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_pos(ui_AlarmPanel, 1, -1);
    lv_obj_set_align(ui_AlarmPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AlarmPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_AlarmPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AlarmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Label1, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label1, -97, -111);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Alarm Clock Working Day");

    ui_Label2 = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Label2, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label2, -95, -55);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Alarm Clock Weekends");

    ui_Label3 = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Label3, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label3, -103, 17);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Alarm Clock One Off");

    ui_Switch1 = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Switch1, 50, 25);
    lv_obj_set_pos(ui_Switch1, 152, -111);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

    ui_Switch2 = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Switch2, 50, 25);
    lv_obj_set_pos(ui_Switch2, 155, -47);
    lv_obj_set_align(ui_Switch2, LV_ALIGN_CENTER);

    ui_Switch3 = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Switch3, 50, 25);
    lv_obj_set_pos(ui_Switch3, 154, 22);
    lv_obj_set_align(ui_Switch3, LV_ALIGN_CENTER);

    ui_Button6 = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Button6, 70, 41);
    lv_obj_set_pos(ui_Button6, 62, -111);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Button6);
    lv_obj_set_size(ui_Label6, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label6, -1, 1);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "08:15");

    ui_Button1 = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Button1, 70, 41);
    lv_obj_set_pos(ui_Button1, 63, 18);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_Button1);
    lv_obj_set_size(ui_Label7, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label7, -1, 1);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "15:23");

    ui_Button4 = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_Button4, 70, 41);
    lv_obj_set_pos(ui_Button4, 62, -47);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Button4);
    lv_obj_set_size(ui_Label8, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_Label8, -1, 1);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "12:03");

    ui_AlarmModalPanel = lv_obj_create(ui_AlarmScreen);
    lv_obj_set_size(ui_AlarmModalPanel, 321, 217);
    lv_obj_set_align(ui_AlarmModalPanel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_AlarmModalPanel, LV_OBJ_FLAG_HIDDEN);       /// Flags
    lv_obj_clear_flag(ui_AlarmModalPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_AlarmHourRoller = lv_roller_create(ui_AlarmModalPanel);
    lv_roller_set_options(ui_AlarmHourRoller,
                          "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_size(ui_AlarmHourRoller, 100, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_AlarmHourRoller, -34, -8);
    lv_obj_set_align(ui_AlarmHourRoller, LV_ALIGN_CENTER);

    ui_AlarmMinuteRoller = lv_roller_create(ui_AlarmModalPanel);
    lv_roller_set_options(ui_AlarmMinuteRoller,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_size(ui_AlarmMinuteRoller, 100, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_AlarmMinuteRoller, 27, -8);
    lv_obj_set_align(ui_AlarmMinuteRoller, LV_ALIGN_CENTER);

    ui_AlarmModalCancelButton = lv_btn_create(ui_AlarmModalPanel);
    lv_obj_set_size(ui_AlarmModalCancelButton, 100, 50);
    lv_obj_set_pos(ui_AlarmModalCancelButton, -74, 74);
    lv_obj_set_align(ui_AlarmModalCancelButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_AlarmModalCancelButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_AlarmModalCancelButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_Label15 = lv_label_create(ui_AlarmModalCancelButton);
    lv_obj_set_size(ui_Label15, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "Cancel");

    ui_AlarmModalOkButton = lv_btn_create(ui_AlarmModalPanel);
    lv_obj_set_size(ui_AlarmModalOkButton, 119, 47);
    lv_obj_set_pos(ui_AlarmModalOkButton, 76, 72);
    lv_obj_set_align(ui_AlarmModalOkButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_AlarmModalOkButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_AlarmModalOkButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_Label16 = lv_label_create(ui_AlarmModalOkButton);
    lv_obj_set_size(ui_Label16, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "OK");

    ui_AlarmSettingsBtn = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmSettingsBtn, 35, 35);
    lv_obj_set_pos(ui_AlarmSettingsBtn, 195, -130);
    lv_obj_set_align(ui_AlarmSettingsBtn, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_opa(ui_AlarmSettingsBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_AlarmSettingsBtnLabel = lv_label_create(ui_AlarmSettingsBtn);
    lv_obj_set_align(ui_AlarmSettingsBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AlarmSettingsBtnLabel, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_align(ui_AlarmSettingsBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmModalCancelButton, ui_event_AlarmModalCancelButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmModalOkButton, ui_event_AlarmModalOkButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmScreen, ui_event_AlarmScreen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmSettingsBtn, ui_event_AlarmSettingsBtn, LV_EVENT_ALL, ui_AlarmScreen);
}
static void set_value(void *indic, int32_t v)
{
    lv_meter_set_indicator_end_value(ui_AnalogMeter, indic, v);
}
// ANALOG SCREEN INIT
void ui_AnalogClock_screen_init(void)
{
    ui_AnalogClockScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AnalogClockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_AnalogPanel = lv_obj_create(ui_AnalogClockScreen);
    lv_obj_set_size(ui_AnalogPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_align(ui_AnalogPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AnalogPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_AnalogPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AnalogPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AnalogSettingsBtn = lv_btn_create(ui_AnalogPanel);
    lv_obj_set_size(ui_AnalogSettingsBtn, 35, 35);
    lv_obj_set_pos(ui_AnalogSettingsBtn, 195, -130);
    lv_obj_set_align(ui_AnalogSettingsBtn, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_opa(ui_AnalogSettingsBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AnalogSettingsLabel = lv_label_create(ui_AnalogSettingsBtn);
    lv_obj_set_align(ui_AnalogSettingsLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AnalogSettingsLabel, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_align(ui_AnalogSettingsLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AnalogMeter = lv_meter_create(ui_AnalogPanel);
    lv_obj_set_size(ui_AnalogMeter, 300, 300);
    lv_obj_center(ui_AnalogMeter);

    lv_meter_scale_t *scale_min = lv_meter_add_scale(ui_AnalogMeter);
    lv_meter_set_scale_ticks(ui_AnalogMeter, scale_min, 61, 1, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(ui_AnalogMeter, scale_min, 0, 60, 360, 270);

    lv_meter_scale_t *scale_hour = lv_meter_add_scale(ui_AnalogMeter);
    lv_meter_set_scale_ticks(ui_AnalogMeter, scale_hour, 12, 0, 0, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(ui_AnalogMeter, scale_hour, 1, 2, 20, lv_color_black(), 10);
    lv_meter_set_scale_range(ui_AnalogMeter, scale_hour, 1, 12, 330, 300);
    LV_IMG_DECLARE(img_hand)

    lv_meter_indicator_t *indic_min = lv_meter_add_needle_img(ui_AnalogMeter, scale_min, &img_hand, 5, 5);
    lv_meter_indicator_t *indic_hour = lv_meter_add_needle_img(ui_AnalogMeter, scale_min, &img_hand, 5, 5);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_values(&a, 0, 60);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_time(&a, 60000); /*2 sec for 1 turn of the minute hand (1 hour)*/
    lv_anim_set_var(&a, indic_min);
    lv_anim_start(&a);

    lv_anim_set_var(&a, indic_hour);
    lv_anim_set_time(&a, 120000); /*24 sec for 1 turn of the hour hand*/
    lv_anim_set_values(&a, 0, 60);
    lv_anim_start(&a);

    lv_obj_add_event_cb(ui_AnalogSettingsBtn, ui_event_AnalogSettingsBtn, LV_EVENT_ALL, ui_AnalogClockScreen);
    lv_obj_add_event_cb(ui_AnalogClockScreen, ui_event_AnalogClockScreen, LV_EVENT_ALL, NULL);
}
// DIGITAL CLOCK SCREEN INIT
void ui_DigitalClock_screen_init(void)
{
    ui_DigitalClockScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DigitalClockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_DigitalClockPanel = lv_obj_create(ui_DigitalClockScreen);
    lv_obj_set_size(ui_DigitalClockPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_style_bg_color(ui_DigitalClockPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DigitalClockPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(ui_DigitalClockPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_DigitalClockPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_DigitalClockBatteryLbl = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_pos(ui_DigitalClockBatteryLbl, 20,0);
    lv_obj_set_align(ui_DigitalClockBatteryLbl, LV_ALIGN_TOP_LEFT);
    lv_obj_set_size(ui_DigitalClockBatteryLbl, 40,20);
    lv_label_set_text(ui_DigitalClockBatteryLbl, LV_SYMBOL_BATTERY_2);

    ui_DigitalClockLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_DigitalClockLabel, 105, 75);
    lv_obj_set_align(ui_DigitalClockLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_DigitalClockLabel, "12:30.");

    lv_obj_set_style_text_align(ui_DigitalClockLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockLabel, &ui_font_Technology120, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockSecondLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockSecondLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_DigitalClockSecondLabel, 318, 124);
    lv_obj_set_align(ui_DigitalClockSecondLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_DigitalClockSecondLabel, "13");
    lv_obj_set_style_text_align(ui_DigitalClockSecondLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockSecondLabel, &ui_font_Technology60, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockDateLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockDateLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_DigitalClockDateLabel, 75, 215);
    lv_obj_set_align(ui_DigitalClockDateLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_DigitalClockDateLabel, "4th, April 2023");
    lv_obj_set_style_text_align(ui_DigitalClockDateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockDateLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockSettingsBtn = lv_btn_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockSettingsBtn, 35, 35);
    lv_obj_set_pos(ui_DigitalClockSettingsBtn, 401, -6);
    lv_obj_set_align(ui_DigitalClockSettingsBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_opa(ui_DigitalClockSettingsBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockSettingsBtnLabel = lv_label_create(ui_DigitalClockSettingsBtn);
    lv_obj_set_align(ui_DigitalClockSettingsBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DigitalClockSettingsBtnLabel, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_align(ui_DigitalClockSettingsBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_DigitalClockScreen, ui_event_DigitalClockScreen, LV_EVENT_ALL,  NULL);
    lv_obj_add_event_cb(ui_DigitalClockSettingsBtn, ui_event_DigitalClockSettingsBtn, LV_EVENT_ALL, ui_DigitalClockScreen);
}
void ui_Weather_screen_init(void)
{
    ui_Weather = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Weather, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_WeatherPanel = lv_obj_create(ui_Weather);
    lv_obj_set_size(ui_WeatherPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_pos(ui_WeatherPanel, 1, 4);
    lv_obj_set_align(ui_WeatherPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WeatherPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_WeatherPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WeatherPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherImage = lv_img_create(ui_WeatherPanel);
    lv_img_set_src(ui_WeatherImage, &ui_img_day_clear_png);
    lv_obj_set_size(ui_WeatherImage, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 128
    lv_obj_set_pos(ui_WeatherImage, -140, -71);
    lv_obj_set_align(ui_WeatherImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WeatherImage, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_WeatherImage, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_WeatherCity = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherCity, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherCity, 0, -126);
    lv_obj_set_align(ui_WeatherCity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherCity, "London, GB");
    lv_obj_set_style_text_font(ui_WeatherCity, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherTemperatureLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherTemperatureLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherTemperatureLbl, -5, -18);
    lv_obj_set_align(ui_WeatherTemperatureLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherTemperatureLbl, "13°C");
    lv_obj_set_style_text_font(ui_WeatherTemperatureLbl, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherBriefingLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherBriefingLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherBriefingLbl, 1, 39);
    lv_obj_set_align(ui_WeatherBriefingLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherBriefingLbl, "Feels like 12°C. Scattered clouds. Light breeze");

    ui_WeatherMiscLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherMiscLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 121
    lv_obj_set_pos(ui_WeatherMiscLabel, 72, -96);
    lv_obj_set_align(ui_WeatherMiscLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherMiscLabel, " 3.1m/s WNW   Humidity: 62% Dew point: 6°C");
    lv_obj_set_style_text_font(ui_WeatherMiscLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherTimesLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherTimesLbl, LV_SIZE_CONTENT,  LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherTimesLbl, -12, 80);
    lv_obj_set_align(ui_WeatherTimesLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherTimesLbl, "13:00       16:00      19:00       21:00");

    ui_WeatherThirdTempLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherThirdTempLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherThirdTempLbl, 125, 118);
    lv_obj_set_align(ui_WeatherThirdTempLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherThirdTempLbl, "10°C");

    ui_WeatherSecondTempLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherSecondTempLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherSecondTempLbl, -50, 118);
    lv_obj_set_align(ui_WeatherSecondTempLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherSecondTempLbl, "10°C	");

    ui_WeatherFourthTempLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherFourthTempLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherFourthTempLbl, 38, 118);
    lv_obj_set_align(ui_WeatherFourthTempLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherFourthTempLbl, "10°C	");

    ui_WeatherFirstTempLbl = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherFirstTempLbl, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_pos(ui_WeatherFirstTempLbl, -141, 119);
    lv_obj_set_align(ui_WeatherFirstTempLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherFirstTempLbl, "7°C	");

    ui_Label13 = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_Label13, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  /// 121
    lv_obj_set_pos(ui_Label13, 131, -70);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Label13, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_Label13, "Visibility: 10.0km UV: 3");
    lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Weather, ui_event_Weather, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_TEAL), lv_palette_main(LV_PALETTE_TEAL),
                                              true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Settings_screen_init();
    ui_Alarm_screen_init();
    ui_AnalogClock_screen_init();
    ui_DigitalClock_screen_init();
    ui_Weather_screen_init();
    // ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_DigitalClockScreen);
}
