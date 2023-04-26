#include <stdlib.h>
#include "mystr.h"

int slen(char* str){
  int i=0;
  while(*str++) i++;
  return i;
}

char* scat(char* s1, char* s2){
  char *c, *cat = (char*)calloc(slen(s1)+slen(s2)+1, 1);
  if ((c=cat)){
    while((*c++=*s1++));
    c--;
    while((*c++=*s2++));
  }
  return cat;
}

int scmp(char* s1, char* s2){
  while(*s1 && (*s1==*s2))
    s1++, s2++;
  return *s1-*s2;
  
}

char* sdup(char* str){
  char *d, *dup = (char*)calloc(slen(str)+1, 1);
  if ((d=dup))
    while((*d++=*str++));
  return dup;
}

char* srev(char* str){
  char *rs, *re, *rev = (char*)calloc(slen(str)+1, 1);
  if ((rs=rev)) {
    re = str+slen(str)-1;
    while (re >= str)
      *rs++ = *re--;
  }
  return rev;
}