// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: OverEClocks

#ifndef _OVERECLOCKS_UI_H
#define _OVERECLOCKS_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_events.h"
// Settings Screen Objects
extern lv_obj_t * ui_SettingsScreen;
extern lv_obj_t * ui_SettingsPanel;
extern lv_obj_t * ui_DarkmodeLabel;
extern lv_obj_t * ui_DarkmodeSwitch;
extern lv_obj_t * ui_SettingsCityEdit;
extern lv_obj_t * ui_SettingsCityLabel;
extern lv_obj_t * ui_SettingsSSIDLabel;
extern lv_obj_t * ui_SettingsSSIDEdit;
extern lv_obj_t * ui_SettingsPasswordLabel;
extern lv_obj_t * ui_SettingsPasswordEdit;
extern lv_obj_t * ui_SettingsKeyboard;
extern lv_obj_t * ui_SettingsHomeBtn;
extern lv_obj_t * ui_SettingsHomeBtnLabel;
extern lv_obj_t * ui_SettingsAPLabel;
extern lv_obj_t * ui_SettingsIPLabel;
//Settings Screen Events
void ui_event_SettingsPasswordEdit(lv_event_t * e);
void ui_event_SettingsSSIDEdit(lv_event_t * e);
void ui_event_SettingsCityEdit(lv_event_t * e);
void ui_event_DarkmodeSwitch(lv_event_t * e);
void ui_event_SettingsHomeBtn(lv_event_t * e);
void ui_event_SettingsKeyboard(lv_event_t * e);

// Alarm Screen Objects
extern lv_obj_t * ui_AlarmScreen;
extern lv_obj_t * ui_AlarmPanel;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_Switch2;
extern lv_obj_t * ui_Switch3;
extern lv_obj_t * ui_Button6;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label7;
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_AlarmModalPanel;
extern lv_obj_t * ui_AlarmHourRoller;
extern lv_obj_t * ui_AlarmMinuteRoller;
extern lv_obj_t * ui_AlarmModalCancelButton;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_AlarmModalOkButton;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_AlarmSettingsBtn;
extern lv_obj_t * ui_AlarmSettingsBtnLabel;
// Alarm Screen Events
void ui_event_AlarmModalOkButton(lv_event_t * e);
void ui_event_AlarmModalCancelButton(lv_event_t * e);
void ui_event_Button4(lv_event_t * e);
void ui_event_Button1(lv_event_t * e);
void ui_event_Button6(lv_event_t * e);
void ui_event_AlarmScreen(lv_event_t * e);


// Analog Clock Objects
extern lv_obj_t * ui_AnalogClockScreen;
extern lv_obj_t * ui_AnalogPanel;
extern lv_obj_t * ui_AnalogSettingsBtn;
extern lv_obj_t * ui_AnalogMeter;
extern lv_obj_t * ui_AnalogSettingsLabel;
// Analog Clock Events
void ui_event_AnalogClockScreen(lv_event_t * e);
void ui_event_AnalogSettingsBtn(lv_event_t * e);

// Digital Clock Objects
extern lv_obj_t * ui_DigitalClockScreen;
extern lv_obj_t * ui_DigitalClockPanel;
extern lv_obj_t * ui_DigitalClockLabel;
extern lv_obj_t * ui_DigitalClockSecondLabel;
extern lv_obj_t * ui_DigitalClockDateLabel;
extern lv_obj_t * ui_DigitalClockSettingsBtn;
extern lv_obj_t * ui_DigitalClockSettingsBtnLabel;
// Digital Clock Events
void ui_event_DigitalClockScreen(lv_event_t * e);
void ui_event_DigitalClockSettingsBtn(lv_event_t * e);

// Weather Clock Objects
extern lv_obj_t * ui_Weather;
extern lv_obj_t * ui_WeatherPanel;
extern lv_obj_t * ui_WeatherImage;
extern lv_obj_t * ui_WeatherCity;
extern lv_obj_t * ui_WeatherTemperatureLbl;
extern lv_obj_t * ui_WeatherBriefingLbl;
extern lv_obj_t * ui_WeatherParamsLabel;
extern lv_obj_t * ui_WeatherTimesLbl;
extern lv_obj_t * ui_WeatherFirstTempLbl;
extern lv_obj_t * ui_WeatherSecondTempLbl;
extern lv_obj_t * ui_WeatherThirdTempLbl;
extern lv_obj_t * ui_WeatherFourthTempLbl;
extern lv_obj_t * ui_Label13;
// Weather Clock Events
void ui_event_Weather(lv_event_t * e);


LV_IMG_DECLARE(ui_img_day_rain_png);    // assets\day_rain.png
LV_IMG_DECLARE(ui_img_day_clear_png);    // assets\day_clear.png


LV_FONT_DECLARE(ui_font_Technology120);
LV_FONT_DECLARE(ui_font_Technology60);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
