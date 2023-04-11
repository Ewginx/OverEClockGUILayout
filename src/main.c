/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "lvgl.h"
#include "app_hal.h"
#include "ui.h"

int main(void)
{
	lv_init();

	hal_setup();

  ui_init();

	hal_loop();
}
