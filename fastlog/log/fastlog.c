#include <stdio.h>

static FILE *fp = NULL;
void logOpen(void){
  fp = fopen("outlog.mem", "w");
}

void logClose(void){
  fclose(fp);
}

void logW(int fileId, int lineNum, int argNum, const char *msg, int arg1){
  unsigned int id;

  id = argNum << 31;
  id |= (fileId & 0x7fff) << 16;
  id |= lineNum & 0xffff;

  printf("argNum = %d fileId = %d lineNum = %d\n", argNum, fileId, lineNum);
  printf("%08x\n", id);

  fwrite(&id, sizeof(int), 1, fp);
  if (argNum != 0){
    fwrite(&arg1, sizeof(int), 1, fp);
  }
}
