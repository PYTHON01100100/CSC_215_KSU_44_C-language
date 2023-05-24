#include <stdio.h>

int main(){
  char sentence[255], ch;
  int i=0;

  printf("Please enter a sentence:\n");
  gets(sentence);

  while( (ch=sentence[i]) != '\0'){
    if (i==0 || sentence[i-1] == ' '){
      if (ch>='a' && ch<='z')
        sentence[i] -= ('a'-'A');
    }
    else {
      if (ch>='A' && ch<='Z')
        sentence[i] += ('a'-'A');
    }
    i++; 
  }

  printf("%s\n", sentence);

  return 0;
}