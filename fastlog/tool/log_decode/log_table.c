#include "log_decode.h"

logTable_t logTable[] = {
    {FILEID_SAMPLE1_C, 8, 0, "IN func1"},
    {FILEID_SAMPLE1_C, 10, 0, "OUT func1"},
    {FILEID_SAMPLE2_C, 6, 1, "IN func2 a = %08x"},
    {FILEID_SAMPLE2_C, 8, 1, "OUT func2 a = %d"},
};
unsigned int g_logTableNum = sizeof(logTable)/sizeof(logTable[0]);
