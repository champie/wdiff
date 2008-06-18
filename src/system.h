/* Shared definitions for GNU wdiff.
   Copyright (C) 1994, 1997, 1998 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#if HAVE_CONFIG_H
# include <config.h>
#endif

#if __STDC__
# define voidstar void *
#else
# define voidstar char *
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#else
char *getenv ();
#endif

/* Some systems do not define EXIT_*, even with STDC_HEADERS.  */
#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

/* Other header files.  */

#include <sys/types.h>
#include <stdio.h>

#include <errno.h>
#ifndef errno
extern int errno;
#endif

/* Small library functions.  */

#ifndef PARAMS
# if PROTOTYPES
#  define PARAMS(Args) Args
# else
#  define PARAMS(Args) ()
# endif
#endif

#include "error.h"
#include "xalloc.h"

/* Internationalization.  */
#include "gettext.h"
#define _(str) gettext (str)
#define N_(str) gettext_noop (str)

/* Debugging the memory allocator.  */

#if WITH_DMALLOC
# define MALLOC_FUNC_CHECK
# include <dmalloc.h>
#endif