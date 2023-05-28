#include <string.h>
#include <stdlib.h>
#include "functions.h"

char* str_replace(char* search, char* replace, char* orig){
  int count = 0;
	char *p;
 for(p =orig; p != NULL && *p != '\0'; p++){
	p= strstr(p, search);

	if(p != NULL)
		count++;
	else
		break;
}


int replace_len =strlen(replace), search_len = strlen(search);
int delta = count*(replace_len-search_len);
char *result= (char*)malloc((strlen(orig)+delta+1)*sizeof(char));
if(result == NULL)
	return NULL;
int i =0;
while(strstr(orig, search)){
	int diff = strstr(orig, search)-orig;
	strncpy(result+i, orig, diff);
	i+= diff;
	strcpy(result+i, replace);
	i+= replace_len;
	orig+= diff+search_len;
	result[i] ='\0';
}
strcat(result,orig);
 return result;
}

char** explode(char* delimiter, char* orig, int* count){
 *count = 1;
 char *p =orig,*q;
 while((q=strstr(p,delimiter))){
(*count)++;
p= q+1;
}

char **result =(char**)malloc((*count)*sizeof(char*));
if(result==NULL)
return NULL;

int i=0;
p = strtok(orig, delimiter);

while(p != NULL){
result[i++] =p;
p= strtok(NULL,delimiter);
}

  return result;
}

char* implode(char* glue, char** pieces, int count){
  int size = 0, i;
  for (i=0; i < count; i++) 
    size += strlen(pieces[i]);
  size += (count-1)*strlen(glue)+1;
  char *result = calloc(size, sizeof(char));
if(result ==NULL)
 return NULL;

  for(i=0; i<count; i++){
    strcat(result, pieces[i]);
    if (i < count-1){
      strcat(result, glue);
    }
  }
  return result;
}