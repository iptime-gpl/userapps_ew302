/*
 * iSeries_proc.h
 * Copyright (C) 2001  Kyle A. Lucke IBM Corporation
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */


/* Change Activity: */
/* End Change Activity */

#ifndef _ISERIES_PROC_H
#define _ISERIES_PROC_H

#include <linux/proc_fs.h>

extern void iSeries_proc_early_init(void);
extern void iSeries_proc_create(void);

typedef void (*iSeriesProcFunction)(struct proc_dir_entry *iSeries_proc);

extern void iSeries_proc_callback(iSeriesProcFunction initFunction);

#endif /* _iSeries_PROC_H */
