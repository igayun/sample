#ifndef _FASTLOG_H_
#define _FASTLOG_H_

#include "fileid.h"

#undef FILEID

#define LOG0(msg)        logW(FILEID, __LINE__, 0, msg, 0)
#define LOG1(msg, arg1)  logW(FILEID, __LINE__, 1, msg, arg1)


extern void logOpen(void);
extern void logClose(void);

#endif /* _FASTLOG_H_ */
