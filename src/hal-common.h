/* Time-stamp: <2005-10-10 01:23:30 jcs>
|
|  Copyright (C) 2005 Jorg Schuler <jcsjcs at users sourceforge net>
|  Part of the gtkpod project.
| 
|  URL: http://www.gtkpod.org/
|  URL: http://gtkpod.sourceforge.net/
|
|
|  The source is taken from libipoddevice, CVS version October 8 2005
|  (http://64.14.94.162/index.php/Libipoddevice).
|
|  I decided not to make libgpod dependent on libipoddevice because
|  the latter depends on libraries not widely available yet (libhal >=
|  0.5.2, glib >= 2.8). It is planned to replace these files with a
|  libipoddevice dependence at some later time.
|
|  The following changes were done:
|
|  - libhal becomes optional (see #if HAVE_LIBHAL sections)
|  - provide some dummy libhal functions to make libhal-independence
|    of ipod-device.c easier.
|
|  Because of these changes only a limited amount of functionality is
|  available. See ipod-device.h for summary.
|
|
|
|
|  $Id$
*/
/* ex: set ts=4: */
/***************************************************************************
*  hal-common.h
*  Copyright (C) 2005 Novell 
*  Written by Aaron Bockover <aaron@aaronbock.net>
****************************************************************************/

/*  
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of version 2.1 of the GNU Lesser General Public
 *  License as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Lesser Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 *  USA
 */

#ifndef HAL_COMMON_H
#define HAL_COMMON_H

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <glib.h>
#include <glib-object.h>

#if HAVE_LIBHAL

#include <libhal.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>

static GMainContext *ipod_device_global_main_context = NULL;

dbus_bool_t hal_mainloop_integration(LibHalContext *ctx, DBusError *error);
void ipod_device_set_global_main_context(GMainContext *ctx);

#else
typedef void LibHalContext;
gchar **libhal_manager_find_device_string_match (LibHalContext *hal_ctx,
						 const gchar *dev,
						 const gchar *str,
						 gint *vol_count,
						 void *error);
void libhal_free_string_array (gchar **volumes);
gboolean libhal_device_property_exists (LibHalContext *hal_ctx,
					const gchar *vol,
					const gchar *prop,
					void *error);
gboolean libhal_device_get_property_bool (LibHalContext *hal_ctx,
					  const gchar *vol,
					  const gchar *prop,
					  void *error);
void libhal_ctx_shutdown (LibHalContext *hal_ctx, void *error);
void libhal_ctx_free (LibHalContext *hal_ctx);
#endif


#endif /* HAL_COMMON_H */