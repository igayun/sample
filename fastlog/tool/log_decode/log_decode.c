#include <stdio.h>
#include "log_decode.h"

extern logTable_t logTable[];

int main(int argc, char *argv[]){
  FILE *fp = NULL;
  unsigned int data;
  unsigned int lineNum;
  unsigned int args;
  unsigned int fileId;
  unsigned int i;

  if (argc != 2){
    printf("Usage: %s <memfile>\n", argv[0]);
    return -1;
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL){
    printf("cannot open file %s\n", argv[1]);
    return -1;
  }

  while(!feof(fp)){
    fread(&data, sizeof(int), 1, fp);
    //    printf("%08x\n", data);
    args     = (data & 0x80000000) >> 31;
    fileId   = (data & 0x7fff0000) >> 16;
    lineNum  = (data & 0x0000ffff) >>  0;

    for (i = 0; i < g_logTableNum;i++){
      if ((args    == logTable[i].args)   &&
	  (fileId  == logTable[i].fileId) &&
	  (lineNum == logTable[i].lineNum)){
	if (args == 0){
	  printf(logTable[i].logstr);
	  printf("\n");
	} else {
	  fread(&data, sizeof(int), 1, fp);
	  printf(logTable[i].logstr, data);
	  printf("\n");
	}
	break;
      }
    }
    if (i == g_logTableNum){
      printf("Unknown LOG Code %08x\n", data);
    }
  }
  return 0;
}
