/*
 * @Author: ljyws 945706034@qq.com
 * @Date: 2024-04-27 01:37:12
 * @LastEditors: ljyws 945706034@qq.com
 * @LastEditTime: 2024-05-03 00:59:43
 * @FilePath: \desktop_monitor\src\display\lv_porting\lv_port_disp.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file lv_port_disp_templ.h
 *
 */

/*Copy this file as "lv_port_disp.h" and set this value to "1" to enable content*/
#if 1

#ifndef LV_PORT_DISP_TEMPL_H
#define LV_PORT_DISP_TEMPL_H


/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#include <Arduino.h>
#include "../lgfx_config.hpp"


#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 320

#define LV_VER_RES_MAX  240
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/* Initialize low level display driver */
void lv_port_disp_init(void);

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void);

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void);

/**********************
 *      MACROS
 **********************/


#endif /*LV_PORT_DISP_TEMPL_H*/

#endif /*Disable/Enable content*/
