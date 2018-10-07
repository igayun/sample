#include "fastlog.h"

#define FILEID FILEID_SAMPLE1_C

extern void func2(int a);

void func1(void){
  LOG0("IN func1");

  LOG0("OUT func1");
}


int main(int argc, char *argv[]){

  logOpen();
  func1();
  func2(0x1234);
  logClose();

  return 0;
}
