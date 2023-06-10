#include <stdlib.h>
#include <string.h>

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

int main(){
    char sentence[256]; 
	char search[50]; 
	char replace[50]; 

    printf("Enter sentence = ");
    fgets(sentence,sizeof(sentence),stdin);
	
	printf("Enter search word = ");
    fgets(search,sizeof(search),stdin);
	
	printf("Enter the word to replace it with = ");
    fgets(replace,sizeof(replace),stdin);
    
	printf("%s\n\n", str_replace(search, replace, sentence)) ;
	
	return 0;
}