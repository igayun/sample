#ifndef _LOG_DECODE_H_
#define _LOG_DECODE_H_

#include "fileid.h"

typedef struct {
  unsigned int fileId;
  unsigned int lineNum;
  unsigned int args;
  char        *logstr;
}logTable_t;

extern unsigned int g_logTableNum;

#endif /* _LOG_DECODE_H_ */
