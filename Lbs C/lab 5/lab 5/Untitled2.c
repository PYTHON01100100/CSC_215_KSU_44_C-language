#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n;
   int* grades;
   int l;
   int w=-1;
   float sum=0, avg;
   printf("Enter the number of values: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter %d values:\n", n);
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      for (int j = 0; j < i; j++) {
         if (arr[j] == arr[i]) {
            l=j;
            printf("Value already entered, try again.\n");
            i--;
            w=1;
            break;
         }
      }
      if(w==-1)
      sum += (arr[i]);

      w=-1;
   }
   avg = sum / n;
    printf("The average of array elements :%.2f  (sum = %f , count = %d) \n", avg, sum, n);
/*
   printf("Unique values entered are: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
  }
*/
   return 0;
}