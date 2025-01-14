#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "display/monitor.h"
#include "indev/mouse.h"
#include "indev/mousewheel.h"
#include "indev/keyboard.h"
#include "sdl/sdl.h"
#include "ui.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define ONE_MINUTE_MS (60 * 1000)
#define ONE_HOUR_MS (60 * 60 * 1000)
#define TWELVE_HOUR_MS (12 * 60 * 60 * 1000)
bool flag = true;
Uint64 timeout;
int day;
int month;
int year;
int hour;
int minute;
int second;
struct tm *tm_struct;
time_t now;
int16_t angle;

char time_string[6];
char second_string[2];
char date_string[100];
/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
    (void)data;

    while (1)
    {
        SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}

void hal_setup(void)
{
// Workaround for sdl2 `-m32` crash
// https://bugs.launchpad.net/ubuntu/+source/libsdl2/+bug/1775067/comments/7
#ifndef WIN32
    setenv("DBUS_FATAL_WARNINGS", "0", 1);
#endif

    /* Add a display
     * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/

    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf[SDL_HOR_RES * 10];                       /*Declare a buffer for 10 lines*/
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, SDL_HOR_RES * 10); /*Initialize the display buffer*/

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);           /*Basic initialization*/
    disp_drv.flush_cb = sdl_display_flush; /*Used when `LV_VDB_SIZE != 0` in lv_conf.h (buffered drawing)*/
    disp_drv.draw_buf = &disp_buf;
    disp_drv.hor_res = SDL_HOR_RES;
    disp_drv.ver_res = SDL_VER_RES;
    // disp_drv.disp_fill = monitor_fill;      /*Used when `LV_VDB_SIZE == 0` in lv_conf.h (unbuffered drawing)*/
    // disp_drv.disp_map = monitor_map;        /*Used when `LV_VDB_SIZE == 0` in lv_conf.h (unbuffered drawing)*/
    lv_disp_drv_register(&disp_drv);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = sdl_mouse_read; /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);

    sdl_init();

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
     * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);
    timeout = SDL_GetTicks64();
}

void hal_loop(void)
{
    while (1)
    {
        SDL_Delay(5);
        lv_task_handler();
        if (SDL_GetTicks64() - timeout > 1000)
        {
            timeout = SDL_GetTicks64();
            now = time(NULL);
            tm_struct = localtime(&now);
            hour = tm_struct->tm_hour;
            minute = tm_struct->tm_min;
            second = tm_struct->tm_sec;
            day = tm_struct->tm_mday;
            month = tm_struct->tm_mon;
            year = tm_struct->tm_year;
            angle = second * 60;
            lv_img_set_angle(ui_ImageArmSecond, angle);
            angle = minute * 60;
            lv_img_set_angle(ui_ImageArmMinute, angle);
            angle = hour * 300 + (int)minute / 2 * 10;
            lv_img_set_angle(ui_ImageArmHour, angle);
            printf("Time: %i:%i:%i \n", hour, minute, second);
            fflush(stdout);
            sprintf(time_string, "%02i:%02i", hour, minute);
            lv_label_set_text(digitalClockLabel, time_string);
            sprintf(second_string, "%02i", second);
            lv_label_set_text(digitalClockSecondLabel, second_string);
            sprintf(date_string, "%02i.%02i.%i,", day, month + 1, year + 1900);
            lv_label_set_text(digitalClockDateLabel, date_string);
            // if (flag)
            // {
            //     lv_img_set_src(weatherImage, "D:angry_clouds.png");
            //     flag = false;
            // }
        }
    }
}
