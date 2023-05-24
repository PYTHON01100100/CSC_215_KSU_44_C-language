#include <stdio.h>

int main(){
  int init;
  float bal;
  int i;
  float j;
  printf("Enter the initial balance:");
  scanf("%d", &init);
  
  printf("Rate");
  for (i=1; i <= 5; i++)
    printf("\tYear %-7d", i);
  for (j=0.01; j <= 0.05; j+=0.01){
    bal = init;  
    printf("\n%d%%", (int)(j*100));
    for (i=1; i <= 5; i++){
      bal += bal * j;
      printf("\tS.R %4.2f", bal);
    }
  }  
  printf("\n");
  return 0;
}
