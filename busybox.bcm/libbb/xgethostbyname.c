/* vi: set sw=4 ts=4: */
/*
 * Mini xgethostbyname implementation.
 *
 *
 * Copyright (C) 2001 Matt Kraai <kraai@alumni.carnegiemellon.edu>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <netdb.h>
extern int h_errno;

#include "libbb.h"

struct hostent *xgethostbyname(const char *name)
{
	struct hostent *retval;

	if ((retval = gethostbyname(name)) == NULL)
		herror_msg_and_die("%s", name);

	return retval;
}
