#include "fastlog.h"

#define FILEID FILEID_SAMPLE2_C

void func2(int a){
  LOG1("IN func2 a = %08x", a);

  LOG1("OUT func2 a = %d", a);
}
