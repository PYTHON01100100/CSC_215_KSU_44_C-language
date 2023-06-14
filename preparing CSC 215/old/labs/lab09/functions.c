#include <stdlib.h>
#include <string.h>
#include "functions.h"

char* str_replace(char* search, char* replace, char* orig){
  char *p, *po, *result, *r;
  int count = 0, size;
  for (p = strstr(orig, search); p; p = strstr(p+strlen(search), search))
    count++;
  size = strlen(orig)+1+count*(strlen(replace)-strlen(search));
  if (!(r = result = (char*)calloc(size,1))) return NULL;

  for (p = strstr(po=orig, search); p; p = strstr(p+strlen(search), search)){
    strncpy(r, po, p-po);
    r += p-po;
    strcpy(r, replace);
    r += strlen(replace);
    po = p + strlen(search);
  }
  strcpy(r, po);
  return result;
}

char** explode(char* delimiter, char* orig, int* count){
  char *s=strdup(orig), *ss, **result;
  int i;
  *count = 0;
  while (strtok(s, delimiter)){
    (*count)++;
    s = NULL;
  }
  result = (char**)calloc(*count, sizeof(char*));
  s = strdup(orig);
  while ((ss = strtok(s, delimiter))){
    result[i++] = ss;
    s = NULL;
  }
  return result;
}

char* implode(char* glue, char** pieces, int count){
  char *result, *r;  
  int size = 0, i;
  for (i=0; i < count; i++) 
    size += strlen(pieces[i]);
  size += (count-1)*strlen(glue)+1;
  if (!(r=result = (char*)calloc(size, 1))) return NULL;
  for(i=0; i<count; i++){
    strcpy(r, pieces[i]);
    r += strlen(pieces[i]);
    if (i < count-1){
      strcpy(r, glue);
      r += strlen(glue);
    }
  }
  return result;
}