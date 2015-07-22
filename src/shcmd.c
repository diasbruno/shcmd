#include <stdio.h>
#include "shcmd.h"

int shcmd(const char* command, char* out)
{
  FILE* ret = NULL;
  int c = 0;

  ret = popen(command, "r");

  if (ret) {
    c = fgetc(ret);
    *out = c;
    while (c != EOF) {
      *out++ = c;
      c = fgetc(ret);
    }
    pclose(ret);
  } else {
    printf("failed to pope\n");
    return 1;
  }

  return 0;
}
