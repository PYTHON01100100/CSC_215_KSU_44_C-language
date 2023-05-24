#include <stdio.h>
#include <stdlib.h> 
#include "pub.h"

Publication readpub(){
  Publication pub;
  char c;
  int v;
  printf("\nWhat type of publication (Book:b , Magazine:m)?");
  scanf("%c\n", &c);
  pub.type = c=='b'? ptBook:ptMagazine;
  printf("\nEnter the title:");
  gets(pub.title);
  printf("\nEnter # of pages:");
  scanf("%d\n", &(pub.npages));
  printf("\nWhat type of cover (Hardcover:h , Paperback:p)?");
  scanf("%c\n", &c);
  pub.cover = c=='h'? ctHardcover:ctPaperback; 
  printf("\nEnter the price:");
  scanf("%f\n", &(pub.price));
  if (pub.type == ptBook) {
    printf("\nEnter the ISBN:");
    scanf("%u\n", &(pub.more.isbn));
  }
  else {
    printf("\nEnter the ISSN:");
    scanf("%d\n", &(pub.more.details.issn));
    printf("\nEnter the volume #:");
    scanf("%d\n", &v); 
    pub.more.details.vol = (char)v;
    printf("\nEnter the issue #:");
    scanf("%d\n", &v); 
    pub.more.details.issue = (char)v;
  }
  return pub;
}

int findpub(Publication* pub, PubList pl){
  int i;
  for (i=0; i < pl.count; i++)
    if (pl.items[i].type == pub->type){
      if (pub->type == ptBook){
        if (pl.items[i].more.isbn == pub->more.isbn)
          return i;
      }
      else {
        if (pl.items[i].more.details.issn == pub->more.details.issn &&
            pl.items[i].more.details.vol == pub->more.details.vol &&
            pl.items[i].more.details.issue == pub->more.details.issue)
          return i;
      }
    }
  return -1;
}

PubList getallbooks(PubList pl){
  PubList result;
  Publication* p;
  int i;
  result.count = 0;  
  for (i=0; i<pl.count; i++)
    if (pl.items[i].type == ptBook) result.count++;
  result.items = (Publication*) malloc(result.count*sizeof(Publication));
  if ((p = result.items)){
    for (i=0; i<pl.count; i++){
      if (pl.items[i].type == ptBook)
        *p++ = pl.items[i];
    }
  }
  return result;
}

void printpublist(PubList pl){ 
  int i;
  for (i=0; i < pl.count; i++){
    printf("\n[%s]\n===========\n", pl.items[i].type==ptBook?"Book":"Magazine");
    printf("%s\n", pl.items[i].title);
    printf("%d pages @ S.R.%.2f\n", pl.items[i].npages, pl.items[i].price);
    if (pl.items[i].type == ptBook) printf("ISBN: %010u\n", pl.items[i].more.isbn);
    else printf("ISSN: %08d Vol. %d(%d)\n", pl.items[i].more.details.issn,
                                            pl.items[i].more.details.vol,
                                            pl.items[i].more.details.issue);
  }
    
}