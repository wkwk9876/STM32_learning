#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "systemlog.h"

void printlog(int level, const char * funcname, int linenum, const char * format, ...)
{
    va_list ap;
    va_start(ap, format);    
    if (level >= __LOG_LEVEL__)
    {
        printf("In %s at %d line :", funcname, linenum);
        vprintf(format, ap);
    }
    va_end(ap);
}
