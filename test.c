#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "shcmd.h"

int main(void)
{
  char* buf = malloc(sizeof(char) * 1024);
  memset(buf, '\0', 1024);
  shcmd("ls", buf);
  printf("%s\n", buf);
  assert(buf[0] != '\0');
  return 0;
}
