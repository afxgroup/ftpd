#include "console.h"
#include <arpa/inet.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if ENABLE_LOGGING
static bool disable_logging = false;
#endif

/* this is a lot easier when you have a real console */

void console_init(void)
{
}

void console_set_status(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
  fputc('\n', stdout);
}

void console_print(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
}

void debug_print(const char *fmt, ...)
{
#ifdef ENABLE_LOGGING
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
#endif
}

void console_render(void)
{
}
