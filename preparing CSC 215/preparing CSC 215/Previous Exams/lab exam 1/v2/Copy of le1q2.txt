#include <stdio.h>
#define MAXLEN 1000

int main(){
  char ch, src[MAXLEN], dst[MAXLEN];
  int i, j;
  
  do {
    i = j = 0;
    printf("Please enter a sentence:\n");
    gets(src);

    while ((ch=src[i++])!= '\0')  
      switch (ch){
        case '\t': dst[j++] = '\\';
	           dst[j++] = 't';
                   break;
        case '\'':
        case '\"': dst[j++] = '\\';
        default: dst[j++] = ch;
      }
    dst[j++] = '\0';
    
    printf("\n%s\n", dst);   

    printf("Do you want to process another sentence:");
    ch = getchar();
    getchar();
  } while(ch == 'y');

  printf("Good bye\n");

  return 0;
}
