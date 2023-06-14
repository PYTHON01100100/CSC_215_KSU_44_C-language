#include <stdio.h>
#include <stdlib.h>
#include "pub.h"

int main(){
  PubList pl, bl;
  Publication p;
  int i;
  float sum=0;
  printf("How many publication to process?");
  scanf("%d\n", &(pl.count));
  if ((pl.items = (Publication*) malloc(pl.count*sizeof(Publication)))) {
    for (i=0; i<pl.count; i++) {
      do {
        p = readpub();
      } while (findpub(&p, pl) != -1);
      pl.items[i] = p;
      printf("\n--------------------");
    }  
    bl = getallbooks(pl);
    printpublist(bl);
    for (i=0; i < bl.count; i++)
      sum += bl.items[i].price;
    printf("\nTotal price for all books: %.2f", sum);
    free(pl.items);
    free(bl.items);
    return 0;
  }
  return -1;
}