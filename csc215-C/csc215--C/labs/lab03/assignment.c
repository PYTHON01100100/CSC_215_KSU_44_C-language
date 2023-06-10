#include <stdio.h>

int main(){
  char sentence[255], ch;
  int i=0;
  int cA=0, cE=0, cI=0, cO=0, cU=0;
  printf("Please enter a sentence:\n");
  gets(sentence);

  while( (ch=sentence[i++]) != '\0')
    switch (ch){
      case 'A': case 'a': cA++; break;      
      case 'E': case 'e': cE++; break;
      case 'I': case 'i': cI++; break;
      case 'O': case 'o': cO++; break;
      case 'U': case 'u': cU++;
    }

  printf("A:%d\tE:%d\tI:%d\tO:%d\tU:%d\n",
          cA, cE, cI, cO, cU);

  return 0;
}