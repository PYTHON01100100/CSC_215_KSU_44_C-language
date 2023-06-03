#include <stdio.h>
#include <stdlib.h>
#include "pub.h"
#include "pub.c"

int main(){
  int n,i;
  PubList pl,bpl;
  float tot=0;
  printf("Enter The No. of publications: ");
  scanf("%d",&n);
  printf("The No of Pub is: %d\n",n);
  pl.list=(Publication*)malloc(n*sizeof(Publication));
  pl.count = 0;
  for(i=0;i<n;i++){
    Publication p=readpub();
    if(findpub(&p,pl)==-1){
    pl.list[i]=p;
    pl.count++;
    }
    else{
      i--;
    }
  }
  printf("part 1 done\n");
  bpl=getallbooks(pl);
  for(i=0;i<bpl.count;i++){
    tot +=bpl.list[i].price;
  }
  printf("sum of all book prices = SR%2.f\n",tot);

  
return 0;
}