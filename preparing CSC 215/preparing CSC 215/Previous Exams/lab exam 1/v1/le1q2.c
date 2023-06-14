#include <stdio.h>
#define MAXLEN 1000
int main(){
  char ch, sentence[MAXLEN];
  int i, start, count, maxstart, maxcount;
  
  do {
    i = start = count = maxstart = 0;
    maxcount = -1;

    printf("Please enter a sentence:\n");
    gets(sentence);
    do {
      ch = sentence[i];
      if (ch == ' ' || ch == '\t' || ch == '\0'){
        if (count > maxcount){
          maxcount = count;
          maxstart = start;
	}
        start = i+1;
        count = 0;
      }
      else 
        count++;
      i++;
    } while(ch != '\0');
    printf("The longest word: ");
    for (i=maxstart; i<=maxstart+maxcount; i++)
      printf("%c", sentence[i]);
    printf("\n");
    printf("Do you want to analyse another sentence:");
    ch = getchar();
    getchar();    
  } while(ch == 'y');
  printf("Good bye\n");
  return 0;
}
