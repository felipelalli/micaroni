/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      System level: initialization, cleanup, etc.
 *
 *      By Shawn Hargreaves.
 *
 *      See readme.txt for copyright information.
 */


#ifndef ALLEGRO_SYSTEM_H
#define ALLEGRO_SYSTEM_H

#ifdef __cplusplus
   extern "C" {
#endif

#include "base.h"

struct RGB;
struct BITMAP;
struct GFX_VTABLE;

#define ALLEGRO_ERROR_SIZE 256

AL_ARRAY(char, allegro_id);
AL_ARRAY(char, allegro_error);

#define OSTYPE_UNKNOWN     0
#define OSTYPE_WIN3        AL_ID('W','I','N','3')
#define OSTYPE_WIN95       AL_ID('W','9','5',' ')
#define OSTYPE_WIN98       AL_ID('W','9','8',' ')
#define OSTYPE_WINME       AL_ID('W','M','E',' ')
#define OSTYPE_WINNT       AL_ID('W','N','T',' ')
#define OSTYPE_WIN2000     AL_ID('W','2','K',' ')
#define OSTYPE_WINXP       AL_ID('W','X','P',' ')
#define OSTYPE_OS2         AL_ID('O','S','2',' ')
#define OSTYPE_WARP        AL_ID('W','A','R','P')
#define OSTYPE_DOSEMU      AL_ID('D','E','M','U')
#define OSTYPE_OPENDOS     AL_ID('O','D','O','S')
#define OSTYPE_LINUX       AL_ID('T','U','X',' ')
#define OSTYPE_FREEBSD     AL_ID('F','B','S','D')
#define OSTYPE_UNIX        AL_ID('U','N','I','X')
#define OSTYPE_BEOS        AL_ID('B','E','O','S')
#define OSTYPE_QNX         AL_ID('Q','N','X',' ')
#define OSTYPE_MACOS       AL_ID('M','A','C',' ')

AL_VAR(int, os_type);
AL_VAR(int, os_version);
AL_VAR(int, os_revision);
AL_VAR(int, os_multitasking);

#define SYSTEM_AUTODETECT  0
#define SYSTEM_NONE        AL_ID('N','O','N','E')

AL_FUNC(int, install_allegro, (int system_id, int *errno_ptr, AL_METHOD(int, atexit_ptr, (AL_METHOD(void, func, (void))))));
#define allegro_init()  install_allegro(SYSTEM_AUTODETECT, &errno, (int (*)(void (*)(void)))atexit)
AL_FUNC(void, allegro_exit, (void));

AL_FUNC(void, get_executable_name, (char *output, int size));
AL_PRINTFUNC(void, allegro_message, (AL_CONST char *msg, ...), 1, 2);


AL_FUNC(void, check_cpu, (void));

/* CPU Capabilities flags - set to 0 on non x86 capable chips */
#define CPU_ID       0x0001
#define CPU_FPU      0x0002
#define CPU_MMX      0x0004
#define CPU_MMXPLUS  0x0008
#define CPU_SSE      0x0010
#define CPU_SSE2     0x0020
#define CPU_3DNOW    0x0040
#define CPU_ENH3DNOW 0x0080
#define CPU_CMOV     0x0100

AL_ARRAY(char, cpu_vendor);
AL_VAR(int, cpu_family);
AL_VAR(int, cpu_model);
AL_VAR(int, cpu_capabilities);


typedef struct SYSTEM_DRIVER
{
   int  id;
   AL_CONST char *name;
   AL_CONST char *desc;
   AL_CONST char *ascii_name;
   AL_METHOD(int, init, (void));
   AL_METHOD(void, exit, (void));
   AL_METHOD(void, get_executable_name, (char *output, int size));
   AL_METHOD(int, find_resource, (char *dest, AL_CONST char *resource, int size));
   AL_METHOD(void, set_window_title, (AL_CONST char *name));
   AL_METHOD(int, set_window_close_button, (int enable));
   AL_METHOD(void, set_window_close_hook, (AL_METHOD(void, proc, (void))));
   AL_METHOD(void, message, (AL_CONST char *msg));
   AL_METHOD(void, assert, (AL_CONST char *msg));
   AL_METHOD(void, save_console_state, (void));
   AL_METHOD(void, restore_console_state, (void));
   AL_METHOD(struct BITMAP *, create_bitmap, (int color_depth, int width, int height));
   AL_METHOD(void, created_bitmap, (struct BITMAP *bmp));
   AL_METHOD(struct BITMAP *, create_sub_bitmap, (struct BITMAP *parent, int x, int y, int width, int height));
   AL_METHOD(void, created_sub_bitmap, (struct BITMAP *bmp, struct BITMAP *parent));
   AL_METHOD(int, destroy_bitmap, (struct BITMAP *bitmap));
   AL_METHOD(void, read_hardware_palette, (void));
   AL_METHOD(void, set_palette_range, (AL_CONST struct RGB *p, int from, int to, int retracesync));
   AL_METHOD(struct GFX_VTABLE *, get_vtable, (int color_depth));
   AL_METHOD(int, set_display_switch_mode, (int mode));
   AL_METHOD(int, set_display_switch_callback, (int dir, AL_METHOD(void, cb, (void))));
   AL_METHOD(void, remove_display_switch_callback, (AL_METHOD(void, cb, (void))));
   AL_METHOD(void, display_switch_lock, (int lock, int foreground));
   AL_METHOD(int, desktop_color_depth, (void));
   AL_METHOD(int, get_desktop_resolution, (int *width, int *height));
   AL_METHOD(void, yield_timeslice, (void));
   AL_METHOD(_DRIVER_INFO *, gfx_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, digi_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, midi_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, keyboard_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, mouse_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, joystick_drivers, (void));
   AL_METHOD(_DRIVER_INFO *, timer_drivers, (void));
} SYSTEM_DRIVER;


AL_VAR(SYSTEM_DRIVER, system_none);
AL_VAR(SYSTEM_DRIVER *, system_driver);
AL_ARRAY(_DRIVER_INFO, _system_driver_list);

#include "inline/system.inl"

#ifdef __cplusplus
   }
#endif

#endif          /* ifndef ALLEGRO_SYSTEM_H */


