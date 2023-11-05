#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *lastScreen = NULL;
lv_obj_t *pressed_alarm_button = NULL;

// Settings Screen Objects
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
lv_obj_t *ui_SettingsHomeButton;
lv_obj_t *ui_SettingsHomeButtonLabel;
lv_obj_t *ui_SettingsAPLabel;
lv_obj_t *ui_SettingsIPLabel;
lv_obj_t *brightnessSlider;
lv_obj_t *autoBrightnessCheckbox;

// Settings Screen Events
void ui_event_SettingsPasswordEdit(lv_event_t *e);
void ui_event_SettingsSSIDEdit(lv_event_t *e);
void ui_event_SettingsCityEdit(lv_event_t *e);
void ui_event_SettingsHomeButton(lv_event_t *e);
void ui_event_SettingsKeyboard(lv_event_t *e);

// Alarm Screen Objects
lv_obj_t *ui_AlarmScreen;
lv_obj_t *ui_AlarmPanel;
lv_obj_t *ui_AlarmDummyPanel;
lv_obj_t *ui_AlarmWorkingDayLabel;
lv_obj_t *ui_AlarmWeekendDayLabel;
lv_obj_t *ui_AlarmOneOffLabel;
lv_obj_t *ui_AlarmWorkingDaySwitch;
lv_obj_t *ui_AlarmWeekendDaySwitch;
lv_obj_t *ui_AlarmOneOffSwitch;
lv_obj_t *ui_AlarmWorkingDayButton;
lv_obj_t *ui_AlarmWorkingDayButtonLabel;
lv_obj_t *ui_AlarmWeekendDayButton;
lv_obj_t *ui_AlarmWeekendDayButtonLabel;
lv_obj_t *ui_AlarmOneOffButton;
lv_obj_t *ui_AlarmOneOffButtonLabel;
lv_obj_t *ui_AlarmModalPanel;
lv_obj_t *ui_AlarmHourRoller;
lv_obj_t *ui_AlarmMinuteRoller;
lv_obj_t *ui_AlarmModalCancelButton;
lv_obj_t *ui_AlarmModalCancelButtonLabel;
lv_obj_t *ui_AlarmModalOkButton;
lv_obj_t *ui_AlarmModalOkButtonLabel;
lv_obj_t *ui_AlarmSettingsBtn;
lv_obj_t *ui_AlarmSettingsBtnLabel;
// Alarm Screen Events
void ui_event_AlarmModalOkButton(lv_event_t *e);
void ui_event_AlarmModalCancelButton(lv_event_t *e);
void ui_event_AlarmScreen(lv_event_t *e);
void ui_event_OneOffButton(lv_event_t *e);
void ui_event_WeekendButton(lv_event_t *e);
void ui_event_WorkingDayButton(lv_event_t *e);

// Analog Clock Objects
lv_obj_t *ui_AnalogClockScreen;
lv_obj_t *ui_AnalogClockPanel;
lv_obj_t *ui_AnalogSettingsBtn;
lv_obj_t *ui_AnalogSettingsLabel;
lv_obj_t *ui_ImageWatchface;
lv_obj_t *ui_ImageArmHour;
lv_obj_t *ui_ImageArmMinute;
lv_obj_t *ui_ImageArmSecond;

// Digital Clock Objects
lv_obj_t *ui_DigitalClockScreen;
lv_obj_t *ui_DigitalClockPanel;
lv_obj_t *ui_DigitalClockLabel;
lv_obj_t *ui_DigitalClockSecondLabel;
lv_obj_t *ui_DigitalClockDateLabel;
lv_obj_t *ui_DigitalClockDayLabel;
lv_obj_t *ui_DigitalClockSettingsBtn;
lv_obj_t *ui_DigitalClockSettingsBtnLabel;
// Digital Clock Events
void ui_event_DigitalClockScreen(lv_event_t *e);

// Weather Objects
lv_obj_t *ui_WeatherScreen;
lv_obj_t *ui_WeatherPanel;
lv_obj_t *ui_WeatherImage;
lv_obj_t *ui_WeatherCity;
lv_obj_t *ui_WeatherTemperatureLabel;
lv_obj_t *ui_WeatherBriefingLabel;
lv_obj_t *ui_WeatherWindLabel;
lv_obj_t *ui_WeatherHumidityLabel;
lv_obj_t *ui_WeatherPressureLabel;
lv_obj_t *ui_WeatherFeelsLikeLabel;
lv_obj_t *ui_WeatherMaxTempLabel;
lv_obj_t *ui_WeatherMinTempLabel;
lv_obj_t *ui_WeatherRainProbabLabel;
lv_obj_t *ui_WeatherTimesLabel;
lv_obj_t *ui_WeatherThirdTempLabel;
lv_obj_t *ui_WeatherSecondTempLabel;
lv_obj_t *ui_WeatherFourthTempLabel;
lv_obj_t *ui_WeatherFirstTempLabel;

lv_obj_t *ui_BatteryLabel;
lv_obj_t *ui_SettingsButton;
lv_obj_t *ui_SettingsButtonLabel;
// Weather Events
void ui_event_WeatherScreen(lv_event_t *e);

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
void ui_create_settings_screen()
{
    if (ui_SettingsScreen == NULL)
    {
        ui_SettingsScreen = lv_obj_create(NULL);
        lv_obj_add_flag(ui_SettingsScreen, LV_OBJ_FLAG_IGNORE_LAYOUT); /// Flags
        lv_obj_set_scroll_dir(ui_SettingsScreen, LV_DIR_VER);
        lv_obj_clear_flag(ui_SettingsScreen, LV_OBJ_FLAG_SCROLL_ELASTIC);

        ui_SettingsPanel = lv_obj_create(ui_SettingsScreen);
        lv_obj_set_size(ui_SettingsPanel, lv_pct(100), SETTINGS_PANEL_HEIGHT);
        lv_obj_set_style_bg_color(ui_SettingsPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_SettingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(ui_SettingsPanel, LV_OBJ_FLAG_SCROLL_ELASTIC);

        ui_DarkmodeLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_DarkmodeLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_DarkmodeLabel, 35, 15);
        lv_obj_set_align(ui_DarkmodeLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_DarkmodeLabel, "Dark Mode");
        lv_obj_set_style_text_font(ui_DarkmodeLabel, &montserrat_18, LV_PART_MAIN);

        ui_DarkmodeSwitch = lv_switch_create(ui_SettingsPanel);
        lv_obj_set_size(ui_DarkmodeSwitch, 50, 25);
        lv_obj_set_pos(ui_DarkmodeSwitch, 175, 15);
        lv_obj_set_align(ui_DarkmodeSwitch, LV_ALIGN_TOP_LEFT);

        brightnessSlider = lv_slider_create(ui_SettingsPanel);
        lv_obj_align_to(brightnessSlider,  ui_DarkmodeLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 35);
        lv_slider_set_range(brightnessSlider, 0 , 255);

        autoBrightnessCheckbox = lv_checkbox_create(ui_SettingsPanel);
        lv_obj_align_to(autoBrightnessCheckbox, brightnessSlider, LV_ALIGN_OUT_RIGHT_MID, 50, 0);
        lv_checkbox_set_text(autoBrightnessCheckbox, "Auto");

        ui_SettingsCityEdit = lv_textarea_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsCityEdit, 250, LV_SIZE_CONTENT); /// 33
        lv_obj_set_pos(ui_SettingsCityEdit, 180, SETTINGS_PANEL_HEIGHT / 5);
        lv_obj_set_align(ui_SettingsCityEdit, LV_ALIGN_TOP_LEFT);
        lv_textarea_set_max_length(ui_SettingsCityEdit, 100);
        lv_textarea_set_placeholder_text(ui_SettingsCityEdit, "City, country code ISO-81118");
        lv_textarea_set_one_line(ui_SettingsCityEdit, true);

        ui_SettingsCityLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsCityLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_SettingsCityLabel, 20, SETTINGS_PANEL_HEIGHT / 5);
        lv_obj_set_align(ui_SettingsCityLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_SettingsCityLabel, "City and\ncountry code");
        lv_obj_set_style_text_font(ui_SettingsCityLabel, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_SettingsCityLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_SettingsSSIDEdit = lv_textarea_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsSSIDEdit, 250, LV_SIZE_CONTENT);
        lv_obj_set_pos(ui_SettingsSSIDEdit, 180, SETTINGS_PANEL_HEIGHT / 5 + 60);
        lv_obj_set_align(ui_SettingsSSIDEdit, LV_ALIGN_TOP_LEFT);
        lv_textarea_set_max_length(ui_SettingsSSIDEdit, 50);
        lv_textarea_set_placeholder_text(ui_SettingsSSIDEdit, "WiFi SSID");
        lv_textarea_set_one_line(ui_SettingsSSIDEdit, true);

        ui_SettingsSSIDLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsSSIDLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_SettingsSSIDLabel, 40, SETTINGS_PANEL_HEIGHT / 5 + 70);
        lv_obj_set_align(ui_SettingsSSIDLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_SettingsSSIDLabel, "WiFi SSID");
        lv_obj_set_style_text_font(ui_SettingsSSIDLabel, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_SettingsPasswordEdit = lv_textarea_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsPasswordEdit, 250, LV_SIZE_CONTENT); /// 33
        lv_obj_set_pos(ui_SettingsPasswordEdit, 180, SETTINGS_PANEL_HEIGHT / 5 + 60 * 2);
        lv_obj_set_align(ui_SettingsPasswordEdit, LV_ALIGN_TOP_LEFT);
        lv_textarea_set_max_length(ui_SettingsPasswordEdit, 100);
        lv_textarea_set_placeholder_text(ui_SettingsPasswordEdit, "WiFi Password");
        lv_textarea_set_one_line(ui_SettingsPasswordEdit, true);
        lv_textarea_set_password_mode(ui_SettingsPasswordEdit, true);

        ui_SettingsPasswordLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsPasswordLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_SettingsPasswordLabel, 20, SETTINGS_PANEL_HEIGHT / 5 + 65 * 2);
        lv_obj_set_align(ui_SettingsPasswordLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_SettingsPasswordLabel, "WiFi Password");
        lv_obj_set_style_text_font(ui_SettingsPasswordLabel, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_SettingsAPLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsAPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_SettingsAPLabel, 80, SETTINGS_PANEL_HEIGHT - 60);
        lv_obj_set_align(ui_SettingsAPLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_SettingsAPLabel, "AccessPoint IP:");
        lv_obj_set_style_text_font(ui_SettingsAPLabel, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_SettingsIPLabel = lv_label_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsIPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_pos(ui_SettingsIPLabel, 230, SETTINGS_PANEL_HEIGHT - 60);
        lv_obj_set_align(ui_SettingsIPLabel, LV_ALIGN_TOP_LEFT);
        lv_label_set_text(ui_SettingsIPLabel, "192.120.12.99");
        lv_obj_set_style_text_font(ui_SettingsIPLabel, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_SettingsHomeButton = lv_btn_create(ui_SettingsPanel);
        lv_obj_set_size(ui_SettingsHomeButton, 35, 35);
        lv_obj_set_pos(ui_SettingsHomeButton, 401, -6);
        lv_obj_set_align(ui_SettingsHomeButton, LV_ALIGN_TOP_LEFT);

        ui_SettingsHomeButtonLabel = lv_label_create(ui_SettingsHomeButton);
        lv_obj_set_align(ui_SettingsHomeButtonLabel, LV_ALIGN_CENTER);
        lv_label_set_text(ui_SettingsHomeButtonLabel, LV_SYMBOL_HOME);
        lv_obj_set_style_text_align(ui_SettingsHomeButtonLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_event_cb(ui_DarkmodeSwitch, ui_event_DarkmodeSwitch, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_SettingsCityEdit, ui_event_SettingsCityEdit, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_SettingsSSIDEdit, ui_event_SettingsSSIDEdit, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_SettingsPasswordEdit, ui_event_SettingsPasswordEdit, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_SettingsHomeButton, ui_event_SettingsHomeButton, LV_EVENT_ALL, NULL);
    }
}
void ui_delete_settings_screen()
{
    if (ui_SettingsScreen != NULL)
    {
        lv_obj_remove_event_cb(ui_DarkmodeSwitch, ui_event_DarkmodeSwitch);
        lv_obj_remove_event_cb(ui_SettingsCityEdit, ui_event_SettingsCityEdit);
        lv_obj_remove_event_cb(ui_SettingsSSIDEdit, ui_event_SettingsSSIDEdit);
        lv_obj_remove_event_cb(ui_SettingsPasswordEdit, ui_event_SettingsPasswordEdit);
        lv_obj_remove_event_cb(ui_SettingsHomeButton, ui_event_SettingsHomeButton);
        // lv_obj_del(ui_SettingsScreen);
        ui_SettingsScreen = NULL;
        ui_SettingsPanel = NULL;
        ui_DarkmodeLabel = NULL;
        ui_DarkmodeSwitch = NULL;
        ui_SettingsCityEdit = NULL;
        ui_SettingsCityLabel = NULL;
        ui_SettingsSSIDEdit = NULL;
        ui_SettingsSSIDLabel = NULL;
        ui_SettingsPasswordEdit = NULL;
        ui_SettingsPasswordLabel = NULL;
        ui_SettingsAPLabel = NULL;
        ui_SettingsIPLabel = NULL;
        ui_SettingsHomeButton = NULL;
        ui_SettingsHomeButtonLabel = NULL;
    }
}
void ui_create_keyboard(lv_obj_t *target)
{
    if (ui_SettingsKeyboard == NULL)
    {
        ui_SettingsKeyboard = lv_keyboard_create(ui_SettingsScreen);
        lv_obj_set_size(ui_SettingsKeyboard, lv_pct(100), 150);
        lv_obj_set_pos(ui_SettingsKeyboard, 0, 0);
        lv_obj_set_align(ui_SettingsKeyboard, LV_ALIGN_BOTTOM_LEFT);
        lv_keyboard_set_textarea(ui_SettingsKeyboard, target);
        lv_obj_add_event_cb(ui_SettingsKeyboard, ui_event_SettingsKeyboard, LV_EVENT_ALL, NULL);
    }
    else
    {
        lv_keyboard_set_textarea(ui_SettingsKeyboard, target);
    }
}
void ui_delete_keyboard()
{
    if (ui_SettingsKeyboard != NULL)
    {
        lv_keyboard_set_textarea(ui_SettingsKeyboard, NULL);
        lv_obj_remove_event_cb(ui_SettingsKeyboard, ui_event_SettingsKeyboard);
        lv_obj_del(ui_SettingsKeyboard);
        lv_obj_set_height(ui_SettingsPanel, SETTINGS_PANEL_HEIGHT);
        ui_SettingsKeyboard = NULL;
    }
}
void ui_event_SettingsHomeButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lv_event_send(ui_SettingsKeyboard, LV_EVENT_CANCEL, NULL);
        lv_scr_load_anim(lastScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, true);
        ui_delete_settings_screen();
    }
}
void ui_event_SettingsKeyboard(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CANCEL)
    {
        ui_delete_keyboard();
    }
}
void ui_event_SettingsCityEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        lv_obj_set_height(ui_SettingsPanel, SETTINGS_PANEL_HEIGHT / 4);
        lv_obj_readjust_scroll(ui_SettingsScreen, LV_ANIM_OFF);
        lv_obj_scroll_to_y(ui_SettingsPanel, lv_obj_get_y(lv_event_get_current_target(e)) - 80, LV_ANIM_ON);
        ui_create_keyboard(lv_event_get_current_target(e));
    }
    if (event_code == LV_EVENT_READY)
    {
        ui_delete_keyboard();
        lv_textarea_set_text(ui_SettingsCityEdit, "ABOBA");
    }
}
void ui_event_SettingsSSIDEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        lv_obj_set_height(ui_SettingsPanel, SETTINGS_PANEL_HEIGHT / 4);
        lv_obj_readjust_scroll(ui_SettingsScreen, LV_ANIM_OFF);
        lv_obj_scroll_to_y(ui_SettingsPanel, lv_obj_get_y(lv_event_get_current_target(e)) - 80, LV_ANIM_ON);
        ui_create_keyboard(lv_event_get_current_target(e));
    }
    if (event_code == LV_EVENT_READY)
    {
        ui_delete_keyboard();
        lv_textarea_set_text(ui_SettingsSSIDEdit, "ABOBA");
    }
}
void ui_event_SettingsPasswordEdit(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED)
    {
        lv_obj_set_height(ui_SettingsPanel, SETTINGS_PANEL_HEIGHT / 4);
        lv_obj_readjust_scroll(ui_SettingsScreen, LV_ANIM_OFF);
        lv_obj_scroll_to_y(ui_SettingsPanel, lv_obj_get_y(lv_event_get_current_target(e)) - 80, LV_ANIM_ON);
        ui_create_keyboard(lv_event_get_current_target(e));
    }
    if (event_code == LV_EVENT_READY)
    {
        ui_delete_keyboard();
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
            lv_obj_set_style_text_color(ui_SettingsButtonLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_SettingsButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_AlarmWorkingDayButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_AlarmWeekendDayButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(ui_AlarmOneOffButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmWorkingDayButtonLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmWeekendDayButtonLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmOneOffButtonLabel, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else
        {
            lv_disp_t *dispp = lv_disp_get_default();
            lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_TEAL), lv_palette_main(LV_PALETTE_TEAL),
                                                      true, LV_FONT_DEFAULT);
            lv_disp_set_theme(dispp, theme);
            lv_obj_set_style_text_color(ui_SettingsButtonLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmWorkingDayButtonLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmWeekendDayButtonLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_AlarmOneOffButtonLabel, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}
void parse_alarm_label(char *string, int pos, char *buff)
{
    for (size_t i = 0; i < 2; i++)
    {
        buff[i] = string[i + pos];
    }
}
void ui_set_roller_time(const lv_obj_t *label)
{
    char alarm_buff[2];
    parse_alarm_label(lv_label_get_text(label), HOUR_LABEL, alarm_buff);
    lv_roller_set_selected(ui_AlarmHourRoller, atoi(alarm_buff), LV_ANIM_OFF);
    parse_alarm_label(lv_label_get_text(label), MINUTE_LABEL, alarm_buff);
    lv_roller_set_selected(ui_AlarmMinuteRoller, atoi(alarm_buff), LV_ANIM_OFF);
}
void ui_create_alarm_modal_panel(lv_obj_t *target_label)
{

    if (ui_AlarmModalPanel == NULL)
    {
        char hour_count[HOUR_COUNT * 3] = {0};
        char hour_buffer[4] = {0};
        char minute_count[MINUTE_COUNT * 3] = {0};
        char minute_buffer[3] = {0};
        ui_AlarmDummyPanel = lv_obj_create(ui_AlarmScreen);
        lv_obj_set_size(ui_AlarmDummyPanel, 480, 320);
        lv_obj_set_align(ui_AlarmDummyPanel, LV_ALIGN_CENTER);
        lv_obj_set_style_bg_opa(ui_AlarmDummyPanel, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
        ui_AlarmModalPanel = lv_obj_create(ui_AlarmDummyPanel);
        lv_obj_set_size(ui_AlarmModalPanel, 250, 230);
        lv_obj_set_align(ui_AlarmModalPanel, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_AlarmModalPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
        for (short int i = 0; i < HOUR_COUNT; i++)
        {
            if (i == HOUR_COUNT - 1)
            {
                sprintf(hour_buffer, "%2i", i);
            }
            else
            {
                sprintf(hour_buffer, "%02i\n", i);
            }
            strcat(hour_count, hour_buffer);
        }
        for (short int i = 0; i < MINUTE_COUNT; i++)
        {
            if (i == MINUTE_COUNT - 1)
            {
                sprintf(minute_buffer, "%02i", i);
            }
            else
            {
                sprintf(minute_buffer, "%02i\n", i);
            }
            strcat(minute_count, minute_buffer);
        }
        ui_AlarmHourRoller = lv_roller_create(ui_AlarmModalPanel);
        lv_roller_set_options(ui_AlarmHourRoller,
                              hour_count, LV_ROLLER_MODE_INFINITE);
        lv_obj_set_size(ui_AlarmHourRoller, 90, 110);
        lv_obj_set_pos(ui_AlarmHourRoller, -50, -35);
        lv_obj_set_align(ui_AlarmHourRoller, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(ui_AlarmHourRoller, &montserrat_18, LV_PART_MAIN);

        ui_AlarmMinuteRoller = lv_roller_create(ui_AlarmModalPanel);
        lv_roller_set_options(ui_AlarmMinuteRoller,
                              minute_count,
                              LV_ROLLER_MODE_INFINITE);
        lv_obj_set_size(ui_AlarmMinuteRoller, 90, 110);
        lv_obj_align_to(ui_AlarmMinuteRoller, ui_AlarmHourRoller, LV_ALIGN_BOTTOM_LEFT, 83, 18);
        lv_obj_set_style_text_font(ui_AlarmMinuteRoller, &montserrat_18, LV_PART_MAIN);

        ui_AlarmModalCancelButton = lv_btn_create(ui_AlarmModalPanel);
        lv_obj_set_size(ui_AlarmModalCancelButton, 90, 45);
        lv_obj_set_pos(ui_AlarmModalCancelButton, 13, 0);
        lv_obj_set_align(ui_AlarmModalCancelButton, LV_ALIGN_BOTTOM_LEFT);

        ui_AlarmModalCancelButtonLabel = lv_label_create(ui_AlarmModalCancelButton);
        lv_obj_set_size(ui_AlarmModalCancelButtonLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_align(ui_AlarmModalCancelButtonLabel, LV_ALIGN_CENTER);
        lv_label_set_text(ui_AlarmModalCancelButtonLabel, "Cancel");
        lv_obj_set_style_text_font(ui_AlarmModalCancelButtonLabel, &montserrat_18, LV_PART_MAIN);

        ui_AlarmModalOkButton = lv_btn_create(ui_AlarmModalPanel);
        lv_obj_set_size(ui_AlarmModalOkButton, 90, 45);
        lv_obj_align_to(ui_AlarmModalOkButton, ui_AlarmModalCancelButton, LV_ALIGN_BOTTOM_LEFT, 85, 10);

        ui_AlarmModalOkButtonLabel = lv_label_create(ui_AlarmModalOkButton);
        lv_obj_set_size(ui_AlarmModalOkButtonLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
        lv_obj_set_align(ui_AlarmModalOkButtonLabel, LV_ALIGN_CENTER);
        lv_label_set_text(ui_AlarmModalOkButtonLabel, "OK");
        lv_obj_set_style_text_font(ui_AlarmModalOkButtonLabel, &montserrat_18, LV_PART_MAIN);

        lv_obj_add_event_cb(ui_AlarmModalCancelButton, ui_event_AlarmModalCancelButton, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_AlarmModalOkButton, ui_event_AlarmModalOkButton, LV_EVENT_ALL, target_label);

        ui_set_roller_time(target_label);
    }
}
void ui_delete_alarm_modal_panel()
{
    if (ui_AlarmDummyPanel != NULL)
    {
        lv_obj_remove_event_cb(ui_AlarmModalCancelButton, ui_event_AlarmModalCancelButton);
        lv_obj_remove_event_cb(ui_AlarmModalOkButton, ui_event_AlarmModalOkButton);
        lv_obj_del(ui_AlarmDummyPanel);
        ui_AlarmDummyPanel = NULL;
        ui_AlarmModalPanel = NULL;
        ui_AlarmHourRoller = NULL;
        ui_AlarmMinuteRoller = NULL;
        ui_AlarmModalCancelButton = NULL;
        ui_AlarmModalCancelButtonLabel = NULL;
        ui_AlarmModalOkButton = NULL;
        ui_AlarmModalOkButtonLabel = NULL;
    }
}
void ui_event_WorkingDayButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_create_alarm_modal_panel(ui_AlarmWorkingDayButtonLabel);
    }
}
void ui_event_WeekendButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_create_alarm_modal_panel(ui_AlarmWeekendDayButtonLabel);
    }
}

void ui_event_OneOffButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_create_alarm_modal_panel(ui_AlarmOneOffButtonLabel);
    }
}
void ui_event_AlarmModalCancelButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_delete_alarm_modal_panel();
    }
}
void ui_event_AlarmModalOkButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lv_label_set_text_fmt(e->user_data, "%02i:%02i", lv_roller_get_selected(ui_AlarmHourRoller), lv_roller_get_selected(ui_AlarmMinuteRoller));
        ui_delete_alarm_modal_panel();
    }
}
// Screen change on GESTURES
void ui_event_AlarmScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_AnalogClockScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_AnalogClockScreen, 0));
        ui_screen_change(ui_AnalogClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_DigitalClockScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_WeatherScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_WeatherScreen, 0));
        ui_screen_change(ui_WeatherScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    else if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_AnalogClockScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_AnalogClockScreen, 0));
        ui_screen_change(ui_AnalogClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void ui_event_WeatherScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_DigitalClockScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_DigitalClockScreen, 0));
        ui_screen_change(ui_DigitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

void ui_event_AnalogClockScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_DigitalClockScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_DigitalClockScreen, 0));
        ui_screen_change(ui_DigitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    else if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_obj_set_parent(ui_SettingsButton, lv_obj_get_child(ui_AlarmScreen, 0));
        lv_obj_set_parent(ui_BatteryLabel, lv_obj_get_child(ui_AlarmScreen, 0));
        ui_screen_change(ui_AlarmScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

// Screen change on Button
void screen_load_event_cb(lv_event_t *e){
    // if(ui_SettingsScreen != NULL){
    // lv_obj_del(ui_SettingsScreen);
    // }
}
void ui_event_SettingsButton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lastScreen = lv_scr_act();
        ui_create_settings_screen();
        ui_screen_change(ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_WeatherSettingsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lastScreen = lv_event_get_user_data(e);
        ui_screen_change(ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_move_battery_label(lv_obj_t *screen)
{
    lv_obj_set_parent(ui_BatteryLabel, screen);
}

///////////////////// SCREENS INIT////////////////////
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

    ui_AlarmWorkingDayLabel = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWorkingDayLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_AlarmWorkingDayLabel, 10, 65);
    lv_obj_set_align(ui_AlarmWorkingDayLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_AlarmWorkingDayLabel, "По будням");
    lv_obj_set_style_text_font(ui_AlarmWorkingDayLabel, &montserrat_18, LV_PART_MAIN);

    ui_AlarmWorkingDayButton = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWorkingDayButton, 70, 41);
    lv_obj_align_to(ui_AlarmWorkingDayButton, ui_AlarmWorkingDayLabel, LV_ALIGN_BOTTOM_LEFT, 270, 10);
    lv_obj_set_style_bg_opa(ui_AlarmWorkingDayButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AlarmWorkingDayButtonLabel = lv_label_create(ui_AlarmWorkingDayButton);
    lv_obj_set_size(ui_AlarmWorkingDayButtonLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_AlarmWorkingDayButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AlarmWorkingDayButtonLabel, "08:15");
    lv_obj_set_style_text_font(ui_AlarmWorkingDayButtonLabel, &montserrat_18, LV_PART_MAIN);


    ui_AlarmWorkingDaySwitch = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWorkingDaySwitch, 50, 25);
    lv_obj_align_to(ui_AlarmWorkingDaySwitch, ui_AlarmWorkingDayButton, LV_ALIGN_BOTTOM_LEFT, 80, 5);

    ui_AlarmWeekendDayLabel = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWeekendDayLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_AlarmWeekendDayLabel, ui_AlarmWorkingDayLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 40);
    lv_label_set_text(ui_AlarmWeekendDayLabel, "СБ ВС");
    lv_obj_set_style_text_font(ui_AlarmWeekendDayLabel, &montserrat_18, LV_PART_MAIN);

    ui_AlarmWeekendDayButton = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWeekendDayButton, 70, 41);
    lv_obj_align_to(ui_AlarmWeekendDayButton, ui_AlarmWorkingDayButton, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_set_style_bg_opa(ui_AlarmWeekendDayButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AlarmWeekendDayButton, &montserrat_18, LV_PART_MAIN);

    ui_AlarmWeekendDayButtonLabel = lv_label_create(ui_AlarmWeekendDayButton);
    lv_obj_set_size(ui_AlarmWeekendDayButtonLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_AlarmWeekendDayButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AlarmWeekendDayButtonLabel, "15:23");
    lv_obj_set_style_text_font(ui_AlarmWeekendDayButtonLabel, &montserrat_18, LV_PART_MAIN);

    ui_AlarmWeekendDaySwitch = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmWeekendDaySwitch, 50, 25);
    lv_obj_align_to(ui_AlarmWeekendDaySwitch, ui_AlarmWorkingDaySwitch, LV_ALIGN_OUT_BOTTOM_MID, 0, 35);

    ui_AlarmOneOffLabel = lv_label_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmOneOffLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_AlarmOneOffLabel, ui_AlarmWeekendDayLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 40);
    lv_label_set_text(ui_AlarmOneOffLabel, "Однократно");
    lv_obj_set_style_text_font(ui_AlarmOneOffLabel, &montserrat_18, LV_PART_MAIN);

    ui_AlarmOneOffButton = lv_btn_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmOneOffButton, 70, 41);
    lv_obj_align_to(ui_AlarmOneOffButton, ui_AlarmWeekendDayButton, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_set_style_bg_opa(ui_AlarmOneOffButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AlarmOneOffButtonLabel = lv_label_create(ui_AlarmOneOffButton);
    lv_obj_set_size(ui_AlarmOneOffButtonLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_AlarmOneOffButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AlarmOneOffButtonLabel, "12:03");
    lv_obj_set_style_text_font(ui_AlarmOneOffButtonLabel, &montserrat_18, LV_PART_MAIN);

    ui_AlarmOneOffSwitch = lv_switch_create(ui_AlarmPanel);
    lv_obj_set_size(ui_AlarmOneOffSwitch, 50, 25);
    lv_obj_align_to(ui_AlarmOneOffSwitch, ui_AlarmWeekendDaySwitch, LV_ALIGN_OUT_BOTTOM_MID, 0, 35);

    lv_obj_add_event_cb(ui_AlarmWorkingDayButton, ui_event_WorkingDayButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmWeekendDayButton, ui_event_WeekendButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmOneOffButton, ui_event_OneOffButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AlarmScreen, ui_event_AlarmScreen, LV_EVENT_ALL, NULL);
}

void ui_AnalogClock_screen_init(void)
{
    ui_AnalogClockScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AnalogClockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_AnalogClockPanel = lv_obj_create(ui_AnalogClockScreen);
    lv_obj_set_size(ui_AnalogClockPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_align(ui_AnalogClockPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_AnalogClockPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_AnalogClockPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AnalogClockPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageWatchface = lv_img_create(ui_AnalogClockScreen);
    lv_img_set_src(ui_ImageWatchface, &ui_img_watchface240_png);
    lv_obj_set_width(ui_ImageWatchface, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ImageWatchface, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_ImageWatchface, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageWatchface, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageWatchface, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_ImageArmHour = lv_img_create(ui_AnalogClockScreen);
    lv_img_set_src(ui_ImageArmHour, &ui_img_armhour_png);
    lv_obj_set_width(ui_ImageArmHour, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ImageArmHour, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ImageArmHour, 0);
    lv_obj_set_y(ui_ImageArmHour, -35);
    lv_obj_set_align(ui_ImageArmHour, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageArmHour, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageArmHour, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_img_set_pivot(ui_ImageArmHour, 9, 77);
    lv_img_set_angle(ui_ImageArmHour, 450);

    ui_ImageArmMinute = lv_img_create(ui_AnalogClockScreen);
    lv_img_set_src(ui_ImageArmMinute, &ui_img_armminute_png);
    lv_obj_set_width(ui_ImageArmMinute, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ImageArmMinute, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ImageArmMinute, 0);
    lv_obj_set_y(ui_ImageArmMinute, -49);
    lv_obj_set_align(ui_ImageArmMinute, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageArmMinute, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageArmMinute, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_img_set_pivot(ui_ImageArmMinute, 9, 105);
    lv_img_set_angle(ui_ImageArmMinute, 1800);

    ui_ImageArmSecond = lv_img_create(ui_AnalogClockScreen);
    lv_img_set_src(ui_ImageArmSecond, &ui_img_armsecond_png);
    lv_obj_set_width(ui_ImageArmSecond, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ImageArmSecond, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ImageArmSecond, 0);
    lv_obj_set_y(ui_ImageArmSecond, -47);
    lv_obj_set_align(ui_ImageArmSecond, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageArmSecond, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageArmSecond, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_img_set_pivot(ui_ImageArmSecond, 5, 115);
    lv_img_set_angle(ui_ImageArmSecond, 3150);

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

    ui_DigitalClockLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockLabel, 320, 100);
    lv_obj_set_pos(ui_DigitalClockLabel, 0, -30);
    lv_obj_set_align(ui_DigitalClockLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DigitalClockLabel, "00:00");

    lv_obj_set_style_text_align(ui_DigitalClockLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockLabel, &ui_font_Roboto120, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockSecondLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockSecondLabel, 60, 40);
    lv_obj_align_to(ui_DigitalClockSecondLabel, ui_DigitalClockLabel, LV_ALIGN_BOTTOM_RIGHT, 50, -3);
    lv_label_set_text(ui_DigitalClockSecondLabel, "00");
    lv_obj_set_style_text_align(ui_DigitalClockSecondLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockSecondLabel, &ui_font_Roboto45, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockDateLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockDateLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_DigitalClockDateLabel, 0, 80);
    lv_obj_set_align(ui_DigitalClockDateLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DigitalClockDateLabel, "04.05.2023");
    lv_obj_set_style_text_align(ui_DigitalClockDateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockDateLabel, &montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DigitalClockDayLabel = lv_label_create(ui_DigitalClockPanel);
    lv_obj_set_size(ui_DigitalClockDayLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    // lv_obj_set_pos(ui_DigitalClockDayLabel, 0, 115);
    lv_obj_align_to(ui_DigitalClockDayLabel,ui_DigitalClockDateLabel, LV_ALIGN_OUT_RIGHT_MID, 10,-10);
    lv_label_set_text(ui_DigitalClockDayLabel, "Вс");
    lv_obj_set_style_text_align(ui_DigitalClockDayLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DigitalClockDayLabel, &montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_add_event_cb(ui_DigitalClockScreen, screen_load_event_cb, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_DigitalClockScreen, ui_event_DigitalClockScreen, LV_EVENT_ALL, NULL);
}
void ui_Weather_screen_init(void)
{
    ui_WeatherScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_WeatherScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_WeatherPanel = lv_obj_create(ui_WeatherScreen);
    lv_obj_set_size(ui_WeatherPanel, lv_pct(100), lv_pct(100));
    lv_obj_set_pos(ui_WeatherPanel, 0, 0);
    lv_obj_set_align(ui_WeatherPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WeatherPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_WeatherPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WeatherPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherImage = lv_img_create(ui_WeatherPanel);
    lv_img_set_src(ui_WeatherImage, &ui_img_day_clear_png);
    lv_obj_set_size(ui_WeatherImage, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 128
    lv_obj_set_pos(ui_WeatherImage, 0, 30);
    lv_obj_set_align(ui_WeatherImage, LV_ALIGN_TOP_LEFT); /// Flags

    ui_WeatherCity = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherCity, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherCity, 0, 15);
    lv_obj_set_align(ui_WeatherCity, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_WeatherCity, "Khabarovsk, RU");
    lv_label_set_long_mode(ui_WeatherCity, LV_LABEL_LONG_CLIP);
    lv_obj_set_style_text_font(ui_WeatherCity, &montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherTemperatureLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherTemperatureLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherTemperatureLabel, -15, -60);
    lv_obj_set_align(ui_WeatherTemperatureLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherTemperatureLabel, "-13°C");
    lv_obj_set_style_text_font(ui_WeatherTemperatureLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherFeelsLikeLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherFeelsLikeLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 121
    lv_obj_set_pos(ui_WeatherFeelsLikeLabel, 0, -5);
    lv_obj_set_align(ui_WeatherFeelsLikeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherFeelsLikeLabel, "Ощущается как: -24°C");
    lv_obj_set_style_text_font(ui_WeatherFeelsLikeLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherWindLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherWindLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 121
    lv_obj_set_pos(ui_WeatherWindLabel, 140, -80);
    lv_obj_set_align(ui_WeatherWindLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherWindLabel, "Ветер: 14.1 км/ч ЗСЗ");
    lv_obj_set_style_text_font(ui_WeatherWindLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherHumidityLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherHumidityLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 121
    // lv_obj_set_pos(ui_WeatherHumidityLabel, 140, -50);
    lv_obj_align_to(ui_WeatherHumidityLabel, ui_WeatherWindLabel,LV_ALIGN_BOTTOM_LEFT, 0 , 20);
    lv_label_set_text(ui_WeatherHumidityLabel, "Влажность: 75%");
    lv_obj_set_style_text_font(ui_WeatherHumidityLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherPressureLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherPressureLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 121
    lv_obj_align_to(ui_WeatherPressureLabel, ui_WeatherHumidityLabel,LV_ALIGN_BOTTOM_LEFT, 0 , 20);
    lv_label_set_text(ui_WeatherPressureLabel, "Давление: 1027 мбар");
    lv_obj_set_style_text_font(ui_WeatherPressureLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherBriefingLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherBriefingLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherBriefingLabel, 0, 30);
    lv_obj_set_align(ui_WeatherBriefingLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherBriefingLabel, "Переменная облачность. Возможен дождь.");
    lv_obj_set_style_text_font(ui_WeatherBriefingLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherMaxTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherMaxTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherMaxTempLabel, -150, 65);
    lv_obj_set_align(ui_WeatherMaxTempLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherMaxTempLabel, "Макс. t: -12°C");
    lv_obj_set_style_text_font(ui_WeatherMaxTempLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherMinTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherMinTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_WeatherMinTempLabel, ui_WeatherMaxTempLabel,  LV_ALIGN_OUT_RIGHT_MID, 15, -1);
    lv_label_set_text(ui_WeatherMinTempLabel, "Мин. t: -20°C");
    lv_obj_set_style_text_font(ui_WeatherMinTempLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_WeatherRainProbabLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherRainProbabLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_WeatherRainProbabLabel, ui_WeatherMinTempLabel,  LV_ALIGN_OUT_RIGHT_MID, 15, -1);
    lv_label_set_text(ui_WeatherRainProbabLabel, "Вероятность осадков: 0%");
    lv_obj_set_style_text_font(ui_WeatherRainProbabLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatherTimesLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherTimesLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherTimesLabel, 0, 95);
    lv_obj_set_align(ui_WeatherTimesLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WeatherTimesLabel, "Ночь               Утро               День               Вечер");
    lv_obj_set_style_text_font(ui_WeatherTimesLabel, &montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_WeatherFirstTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherFirstTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_WeatherFirstTempLabel, 55, -10);
    lv_obj_set_align(ui_WeatherFirstTempLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_WeatherFirstTempLabel, "-7°C");

    ui_WeatherSecondTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherSecondTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_WeatherSecondTempLabel,ui_WeatherFirstTempLabel, LV_ALIGN_OUT_RIGHT_TOP, 65 ,0);
    lv_label_set_text(ui_WeatherSecondTempLabel, "-10°C");

    ui_WeatherThirdTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherThirdTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_WeatherThirdTempLabel,ui_WeatherSecondTempLabel, LV_ALIGN_OUT_RIGHT_TOP, 65 ,0);
    lv_label_set_text(ui_WeatherThirdTempLabel, "-13°C");

    ui_WeatherFourthTempLabel = lv_label_create(ui_WeatherPanel);
    lv_obj_set_size(ui_WeatherFourthTempLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_align_to(ui_WeatherFourthTempLabel,ui_WeatherThirdTempLabel, LV_ALIGN_OUT_RIGHT_TOP, 65 ,0);
    lv_label_set_text(ui_WeatherFourthTempLabel, "-18°C");



    lv_obj_add_event_cb(ui_WeatherScreen, ui_event_WeatherScreen, LV_EVENT_ALL, NULL);
}
void ui_Dock_init()
{
    lv_obj_t *panel = lv_obj_get_child(lv_scr_act(), 0);
    ui_BatteryLabel = lv_label_create(panel);
    lv_obj_set_pos(ui_BatteryLabel, 20, 0);
    lv_obj_set_align(ui_BatteryLabel, LV_ALIGN_TOP_LEFT);
    lv_obj_set_size(ui_BatteryLabel, 40, 30);
    lv_label_set_text(ui_BatteryLabel, LV_SYMBOL_BATTERY_2);
    lv_obj_set_style_text_font(ui_BatteryLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsButton = lv_btn_create(panel);
    lv_obj_set_size(ui_SettingsButton, 35, 35);
    lv_obj_set_pos(ui_SettingsButton, 401, -6);
    lv_obj_set_align(ui_SettingsButton, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_opa(ui_SettingsButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsButtonLabel = lv_label_create(ui_SettingsButton);
    lv_obj_set_align(ui_SettingsButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsButtonLabel, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_align(ui_SettingsButtonLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SettingsButton, ui_event_SettingsButton, LV_EVENT_ALL, NULL);
}
void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_TEAL), lv_palette_main(LV_PALETTE_TEAL),
                                              true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Alarm_screen_init();
    ui_AnalogClock_screen_init();
    ui_DigitalClock_screen_init();
    ui_Weather_screen_init();
    lv_disp_load_scr(ui_DigitalClockScreen);
    ui_Dock_init();
}
