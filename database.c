/* $Id: database.c,v 1.6 2001/10/31 15:58:37 jorge Exp $ */

#include "database.h"
#include "computer.h"

void database_init (struct database *wdb)
{
  int i;

  for (i=0;i<MAXJOBS;i++) {
    job_init (&wdb->job[i]);
  }

  for (i=0;i<MAXCOMPUTERS;i++) {
    computer_init (&wdb->computer[i]);
  }

#ifdef COMM_REPORT
  wdb->bsent = wdb->brecv = 0;
#endif

}

int database_load (struct database *wdb)
{

}

int database_save (struct database *wdb)
{
  /* This function returns 1 on success and 0 on failure */
  /* It logs failure and maybe it should leave that task to the calling function */
  struct database_hdr hdr;
  char *basedir;
  char dir[BUFFERLEN];
  char filename[BUFFERLEN];


  if ((basedir = getenv("DRQUEUE_ROOT")) == NULL) {
    /* This should never happen because we check it at the beginning of the program */
    drerrno = DRE_NOENVROOT;
    return 0;
  }

  snprintf(dir,BUFFERLEN-1,"%s/db",basedir);
  snprintf(filename,BUFFERLEN-1,"%s/drqueue.db",dir);
  if ((fd = open (filename, O_CREAT|O_TRUNC|O_RDWR, 0664)) == -1) {
    if (errno == ENOENT) {
      /* If its because the directory does not exist we try creating it first */
      if (mkdir (dir,0775) == -1) {
	log_master (L_WARNING,"Could not create database directory. Check permissions.");
	drerrno = DRE_COULDNOTCREATE;
	return 0;
      }
      if ((fd = open (filename, O_CREAT|O_TRUNC|O_RDWR, 0664)) == -1) {
	log_master (L_WARNING,"Could not open database file for writing. Check permissions.");
	drerrno = DRE_COULDNOTCREATE;
	return 0;
      }
    } else {
      /* could not open the file for other reasons */
      log_master (L_WARNING,"Could not open database file for writing. Check permissions.");
      drerrno = DRE_COULDNOTCREATE;
      return 0;
    }
  }

  hdr.magic = DB_MAGIC;
  hdr.version = DB_VERSION;
  hdr.job_size = MAXJOBS;
  hdr.computer_size = MAXCOMPUTERS;

  
}
