#include <stdio.h>
#include <string.h>

int atod(char *ch) {
  int len = strlen(ch);
  //printf("len = %d\n",len);
  int res = ch[0]-'0';
  //printf("res = %d\n",res);
  int counter;
  for (counter=1; counter<len; counter++)
  {
    res = res * 10;
    //printf("iter %d, res = %d\n", counter, res);
    res = res + (ch[counter] -'0');
  }
  return res;
}