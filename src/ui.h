// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: OverEClocks

#ifndef _OVERECLOCKS_UI_H
#define _OVERECLOCKS_UI_H

#ifdef __cplusplus
extern "C" {
#endif
#define SETTINGS_PANEL_HEIGHT 640
#define HOUR_COUNT 24
#define MINUTE_COUNT 60
#define HOUR_LABEL 0
#define MINUTE_LABEL 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lvgl.h"
#include "ui_events.h"

// Settings Screen Objects
extern lv_obj_t *settingsScreen;
extern lv_obj_t *settingsPanel;
extern lv_obj_t *darkmodeLabel;
extern lv_obj_t *darkmodeSwitch;
extern lv_obj_t *settingsCityEdit;
extern lv_obj_t *settingsCityLabel;
extern lv_obj_t *settingsSSIDLabel;
extern lv_obj_t *settingsSSIDEdit;
extern lv_obj_t *settingsPasswordLabel;
extern lv_obj_t *settingsPasswordEdit;
extern lv_obj_t *settingsKeyboard;
extern lv_obj_t *settingsHomeButton;
extern lv_obj_t *settingsHomeButtonLabel;
extern lv_obj_t *settingsAPLabel;
extern lv_obj_t *brightnessSlider;
extern lv_obj_t *autoBrightnessCheckbox;

// Settings Screen Events
void event_SettingsPasswordEdit(lv_event_t *e);
void event_SettingsSSIDEdit(lv_event_t *e);
void event_SettingsCityEdit(lv_event_t *e);
void event_DarkmodeSwitch(lv_event_t *e);
void event_SettingsHomeButton(lv_event_t *e);
void event_SettingsKeyboard(lv_event_t *e);

// Alarm Screen Objects
extern lv_obj_t *alarmScreen;
extern lv_obj_t *alarmPanel;
extern lv_obj_t *alarmWorkingDayLabel;
extern lv_obj_t *alarmWeekendDayLabel;
extern lv_obj_t *alarmOneOffLabel;
extern lv_obj_t *alarmWorkingDaySwitch;
extern lv_obj_t *alarmWeekendDaySwitch;
extern lv_obj_t *alarmOneOffSwitch;
extern lv_obj_t *alarmWorkingDayButton;
extern lv_obj_t *alarmWorkingDayButtonLabel;
extern lv_obj_t *alarmWeekendDayButton;
extern lv_obj_t *alarmWeekendDayButtonLabel;
extern lv_obj_t *alarmOneOffButton;
extern lv_obj_t *alarmOneOffButtonLabel;
extern lv_obj_t *alarmModalPanel;
extern lv_obj_t *alarmHourRoller;
extern lv_obj_t *alarmMinuteRoller;
extern lv_obj_t *alarmModalCancelButton;
extern lv_obj_t *alarmModalCancelButtonLabel;
extern lv_obj_t *alarmModalOkButton;
extern lv_obj_t *alarmModalOkButtonLabel;

// Alarm Screen Events
void event_AlarmModalOkButton(lv_event_t *e);
void event_AlarmModalCancelButton(lv_event_t *e);
void event_OneOffButton(lv_event_t *e);
void event_WeekendButton(lv_event_t *e);
void event_WorkingDayButton(lv_event_t *e);
void event_AlarmScreen(lv_event_t *e);

// Analog Clock Objects
extern lv_obj_t *analogClockScreen;
extern lv_obj_t *analogClockPanel;
extern lv_obj_t *ui_ImageWatchface;
extern lv_obj_t *ui_ImageArmHour;
extern lv_obj_t *ui_ImageArmMinute;
extern lv_obj_t *ui_ImageArmSecond;
// Analog Clock Events
void event_AnalogClockScreen(lv_event_t *e);

// Digital Clock Objects
extern lv_obj_t *digitalClockScreen;
extern lv_obj_t *digitalClockPanel;
extern lv_obj_t *digitalClockLabel;
extern lv_obj_t *digitalClockSecondLabel;
extern lv_obj_t *digitalClockDateLabel;
extern lv_obj_t *digitalClockDayLabel;
// Digital Clock Events
void event_DigitalClockScreen(lv_event_t *e);

// Weather Clock Objects
extern lv_obj_t *weatherScreen;
extern lv_obj_t *weatherPanel;
extern lv_obj_t *weatherImage;
extern lv_obj_t *weatherCity;
extern lv_obj_t *weatherTemperatureLabel;
extern lv_obj_t *weatherBriefingLabel;
extern lv_obj_t *weatherWindLabel;
extern lv_obj_t *weatherHumidityLabel;
extern lv_obj_t *weatherPressureLabel;
extern lv_obj_t *weatherFeelsLikeLabel;
extern lv_obj_t *weatherTimesLabel;
extern lv_obj_t *weatherMaxTempLabel;
extern lv_obj_t *weatherMinTempLabel;
extern lv_obj_t *weatherRainProbabLabel;
extern lv_obj_t *weatherFirstTempLabel;
extern lv_obj_t *weatherSecondTempLabel;
extern lv_obj_t *weatherThirdTempLabel;
extern lv_obj_t *weatherFourthTempLabel;

extern lv_obj_t *batteryLabel;
extern lv_obj_t *settingsButton;
extern lv_obj_t *settingsButtonLabel;
// Weather Clock Events
void event_WeatherScreen(lv_event_t *e);

void event_SettingsButton(lv_event_t *e);

void create_battery_label(lv_obj_t *screen);

LV_IMG_DECLARE(ui_img_watchface240_png);
LV_IMG_DECLARE(ui_img_armhour_png);
LV_IMG_DECLARE(ui_img_armminute_png);
LV_IMG_DECLARE(ui_img_armsecond_png);
// LV_IMG_DECLARE(ui_img_day_rain_png);
LV_IMG_DECLARE(ui_img_day_clear_png);

LV_FONT_DECLARE(montserrat_32);
LV_FONT_DECLARE(montserrat_18);
LV_FONT_DECLARE(montserrat_14);
LV_FONT_DECLARE(montserrat_12);
LV_FONT_DECLARE(montserrat_48);
LV_FONT_DECLARE(ui_font_Roboto120);
LV_FONT_DECLARE(ui_font_Roboto45);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
