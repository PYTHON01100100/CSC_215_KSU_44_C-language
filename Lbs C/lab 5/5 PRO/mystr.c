#include <stdlib.h>
#include "mystr.h"

int slen(char* str){
  int i=0;
  while(*str++) i++;
  return i;
}

char* scat(char* s1, char* s2){
  char *p, *Result = (char*)malloc(slen(s1)+slen(s2)+1);
  if ((p=Result)){
    while((*p++=*s1++));
    p--;
    while((*p++=*s2++));
  }
  return Result;
}

int scmp(char* s1, char* s2){
  while(*s1 && (*s1==*s2))
    s1++, s2++;
  return *s1-*s2;
  
}

char* sdup(char* str){
  char *p, *Result = (char*)malloc(slen(str)+1);
  if ((p=Result))
    while((*p++=*str++));
  return Result;
}

char* srev(char* str){
  char *result = (char*)malloc(slen(str)+1);
  if(result){
    char* p=result+slen(str);
    *p--=0;
    while(*str){
      *p--=*str++;
    }
  }
  return result;
}