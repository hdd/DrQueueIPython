//
// Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Jorge Daza Garcia-Blanes
//
// This file is part of DrQueue
//
// DrQueue is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// DrQueue is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA
//
// $Id$
//

#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef __CPLUSPLUS
extern "C" {
#endif

#include "libdrqueue.h"
#include "pointer.h"
#include "job.h"

#define REVISION "$Rev$"
#define VERSION_MAJOR  0
#define VERSION_MINOR  64
#define VERSION_PATCH  3
#define VERSION_POST   0
#define VERSION_PRE    1


int common_environment_check (void);
void show_version (char **argv);
int rmdir_check_str (char *path);
int remove_dir (char *dir);
char *time_str (uint32_t nseconds);
void set_default_env(void);

int common_date_check (void);

/* Mail notifications */
void mn_job_finished (struct job *job);

char *get_version_prepost (void);
char *get_revision_string (void);
char *get_version_complete (void);

#ifdef __CPLUSPLUS
}
#endif

#endif /* _COMMON_H_ */
