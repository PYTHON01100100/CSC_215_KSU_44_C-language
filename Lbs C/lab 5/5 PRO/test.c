#include <stdio.h>
#include <stdlib.h>
#include "mystr.h"
#include "mystr.c"

int main(){
  char name1[20], name2[20];
  printf("Enter your name: ");
  scanf("%s", name1);

  char* phrase = scat("Hello ", name1);
  printf("%s\n", phrase);

  printf("Enter your name: ");
  scanf("%s", name2);

  if (!scmp(name1, name2)){
    char* phrase = scat("You alread entered name ", name2);
    printf("%s\n", phrase);
  }
  else {
    char* phrase = scat("Hello ", name2);
    printf("%s\n", phrase);

  }
    
  char* dupname = sdup(name1);
  printf("Dupname1 : %s\n", dupname);

  char* revname = srev(name2);
  printf("RevName2 %s\n", revname);
  return 0;
}