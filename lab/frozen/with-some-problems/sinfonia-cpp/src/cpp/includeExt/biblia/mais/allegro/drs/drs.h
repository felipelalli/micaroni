/*
 * $RCSfile: drs.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

/*
 * drs.h --- dirty rectangles system
 *
 * This file is gift-ware.  This file is given to you freely
 * as a gift.  You may use, modify, redistribute, and generally hack
 * it about in any way you like, and you do not have to give anyone
 * anything in return.
 *
 * I do not accept any responsibility for any effects, adverse or
 * otherwise, that this code may have on just about anything that
 * you can think of.  Use it at your own risk.
 *
 * Copyright (C) 1998, 1999, 2002  Michael Bukin
 */

#ifndef __bma_drs_h
#define __bma_drs_h

#include <allegro.h>
#ifdef WIN32
#include <winalleg.h>
#endif

namespace biblia { namespace mais { namespace allegro { namespace drs {

/* a few defines for library information */
#define DRS_VERSION          2
#define DRS_SUB_VERSION      0
#define DRS_VERSION_STR      "2.0"
#define DRS_DATE_STR         "2002"

/* Offscreen bitmap.  */
extern BITMAP *DRS_work;
extern BITMAP *DRS_anterior;

#ifdef __cplusplus
extern "C" {
#endif

  /* Initialize DR system.  */
  int DRS_init (const int _size, BITMAP* _bbmp, const int _bcol);
  /* Shutdown DR system.  */
  void DRS_exit (void);

  /* Restart DR system.  */
  void DRS_restart (void);

  /* Set background bitmap or color.  */
  void DRS_set_background (BITMAP* _back, const int _bcol);
  /* Set viewport offset in background bitmap.  */
  void DRS_set_offset (const int _x, const int _y);

  /* Set 'double buffer' mode.  */
  void DRS_use_double_buffer (const int _flag);
  /* Set 'wait for vsync' mode.  */
  void DRS_wait_for_vsync (const int _flag);

  /* Start new frame (copy background bitmap to work bitmap).  */
  void DRS_start_frame (void);

  /* Redraw everything on next update.  */
  void DRS_redraw_on_next_update (void);

  /* Add rectangle for changes in work bitmap (in background coordinates).  */
  void DRS_add_rectangle (const int _x, const int _y, const int _w, const int _h);
  /* Add rectangle for changes in background bitmap (in background coordinates).  */
  void DRS_background_changed (const int _x, const int _y, const int _w, const int _h);
  /* Add rectangle for changes in background and offscreen bitmaps.  */
  void DRS_buffer_changed (const int _x, const int _y, const int _w, const int _h);

  /* Update screen.  */
  void DRS_update_screen (void);

#ifdef __cplusplus
}
#endif

#endif /* !__bma_drs_h */

/*
 * drs.h ends here
 */

}}}}