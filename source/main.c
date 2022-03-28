
#include <errno.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "console.h"
#include "ftp.h"

static const char __attribute__((used)) *version = "\0$VER: FTPD 1.0 (28.03.2022)\n";

/*! looping mechanism
 *
 *  @param[in] callback function to call during each iteration
 *
 *  @returns loop status
 */
static loop_status_t
loop(loop_status_t (*callback)(void))
{
  loop_status_t status = LOOP_CONTINUE;

  while (status == LOOP_CONTINUE)
    status = callback();
  return status;
}

/*! entry point
 *
 *  @param[in] argc unused
 *  @param[in] argv unused
 *
 *  returns exit status
 */
int 
main(int argc, char *argv[])
{
  loop_status_t status = LOOP_RESTART;

  enableUnixPaths();

  /* initialize console subsystem */
  console_init();

#ifdef ENABLE_LOGGING
  /* open log file */
  FILE *fp = freopen("T:ftpd.log", "wb", stderr);
  if (fp == NULL)
  {
    console_print(RED "freopen: 0x%08X\n" RESET, errno);
    goto log_fail;
  }

  /* truncate log file */
  if (ftruncate(fileno(fp), 0) != 0)
  {
    console_print(RED "ftruncate: 0x%08X\n" RESET, errno);
    goto log_fail;
  }
#endif

  while (status == LOOP_RESTART)
  {
    /* initialize ftp subsystem */
    if (ftp_init() == 0)
    {
      /* ftp loop */
      status = loop(ftp_loop);

      /* done with ftp */
      ftp_exit();
    }
    else
      status = LOOP_EXIT;
  }

#ifdef ENABLE_LOGGING
log_fail:
  if (fclose(stderr) != 0)
    console_print(RED "fclose(%d): 0x%08X\n" RESET, fileno(stderr), errno);
#endif

  return 0;
}
