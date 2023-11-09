#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *lastScreen = NULL;
lv_obj_t *pressed_alarm_button = NULL;

// Settings Screen Objects
lv_obj_t *settingsScreen;
lv_obj_t *settingsPanel;
lv_obj_t *darkmodeLabel;
lv_obj_t *darkmodeSwitch;
lv_obj_t *settingsCityEdit;
lv_obj_t *settingsCityLabel;
lv_obj_t *settingsSSIDLabel;
lv_obj_t *settingsSSIDEdit;
lv_obj_t *settingsPasswordLabel;
lv_obj_t *settingsPasswordEdit;
lv_obj_t *settingsKeyboard;
lv_obj_t *settingsHomeButton;
lv_obj_t *settingsHomeButtonLabel;
lv_obj_t *settingsAPLabel;
lv_obj_t *ui_SettingsIPLabel;
lv_obj_t *brightnessSlider;
lv_obj_t *autoBrightnessCheckbox;

// Settings Screen Events
void event_SettingsPasswordEdit(lv_event_t *e);
void event_SettingsSSIDEdit(lv_event_t *e);
void event_SettingsCityEdit(lv_event_t *e);
void event_SettingsHomeButton(lv_event_t *e);
void event_SettingsKeyboard(lv_event_t *e);

// Alarm Screen Objects
lv_obj_t *alarmScreen;
lv_obj_t *alarmPanel;
lv_obj_t *ui_AlarmDummyPanel;
lv_obj_t *alarmWorkingDayLabel;
lv_obj_t *alarmWeekendDayLabel;
lv_obj_t *alarmOneOffLabel;
lv_obj_t *alarmWorkingDaySwitch;
lv_obj_t *alarmWeekendDaySwitch;
lv_obj_t *alarmOneOffSwitch;
lv_obj_t *alarmWorkingDayButton;
lv_obj_t *alarmWorkingDayButtonLabel;
lv_obj_t *alarmWeekendDayButton;
lv_obj_t *alarmWeekendDayButtonLabel;
lv_obj_t *alarmOneOffButton;
lv_obj_t *alarmOneOffButtonLabel;
lv_obj_t *alarmModalPanel;
lv_obj_t *alarmHourRoller;
lv_obj_t *alarmMinuteRoller;
lv_obj_t *alarmModalCancelButton;
lv_obj_t *alarmModalCancelButtonLabel;
lv_obj_t *alarmModalOkButton;
lv_obj_t *alarmModalOkButtonLabel;
lv_obj_t *ui_AlarmSettingsBtn;
lv_obj_t *ui_AlarmSettingsBtnLabel;
// Alarm Screen Events
void event_AlarmModalOkButton(lv_event_t *e);
void event_AlarmModalCancelButton(lv_event_t *e);
void event_AlarmScreen(lv_event_t *e);
void event_OneOffButton(lv_event_t *e);
void event_WeekendButton(lv_event_t *e);
void event_WorkingDayButton(lv_event_t *e);

// Analog Clock Objects
lv_obj_t *analogClockScreen;
lv_obj_t *analogClockPanel;
lv_obj_t *ui_ImageWatchface;
lv_obj_t *ui_ImageArmHour;
lv_obj_t *ui_ImageArmMinute;
lv_obj_t *ui_ImageArmSecond;

// Digital Clock Objects
lv_obj_t *digitalClockScreen;
lv_obj_t *digitalClockPanel;
lv_obj_t *digitalClockLabel;
lv_obj_t *digitalClockSecondLabel;
lv_obj_t *digitalClockDateLabel;
lv_obj_t *digitalClockDayLabel;
lv_obj_t *ui_DigitalClockSettingsBtn;
lv_obj_t *ui_DigitalClockSettingsBtnLabel;
// Digital Clock Events
void event_DigitalClockScreen(lv_event_t *e);

// Weather Objects
lv_obj_t *weatherScreen;
lv_obj_t *weatherPanel;
lv_obj_t *weatherImage;
lv_obj_t *weatherCity;
lv_obj_t *weatherTemperatureLabel;
lv_obj_t *weatherBriefingLabel;
lv_obj_t *weatherWindLabel;
lv_obj_t *weatherHumidityLabel;
lv_obj_t *weatherPressureLabel;
lv_obj_t *weatherFeelsLikeLabel;
lv_obj_t *weatherMaxTempLabel;
lv_obj_t *weatherMinTempLabel;
lv_obj_t *weatherRainProbabLabel;
lv_obj_t *weatherTimesLabel;
lv_obj_t *weatherThirdTempLabel;
lv_obj_t *weatherSecondTempLabel;
lv_obj_t *weatherFourthTempLabel;
lv_obj_t *weatherFirstTempLabel;

lv_obj_t *batteryLabel;
lv_obj_t *settingsButton;
lv_obj_t *settingsButtonLabel;
lv_obj_t *dockTemperatureLabel;
lv_obj_t *dockHumidityLabel;
lv_obj_t *dockWiFiLabel;
// Weather Events
void event_WeatherScreen(lv_event_t *e);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_create_settings_screen() {
  if (settingsScreen == NULL) {
    settingsScreen = lv_obj_create(NULL);
    lv_obj_add_flag(settingsScreen, LV_OBJ_FLAG_IGNORE_LAYOUT); /// Flags
    lv_obj_set_scroll_dir(settingsScreen, LV_DIR_VER);
    lv_obj_clear_flag(settingsScreen, LV_OBJ_FLAG_SCROLL_ELASTIC);

    settingsPanel = lv_obj_create(settingsScreen);
    lv_obj_set_size(settingsPanel, lv_pct(100), SETTINGS_PANEL_HEIGHT);
    lv_obj_set_style_bg_color(settingsPanel, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(settingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(settingsPanel, LV_OBJ_FLAG_SCROLL_ELASTIC);

    darkmodeLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(darkmodeLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(darkmodeLabel, 35, 15);
    lv_obj_set_align(darkmodeLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(darkmodeLabel, "Dark Mode");
    lv_obj_set_style_text_font(darkmodeLabel, &montserrat_18, LV_PART_MAIN);

    darkmodeSwitch = lv_switch_create(settingsPanel);
    lv_obj_set_size(darkmodeSwitch, 50, 25);
    lv_obj_set_pos(darkmodeSwitch, 175, 15);
    lv_obj_set_align(darkmodeSwitch, LV_ALIGN_TOP_LEFT);

    brightnessSlider = lv_slider_create(settingsPanel);
    lv_obj_align_to(brightnessSlider, darkmodeLabel, LV_ALIGN_OUT_BOTTOM_LEFT,
                    10, 35);
    lv_slider_set_range(brightnessSlider, 0, 255);

    autoBrightnessCheckbox = lv_checkbox_create(settingsPanel);
    lv_obj_align_to(autoBrightnessCheckbox, brightnessSlider,
                    LV_ALIGN_OUT_RIGHT_MID, 50, 0);
    lv_checkbox_set_text(autoBrightnessCheckbox, "Auto");

    settingsCityEdit = lv_textarea_create(settingsPanel);
    lv_obj_set_size(settingsCityEdit, 250, LV_SIZE_CONTENT); /// 33
    lv_obj_set_pos(settingsCityEdit, 180, SETTINGS_PANEL_HEIGHT / 5);
    lv_obj_set_align(settingsCityEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(settingsCityEdit, 100);
    lv_textarea_set_placeholder_text(settingsCityEdit,
                                     "City, country code ISO-81118");
    lv_textarea_set_one_line(settingsCityEdit, true);

    settingsCityLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(settingsCityLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(settingsCityLabel, 20, SETTINGS_PANEL_HEIGHT / 5);
    lv_obj_set_align(settingsCityLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(settingsCityLabel, "City and\ncountry code");
    lv_obj_set_style_text_font(settingsCityLabel, &montserrat_18,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(settingsCityLabel, LV_TEXT_ALIGN_CENTER,
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    settingsSSIDEdit = lv_textarea_create(settingsPanel);
    lv_obj_set_size(settingsSSIDEdit, 250, LV_SIZE_CONTENT);
    lv_obj_set_pos(settingsSSIDEdit, 180, SETTINGS_PANEL_HEIGHT / 5 + 60);
    lv_obj_set_align(settingsSSIDEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(settingsSSIDEdit, 50);
    lv_textarea_set_placeholder_text(settingsSSIDEdit, "WiFi SSID");
    lv_textarea_set_one_line(settingsSSIDEdit, true);

    settingsSSIDLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(settingsSSIDLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(settingsSSIDLabel, 40, SETTINGS_PANEL_HEIGHT / 5 + 70);
    lv_obj_set_align(settingsSSIDLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(settingsSSIDLabel, "WiFi SSID");
    lv_obj_set_style_text_font(settingsSSIDLabel, &montserrat_18,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    settingsPasswordEdit = lv_textarea_create(settingsPanel);
    lv_obj_set_size(settingsPasswordEdit, 250, LV_SIZE_CONTENT); /// 33
    lv_obj_set_pos(settingsPasswordEdit, 180,
                   SETTINGS_PANEL_HEIGHT / 5 + 60 * 2);
    lv_obj_set_align(settingsPasswordEdit, LV_ALIGN_TOP_LEFT);
    lv_textarea_set_max_length(settingsPasswordEdit, 100);
    lv_textarea_set_placeholder_text(settingsPasswordEdit, "WiFi Password");
    lv_textarea_set_one_line(settingsPasswordEdit, true);
    lv_textarea_set_password_mode(settingsPasswordEdit, true);

    settingsPasswordLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(settingsPasswordLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(settingsPasswordLabel, 20,
                   SETTINGS_PANEL_HEIGHT / 5 + 65 * 2);
    lv_obj_set_align(settingsPasswordLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(settingsPasswordLabel, "WiFi Password");
    lv_obj_set_style_text_font(settingsPasswordLabel, &montserrat_18,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    settingsAPLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(settingsAPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(settingsAPLabel, 80, SETTINGS_PANEL_HEIGHT - 60);
    lv_obj_set_align(settingsAPLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(settingsAPLabel, "AccessPoint IP:");
    lv_obj_set_style_text_font(settingsAPLabel, &montserrat_18,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsIPLabel = lv_label_create(settingsPanel);
    lv_obj_set_size(ui_SettingsIPLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
    lv_obj_set_pos(ui_SettingsIPLabel, 230, SETTINGS_PANEL_HEIGHT - 60);
    lv_obj_set_align(ui_SettingsIPLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_SettingsIPLabel, "192.120.12.99");
    lv_obj_set_style_text_font(ui_SettingsIPLabel, &montserrat_18,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    settingsHomeButton = lv_btn_create(settingsPanel);
    lv_obj_set_size(settingsHomeButton, 35, 35);
    lv_obj_set_pos(settingsHomeButton, 401, -6);
    lv_obj_set_align(settingsHomeButton, LV_ALIGN_TOP_LEFT);

    settingsHomeButtonLabel = lv_label_create(settingsHomeButton);
    lv_obj_set_align(settingsHomeButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(settingsHomeButtonLabel, LV_SYMBOL_HOME);
    lv_obj_set_style_text_align(settingsHomeButtonLabel, LV_TEXT_ALIGN_CENTER,
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(darkmodeSwitch, event_DarkmodeSwitch, LV_EVENT_ALL,
                        NULL);
    lv_obj_add_event_cb(settingsCityEdit, event_SettingsCityEdit, LV_EVENT_ALL,
                        NULL);
    lv_obj_add_event_cb(settingsSSIDEdit, event_SettingsSSIDEdit, LV_EVENT_ALL,
                        NULL);
    lv_obj_add_event_cb(settingsPasswordEdit, event_SettingsPasswordEdit,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(settingsHomeButton, event_SettingsHomeButton,
                        LV_EVENT_ALL, NULL);
  }
}
void ui_delete_settings_screen() {
  if (settingsScreen != NULL) {
    lv_obj_remove_event_cb(darkmodeSwitch, event_DarkmodeSwitch);
    lv_obj_remove_event_cb(settingsCityEdit, event_SettingsCityEdit);
    lv_obj_remove_event_cb(settingsSSIDEdit, event_SettingsSSIDEdit);
    lv_obj_remove_event_cb(settingsPasswordEdit, event_SettingsPasswordEdit);
    lv_obj_remove_event_cb(settingsHomeButton, event_SettingsHomeButton);
    // lv_obj_del(SettingsScreen);
    settingsScreen = NULL;
    settingsPanel = NULL;
    darkmodeLabel = NULL;
    darkmodeSwitch = NULL;
    settingsCityEdit = NULL;
    settingsCityLabel = NULL;
    settingsSSIDEdit = NULL;
    settingsSSIDLabel = NULL;
    settingsPasswordEdit = NULL;
    settingsPasswordLabel = NULL;
    settingsAPLabel = NULL;
    ui_SettingsIPLabel = NULL;
    settingsHomeButton = NULL;
    settingsHomeButtonLabel = NULL;
  }
}
void ui_create_keyboard(lv_obj_t *target) {
  if (settingsKeyboard == NULL) {
    settingsKeyboard = lv_keyboard_create(settingsScreen);
    lv_obj_set_size(settingsKeyboard, lv_pct(100), 150);
    lv_obj_set_pos(settingsKeyboard, 0, 0);
    lv_obj_set_align(settingsKeyboard, LV_ALIGN_BOTTOM_LEFT);
    lv_keyboard_set_textarea(settingsKeyboard, target);
    lv_obj_add_event_cb(settingsKeyboard, event_SettingsKeyboard, LV_EVENT_ALL,
                        NULL);
  } else {
    lv_keyboard_set_textarea(settingsKeyboard, target);
  }
}
void ui_delete_keyboard() {
  if (settingsKeyboard != NULL) {
    lv_keyboard_set_textarea(settingsKeyboard, NULL);
    lv_obj_remove_event_cb(settingsKeyboard, event_SettingsKeyboard);
    lv_obj_del(settingsKeyboard);
    lv_obj_set_height(settingsPanel, SETTINGS_PANEL_HEIGHT);
    settingsKeyboard = NULL;
  }
}
void event_SettingsHomeButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    lv_event_send(settingsKeyboard, LV_EVENT_CANCEL, NULL);
    lv_scr_load_anim(lastScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, true);
    ui_delete_settings_screen();
  }
}
void event_SettingsKeyboard(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CANCEL) {
    ui_delete_keyboard();
  }
}
void event_SettingsCityEdit(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED) {
    lv_obj_set_height(settingsPanel, SETTINGS_PANEL_HEIGHT / 4);
    lv_obj_readjust_scroll(settingsScreen, LV_ANIM_OFF);
    lv_obj_scroll_to_y(settingsPanel,
                       lv_obj_get_y(lv_event_get_current_target(e)) - 80,
                       LV_ANIM_ON);
    ui_create_keyboard(lv_event_get_current_target(e));
  }
  if (event_code == LV_EVENT_READY) {
    ui_delete_keyboard();
    lv_textarea_set_text(settingsCityEdit, "ABOBA");
  }
}
void event_SettingsSSIDEdit(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED) {
    lv_obj_set_height(settingsPanel, SETTINGS_PANEL_HEIGHT / 4);
    lv_obj_readjust_scroll(settingsScreen, LV_ANIM_OFF);
    lv_obj_scroll_to_y(settingsPanel,
                       lv_obj_get_y(lv_event_get_current_target(e)) - 80,
                       LV_ANIM_ON);
    ui_create_keyboard(lv_event_get_current_target(e));
  }
  if (event_code == LV_EVENT_READY) {
    ui_delete_keyboard();
    lv_textarea_set_text(settingsSSIDEdit, "ABOBA");
  }
}
void event_SettingsPasswordEdit(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED) {
    lv_obj_set_height(settingsPanel, SETTINGS_PANEL_HEIGHT / 4);
    lv_obj_readjust_scroll(settingsScreen, LV_ANIM_OFF);
    lv_obj_scroll_to_y(settingsPanel,
                       lv_obj_get_y(lv_event_get_current_target(e)) - 80,
                       LV_ANIM_ON);
    ui_create_keyboard(lv_event_get_current_target(e));
  }
  if (event_code == LV_EVENT_READY) {
    ui_delete_keyboard();
    lv_textarea_set_text(settingsPasswordEdit, "ABOBA");
  }
}

// Dark mode event
void event_DarkmodeSwitch(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_VALUE_CHANGED) {
    if (lv_obj_has_state(target, LV_STATE_CHECKED)) {
      lv_disp_t *dispp = lv_disp_get_default();
      lv_theme_t *theme = lv_theme_default_init(
          dispp, lv_palette_main(LV_PALETTE_CYAN),
          lv_palette_main(LV_PALETTE_NONE), false, LV_FONT_DEFAULT);
      lv_disp_set_theme(dispp, theme);
      lv_obj_set_style_text_color(settingsButtonLabel, lv_color_black(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_opa(settingsButton, 0,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_opa(alarmWorkingDayButton, 0,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_opa(alarmWeekendDayButton, 0,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_opa(alarmOneOffButton, 0,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmWorkingDayButtonLabel, lv_color_black(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmWeekendDayButtonLabel, lv_color_black(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmOneOffButtonLabel, lv_color_black(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
      lv_disp_t *dispp = lv_disp_get_default();
      lv_theme_t *theme = lv_theme_default_init(
          dispp, lv_palette_main(LV_PALETTE_TEAL),
          lv_palette_main(LV_PALETTE_TEAL), true, LV_FONT_DEFAULT);
      lv_disp_set_theme(dispp, theme);
      lv_obj_set_style_text_color(settingsButtonLabel, lv_color_white(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmWorkingDayButtonLabel, lv_color_white(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmWeekendDayButtonLabel, lv_color_white(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(alarmOneOffButtonLabel, lv_color_white(),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }
}
void parse_alarm_label(char *string, int pos, char *buff) {
  for (size_t i = 0; i < 2; i++) {
    buff[i] = string[i + pos];
  }
}
void ui_set_roller_time(const lv_obj_t *label) {
  char alarm_buff[2];
  parse_alarm_label(lv_label_get_text(label), HOUR_LABEL, alarm_buff);
  lv_roller_set_selected(alarmHourRoller, atoi(alarm_buff), LV_ANIM_OFF);
  parse_alarm_label(lv_label_get_text(label), MINUTE_LABEL, alarm_buff);
  lv_roller_set_selected(alarmMinuteRoller, atoi(alarm_buff), LV_ANIM_OFF);
}
void ui_create_alarm_modal_panel(lv_obj_t *target_label) {

  if (alarmModalPanel == NULL) {
    char hour_count[HOUR_COUNT * 3] = {0};
    char hour_buffer[4] = {0};
    char minute_count[MINUTE_COUNT * 3] = {0};
    char minute_buffer[3] = {0};
    ui_AlarmDummyPanel = lv_obj_create(alarmScreen);
    lv_obj_set_size(ui_AlarmDummyPanel, 480, 320);
    lv_obj_set_align(ui_AlarmDummyPanel, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_opa(ui_AlarmDummyPanel, 200,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    alarmModalPanel = lv_obj_create(ui_AlarmDummyPanel);
    lv_obj_set_size(alarmModalPanel, 250, 230);
    lv_obj_set_align(alarmModalPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(alarmModalPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    for (short int i = 0; i < HOUR_COUNT; i++) {
      if (i == HOUR_COUNT - 1) {
        sprintf(hour_buffer, "%2i", i);
      } else {
        sprintf(hour_buffer, "%02i\n", i);
      }
      strcat(hour_count, hour_buffer);
    }
    for (short int i = 0; i < MINUTE_COUNT; i++) {
      if (i == MINUTE_COUNT - 1) {
        sprintf(minute_buffer, "%02i", i);
      } else {
        sprintf(minute_buffer, "%02i\n", i);
      }
      strcat(minute_count, minute_buffer);
    }
    alarmHourRoller = lv_roller_create(alarmModalPanel);
    lv_roller_set_options(alarmHourRoller, hour_count, LV_ROLLER_MODE_INFINITE);
    lv_obj_set_size(alarmHourRoller, 90, 110);
    lv_obj_set_pos(alarmHourRoller, -50, -35);
    lv_obj_set_align(alarmHourRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(alarmHourRoller, &montserrat_18, LV_PART_MAIN);

    alarmMinuteRoller = lv_roller_create(alarmModalPanel);
    lv_roller_set_options(alarmMinuteRoller, minute_count,
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_size(alarmMinuteRoller, 90, 110);
    lv_obj_align_to(alarmMinuteRoller, alarmHourRoller, LV_ALIGN_BOTTOM_LEFT,
                    83, 18);
    lv_obj_set_style_text_font(alarmMinuteRoller, &montserrat_18, LV_PART_MAIN);

    alarmModalCancelButton = lv_btn_create(alarmModalPanel);
    lv_obj_set_size(alarmModalCancelButton, 90, 45);
    lv_obj_set_pos(alarmModalCancelButton, 13, 0);
    lv_obj_set_align(alarmModalCancelButton, LV_ALIGN_BOTTOM_LEFT);

    alarmModalCancelButtonLabel = lv_label_create(alarmModalCancelButton);
    lv_obj_set_size(alarmModalCancelButtonLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(alarmModalCancelButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(alarmModalCancelButtonLabel, "Cancel");
    lv_obj_set_style_text_font(alarmModalCancelButtonLabel, &montserrat_18,
                               LV_PART_MAIN);

    alarmModalOkButton = lv_btn_create(alarmModalPanel);
    lv_obj_set_size(alarmModalOkButton, 90, 45);
    lv_obj_align_to(alarmModalOkButton, alarmModalCancelButton,
                    LV_ALIGN_BOTTOM_LEFT, 85, 10);

    alarmModalOkButtonLabel = lv_label_create(alarmModalOkButton);
    lv_obj_set_size(alarmModalOkButtonLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(alarmModalOkButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(alarmModalOkButtonLabel, "OK");
    lv_obj_set_style_text_font(alarmModalOkButtonLabel, &montserrat_18,
                               LV_PART_MAIN);

    lv_obj_add_event_cb(alarmModalCancelButton, event_AlarmModalCancelButton,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(alarmModalOkButton, event_AlarmModalOkButton,
                        LV_EVENT_ALL, target_label);

    ui_set_roller_time(target_label);
  }
}
void ui_delete_alarm_modal_panel() {
  if (ui_AlarmDummyPanel != NULL) {
    lv_obj_remove_event_cb(alarmModalCancelButton,
                           event_AlarmModalCancelButton);
    lv_obj_remove_event_cb(alarmModalOkButton, event_AlarmModalOkButton);
    lv_obj_del(ui_AlarmDummyPanel);
    ui_AlarmDummyPanel = NULL;
    alarmModalPanel = NULL;
    alarmHourRoller = NULL;
    alarmMinuteRoller = NULL;
    alarmModalCancelButton = NULL;
    alarmModalCancelButtonLabel = NULL;
    alarmModalOkButton = NULL;
    alarmModalOkButtonLabel = NULL;
  }
}
void event_WorkingDayButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    ui_create_alarm_modal_panel(alarmWorkingDayButtonLabel);
  }
}
void event_WeekendButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    ui_create_alarm_modal_panel(alarmWeekendDayButtonLabel);
  }
}

void event_OneOffButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    ui_create_alarm_modal_panel(alarmOneOffButtonLabel);
  }
}
void event_AlarmModalCancelButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    ui_delete_alarm_modal_panel();
  }
}
void event_AlarmModalOkButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    lv_label_set_text_fmt(e->user_data, "%02i:%02i",
                          lv_roller_get_selected(alarmHourRoller),
                          lv_roller_get_selected(alarmMinuteRoller));
    ui_delete_alarm_modal_panel();
  }
}

void dock_change_parent(lv_obj_t *screen) {
  lv_obj_set_parent(settingsButton, lv_obj_get_child(screen, 0));
  lv_obj_set_parent(batteryLabel, lv_obj_get_child(screen, 0));
  lv_obj_set_parent(dockHumidityLabel, lv_obj_get_child(screen, 0));
  lv_obj_set_parent(dockTemperatureLabel, lv_obj_get_child(screen, 0));
  lv_obj_set_parent(dockWiFiLabel, lv_obj_get_child(screen, 0));
}
// Screen change on GESTURES
void event_AlarmScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_GESTURE &&
      lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
    ui_screen_change(analogClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    dock_change_parent(analogClockScreen);
  }
}
void event_DigitalClockScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_GESTURE &&
      lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
    ui_screen_change(weatherScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    dock_change_parent(weatherScreen);
  } else if (event_code == LV_EVENT_GESTURE &&
             lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
    ui_screen_change(analogClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    dock_change_parent(analogClockScreen);
  }
}
void event_WeatherScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_GESTURE &&
      lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
    ui_screen_change(digitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    dock_change_parent(digitalClockScreen);
  }
}

void event_AnalogClockScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_GESTURE &&
      lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
    ui_screen_change(digitalClockScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    dock_change_parent(digitalClockScreen);
  } else if (event_code == LV_EVENT_GESTURE &&
             lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
    ui_screen_change(alarmScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    dock_change_parent(alarmScreen);
  }
}

// Screen change on Button
void screen_load_event_cb(lv_event_t *e) {
  // if(settingsScreen != NULL){
  // lv_obj_del(settingsScreen);
  // }
}
void event_SettingsButton(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    lastScreen = lv_scr_act();
    ui_create_settings_screen();
    ui_screen_change(settingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
  }
}

void ui_event_WeatherSettingsBtn(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    lastScreen = lv_event_get_user_data(e);
    ui_screen_change(settingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
  }
}

///////////////////// SCREENS INIT////////////////////
// ALARM SCREEN INIT
void alarm_screen_init(void) {
  alarmScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(alarmScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  alarmPanel = lv_obj_create(alarmScreen);
  lv_obj_set_size(alarmPanel, lv_pct(100), lv_pct(100));
  lv_obj_set_pos(alarmPanel, 1, -1);
  lv_obj_set_align(alarmPanel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(alarmPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_bg_color(alarmPanel, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(alarmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  alarmWorkingDayLabel = lv_label_create(alarmPanel);
  lv_obj_set_size(alarmWorkingDayLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(alarmWorkingDayLabel, 10, 65);
  lv_obj_set_align(alarmWorkingDayLabel, LV_ALIGN_TOP_LEFT);
  lv_label_set_text(alarmWorkingDayLabel, "По будням");
  lv_obj_set_style_text_font(alarmWorkingDayLabel, &montserrat_18,
                             LV_PART_MAIN);

  alarmWorkingDayButton = lv_btn_create(alarmPanel);
  lv_obj_set_size(alarmWorkingDayButton, 70, 41);
  lv_obj_align_to(alarmWorkingDayButton, alarmWorkingDayLabel,
                  LV_ALIGN_BOTTOM_LEFT, 270, 10);
  lv_obj_set_style_bg_opa(alarmWorkingDayButton, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);

  alarmWorkingDayButtonLabel = lv_label_create(alarmWorkingDayButton);
  lv_obj_set_size(alarmWorkingDayButtonLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(alarmWorkingDayButtonLabel, LV_ALIGN_CENTER);
  lv_label_set_text(alarmWorkingDayButtonLabel, "08:15");
  lv_obj_set_style_text_font(alarmWorkingDayButtonLabel, &montserrat_18,
                             LV_PART_MAIN);

  alarmWorkingDaySwitch = lv_switch_create(alarmPanel);
  lv_obj_set_size(alarmWorkingDaySwitch, 50, 25);
  lv_obj_align_to(alarmWorkingDaySwitch, alarmWorkingDayButton,
                  LV_ALIGN_BOTTOM_LEFT, 80, 5);

  alarmWeekendDayLabel = lv_label_create(alarmPanel);
  lv_obj_set_size(alarmWeekendDayLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_align_to(alarmWeekendDayLabel, alarmWorkingDayLabel,
                  LV_ALIGN_OUT_BOTTOM_LEFT, 0, 40);
  lv_label_set_text(alarmWeekendDayLabel, "СБ ВС");
  lv_obj_set_style_text_font(alarmWeekendDayLabel, &montserrat_18,
                             LV_PART_MAIN);

  alarmWeekendDayButton = lv_btn_create(alarmPanel);
  lv_obj_set_size(alarmWeekendDayButton, 70, 41);
  lv_obj_align_to(alarmWeekendDayButton, alarmWorkingDayButton,
                  LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
  lv_obj_set_style_bg_opa(alarmWeekendDayButton, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(alarmWeekendDayButton, &montserrat_18,
                             LV_PART_MAIN);

  alarmWeekendDayButtonLabel = lv_label_create(alarmWeekendDayButton);
  lv_obj_set_size(alarmWeekendDayButtonLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(alarmWeekendDayButtonLabel, LV_ALIGN_CENTER);
  lv_label_set_text(alarmWeekendDayButtonLabel, "15:23");
  lv_obj_set_style_text_font(alarmWeekendDayButtonLabel, &montserrat_18,
                             LV_PART_MAIN);

  alarmWeekendDaySwitch = lv_switch_create(alarmPanel);
  lv_obj_set_size(alarmWeekendDaySwitch, 50, 25);
  lv_obj_align_to(alarmWeekendDaySwitch, alarmWorkingDaySwitch,
                  LV_ALIGN_OUT_BOTTOM_MID, 0, 35);

  alarmOneOffLabel = lv_label_create(alarmPanel);
  lv_obj_set_size(alarmOneOffLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
  lv_obj_align_to(alarmOneOffLabel, alarmWeekendDayLabel,
                  LV_ALIGN_OUT_BOTTOM_LEFT, 0, 40);
  lv_label_set_text(alarmOneOffLabel, "Однократно");
  lv_obj_set_style_text_font(alarmOneOffLabel, &montserrat_18, LV_PART_MAIN);

  alarmOneOffButton = lv_btn_create(alarmPanel);
  lv_obj_set_size(alarmOneOffButton, 70, 41);
  lv_obj_align_to(alarmOneOffButton, alarmWeekendDayButton,
                  LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
  lv_obj_set_style_bg_opa(alarmOneOffButton, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);

  alarmOneOffButtonLabel = lv_label_create(alarmOneOffButton);
  lv_obj_set_size(alarmOneOffButtonLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(alarmOneOffButtonLabel, LV_ALIGN_CENTER);
  lv_label_set_text(alarmOneOffButtonLabel, "12:03");
  lv_obj_set_style_text_font(alarmOneOffButtonLabel, &montserrat_18,
                             LV_PART_MAIN);

  alarmOneOffSwitch = lv_switch_create(alarmPanel);
  lv_obj_set_size(alarmOneOffSwitch, 50, 25);
  lv_obj_align_to(alarmOneOffSwitch, alarmWeekendDaySwitch,
                  LV_ALIGN_OUT_BOTTOM_MID, 0, 35);

  lv_obj_add_event_cb(alarmWorkingDayButton, event_WorkingDayButton,
                      LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(alarmWeekendDayButton, event_WeekendButton, LV_EVENT_ALL,
                      NULL);
  lv_obj_add_event_cb(alarmOneOffButton, event_OneOffButton, LV_EVENT_ALL,
                      NULL);
  lv_obj_add_event_cb(alarmScreen, event_AlarmScreen, LV_EVENT_ALL, NULL);
}

void analogClock_screen_init(void) {
  analogClockScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(analogClockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  analogClockPanel = lv_obj_create(analogClockScreen);
  lv_obj_set_size(analogClockPanel, lv_pct(100), lv_pct(100));
  lv_obj_set_align(analogClockPanel, LV_ALIGN_TOP_LEFT);
  lv_obj_clear_flag(analogClockPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_bg_color(analogClockPanel, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(analogClockPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_ImageWatchface = lv_img_create(analogClockScreen);
  lv_img_set_src(ui_ImageWatchface, &ui_img_watchface240_png);
  lv_obj_set_width(ui_ImageWatchface, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_ImageWatchface, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_ImageWatchface, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_ImageWatchface, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
  lv_obj_clear_flag(ui_ImageWatchface, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  ui_ImageArmHour = lv_img_create(analogClockScreen);
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

  ui_ImageArmMinute = lv_img_create(analogClockScreen);
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

  ui_ImageArmSecond = lv_img_create(analogClockScreen);
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

  lv_obj_add_event_cb(analogClockScreen, event_AnalogClockScreen, LV_EVENT_ALL,
                      NULL);
}
// DIGITAL CLOCK SCREEN INIT
void digitalClock_screen_init(void) {
  digitalClockScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(digitalClockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  digitalClockPanel = lv_obj_create(digitalClockScreen);
  lv_obj_set_size(digitalClockPanel, lv_pct(100), lv_pct(100));
  lv_obj_set_style_bg_color(digitalClockPanel, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(digitalClockPanel, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_align(digitalClockPanel, LV_ALIGN_TOP_LEFT);
  lv_obj_clear_flag(digitalClockPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  digitalClockLabel = lv_label_create(digitalClockPanel);
  lv_obj_set_size(digitalClockLabel, 320, 100);
  lv_obj_set_pos(digitalClockLabel, 0, -30);
  lv_obj_set_align(digitalClockLabel, LV_ALIGN_CENTER);
  lv_label_set_text(digitalClockLabel, "00:00");

  lv_obj_set_style_text_align(digitalClockLabel, LV_TEXT_ALIGN_LEFT,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(digitalClockLabel, &font_Roboto120,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  digitalClockSecondLabel = lv_label_create(digitalClockPanel);
  lv_obj_set_size(digitalClockSecondLabel, 60, 40);
  lv_obj_align_to(digitalClockSecondLabel, digitalClockLabel,
                  LV_ALIGN_BOTTOM_RIGHT, 50, -3);
  lv_label_set_text(digitalClockSecondLabel, "00");
  lv_obj_set_style_text_align(digitalClockSecondLabel, LV_TEXT_ALIGN_LEFT,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(digitalClockSecondLabel, &font_Roboto45,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  digitalClockDateLabel = lv_label_create(digitalClockPanel);
  lv_obj_set_size(digitalClockDateLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(digitalClockDateLabel, 0, 80);
  lv_obj_set_align(digitalClockDateLabel, LV_ALIGN_CENTER);
  lv_label_set_text(digitalClockDateLabel, "04.05.2023");
  lv_obj_set_style_text_align(digitalClockDateLabel, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(digitalClockDateLabel, &montserrat_32,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  digitalClockDayLabel = lv_label_create(digitalClockPanel);
  lv_obj_set_size(digitalClockDayLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  // lv_obj_set_pos(digitalClockDayLabel, 0, 115);
  lv_obj_align_to(digitalClockDayLabel, digitalClockDateLabel,
                  LV_ALIGN_OUT_RIGHT_MID, 10, -10);
  lv_label_set_text(digitalClockDayLabel, "Вс");
  lv_obj_set_style_text_align(digitalClockDayLabel, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(digitalClockDayLabel, &montserrat_32,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_event_cb(digitalClockScreen, screen_load_event_cb,
                      LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(digitalClockScreen, event_DigitalClockScreen,
                      LV_EVENT_ALL, NULL);
}
void weather_screen_init(void) {
  weatherScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(weatherScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  weatherPanel = lv_obj_create(weatherScreen);
  lv_obj_set_size(weatherPanel, lv_pct(100), lv_pct(100));
  lv_obj_set_pos(weatherPanel, 0, 0);
  lv_obj_set_align(weatherPanel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(weatherPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_bg_color(weatherPanel, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(weatherPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherImage = lv_img_create(weatherPanel);
  lv_img_set_src(weatherImage, &ui_img_day_rain_png);
  lv_obj_set_pos(weatherImage, 10, 30);
  lv_obj_set_align(weatherImage, LV_ALIGN_TOP_LEFT); /// Flags

  weatherCity = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherCity, 200, LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(weatherCity, 20, 35);
  lv_obj_set_align(weatherCity, LV_ALIGN_TOP_MID);
  lv_label_set_long_mode(weatherCity, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_label_set_text(weatherCity, "Saint-Petersburg, Russia");
  lv_obj_set_style_text_font(weatherCity, &montserrat_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherWindLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherWindLabel, WIND_SYMBOL" %.1f км/ч " SW_WIND_SYMBOL, 15.1);
  lv_obj_set_style_text_font(weatherWindLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_pos(weatherWindLabel, 150, -40);
  lv_obj_set_align(weatherWindLabel, LV_ALIGN_CENTER);


  weatherTemperatureLabel = lv_label_create(weatherPanel);
  lv_obj_set_pos(weatherTemperatureLabel, 20, -45);
  lv_obj_set_align(weatherTemperatureLabel, LV_ALIGN_CENTER);
  lv_label_set_text(weatherTemperatureLabel, "-13°C");
  lv_obj_set_style_text_font(weatherTemperatureLabel, &montserrat_48,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherFeelsLikeLabel = lv_label_create(weatherPanel);
  lv_obj_set_pos(weatherFeelsLikeLabel, 40, 5);
  lv_obj_set_align(weatherFeelsLikeLabel, LV_ALIGN_CENTER);
  lv_label_set_text(weatherFeelsLikeLabel, "Ощущается как: -24°C");
  lv_obj_set_style_text_font(weatherFeelsLikeLabel, &montserrat_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherBriefingLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherBriefingLabel, 320,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(weatherBriefingLabel, 0, 35);
  lv_obj_set_align(weatherBriefingLabel, LV_ALIGN_CENTER);
  lv_label_set_long_mode(weatherBriefingLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_label_set_text(weatherBriefingLabel,
                    "Переменная облачность. Возможен дождь.");
  lv_obj_set_style_text_font(weatherBriefingLabel, &montserrat_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherMaxTempLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherMaxTempLabel, TEMP_UP_SYMBOL" %d°C", -8);
  lv_obj_set_style_text_font(weatherMaxTempLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_pos(weatherMaxTempLabel, -170, 65);
  lv_obj_set_align(weatherMaxTempLabel, LV_ALIGN_CENTER);


  weatherMinTempLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherMinTempLabel, TEMP_DOWN_SYMBOL" %d°C", -19);
  lv_obj_set_style_text_font(weatherMinTempLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(weatherMinTempLabel, weatherMaxTempLabel,
                  LV_ALIGN_OUT_RIGHT_MID, 15, -1);


  weatherRainProbabLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherRainProbabLabel, SNOWFLAKE_SYMBOL" %d%%", 53);
  lv_obj_set_style_text_font(weatherRainProbabLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(weatherRainProbabLabel, weatherMinTempLabel,
                  LV_ALIGN_OUT_RIGHT_MID, 15, -1);

  weatherHumidityLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherHumidityLabel, HUMIDITY_SYMBOL" %d%%", 76);
  lv_obj_set_style_text_font(weatherHumidityLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(weatherHumidityLabel, weatherRainProbabLabel, LV_ALIGN_OUT_RIGHT_MID, 15, -1);


  weatherPressureLabel = lv_label_create(weatherPanel);
  lv_label_set_text_fmt(weatherPressureLabel, PRESSURE_SYMBOL" %d мбар", 1027);
  lv_obj_set_style_text_font(weatherPressureLabel, &weather_icon_font_full_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align_to(weatherPressureLabel, weatherHumidityLabel,
                  LV_ALIGN_OUT_RIGHT_MID, 15, -1);

  weatherTimesLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherTimesLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(weatherTimesLabel, 0, 93);
  lv_obj_set_align(weatherTimesLabel, LV_ALIGN_CENTER);
  lv_label_set_text(
      weatherTimesLabel,
      "Ночь               Утро               День               Вечер");
  lv_obj_set_style_text_font(weatherTimesLabel, &montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  weatherFirstTempLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherFirstTempLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_set_pos(weatherFirstTempLabel, 55, -10);
  lv_obj_set_align(weatherFirstTempLabel, LV_ALIGN_BOTTOM_LEFT);
  lv_label_set_text(weatherFirstTempLabel, "-7°C");

  weatherSecondTempLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherSecondTempLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_align_to(weatherSecondTempLabel, weatherFirstTempLabel,
                  LV_ALIGN_OUT_RIGHT_TOP, 65, 0);
  lv_label_set_text(weatherSecondTempLabel, "-10°C");

  weatherThirdTempLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherThirdTempLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_align_to(weatherThirdTempLabel, weatherSecondTempLabel,
                  LV_ALIGN_OUT_RIGHT_TOP, 65, 0);
  lv_label_set_text(weatherThirdTempLabel, "-13°C");

  weatherFourthTempLabel = lv_label_create(weatherPanel);
  lv_obj_set_size(weatherFourthTempLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT); /// 1
  lv_obj_align_to(weatherFourthTempLabel, weatherThirdTempLabel,
                  LV_ALIGN_OUT_RIGHT_TOP, 65, 0);
  lv_label_set_text(weatherFourthTempLabel, "-18°C");

  lv_obj_add_event_cb(weatherScreen, event_WeatherScreen, LV_EVENT_ALL, NULL);
}
void dock_init() {

  lv_obj_t *panel = lv_obj_get_child(lv_scr_act(), 0);
  batteryLabel = lv_label_create(panel);
  lv_obj_set_pos(batteryLabel, 10, 0);
  lv_obj_set_align(batteryLabel, LV_ALIGN_TOP_LEFT);
  lv_obj_set_size(batteryLabel, 40, 30);
  lv_label_set_text(batteryLabel, LV_SYMBOL_BATTERY_2);
  lv_obj_set_style_text_font(batteryLabel, &lv_font_montserrat_20,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  dockWiFiLabel = lv_label_create(panel);
  lv_obj_set_pos(dockWiFiLabel, 45, 0);
  lv_obj_set_align(dockWiFiLabel, LV_ALIGN_TOP_LEFT);
  lv_obj_set_size(dockWiFiLabel, 40, 30);
  lv_label_set_text(dockWiFiLabel, WIFI_CONNECTED_SYMBOL);
  lv_obj_set_style_text_font(dockWiFiLabel, &wifi_symbols_20,
                             LV_PART_MAIN | LV_STATE_DEFAULT);


  dockTemperatureLabel = lv_label_create(panel);
  lv_obj_set_pos(dockTemperatureLabel, 75, 0);
  lv_obj_set_align(dockTemperatureLabel, LV_ALIGN_TOP_LEFT);
  lv_obj_set_size(dockTemperatureLabel, 60, 30);
  lv_label_set_text(dockTemperatureLabel, "20 °C");
  lv_obj_set_style_text_font(dockTemperatureLabel, &lv_font_montserrat_20,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  dockHumidityLabel = lv_label_create(panel);
  lv_obj_set_pos(dockHumidityLabel, 135, 0);
  lv_obj_set_align(dockHumidityLabel, LV_ALIGN_TOP_LEFT);
  lv_obj_set_size(dockHumidityLabel, 60, 30);
  lv_label_set_text(dockHumidityLabel, "80%");
  lv_obj_set_style_text_font(dockHumidityLabel, &lv_font_montserrat_20,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  settingsButton = lv_btn_create(panel);
  lv_obj_set_size(settingsButton, 35, 35);
  lv_obj_set_pos(settingsButton, 401, -6);
  lv_obj_set_align(settingsButton, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_bg_opa(settingsButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  settingsButtonLabel = lv_label_create(settingsButton);
  lv_obj_set_align(settingsButtonLabel, LV_ALIGN_CENTER);
  lv_label_set_text(settingsButtonLabel, LV_SYMBOL_SETTINGS);
  lv_obj_set_style_text_align(settingsButtonLabel, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);



  lv_obj_add_event_cb(settingsButton, event_SettingsButton, LV_EVENT_ALL, NULL);
}
void ui_init(void) {
  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(
      dispp, lv_palette_main(LV_PALETTE_TEAL), lv_palette_main(LV_PALETTE_TEAL),
      true, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  alarm_screen_init();
  analogClock_screen_init();
  digitalClock_screen_init();
  weather_screen_init();
  lv_disp_load_scr(digitalClockScreen);
  dock_init();
}
