#include <stdio.h>
#include <stdlib.h> 
#include "pub.h"
Publication readpub(){
Publication result;
char c;
printf("Enter The type of publication(b:book,m: magazine): ");
do{
scanf("%c",&c);
}while(c!='b' && c!='m');
printf("\n (%c) \n", c);
result.pttype=c=='b'?Book:Magazine;
printf("enter the title of the publication: ");
/*result.title=(char*)malloc(1024);*/
scanf("%s",result.title);
printf("enter the number of pages of the publication: ");
scanf("%d",&(result.npages)); /**/
printf("Enter The Cover type of publication(h:hardcover,p: paperback):");
do{
scanf("%c",&c);
}while(c!='h' && c!='p');
result.ctype = c=='h'?ctHardcover:ctPaperback;
printf("enter the price of the publication: ");
scanf("%f",&(result.price)); /**/
if(result.pttype==Book){
printf("enter the ISBN of the book: ");
scanf("%d",&(result.id.Bookid.isbn)); /**/
}
else{
printf("enter the ISBN of the magazine: ");
scanf("%d",&result.id.magid.issn);
printf("enter the vol of the magazine: ");
scanf("%d",&result.id.magid.vol);
printf("enter the issue of the magazine: ");
scanf("%d",&result.id.magid.issue);
}

return result;

}
int findpub(Publication* p, PubList pl){
  int i;
  printf("findpub pl.count = %d\n",pl.count);
  for (i=0; i < pl.count; i++){puts("MR2 - 1");
    if (pl.list[i].pttype == p->pttype){puts("MR2 - 2");
      if (p->pttype == Book){puts("MR2 - 3");
        if (pl.list[i].id.Bookid.isbn == p->id.Bookid.isbn)
          return i;
      }
      else {puts("MR2 - 4");
        if (pl.list[i].id.magid.issn == p->id.magid.issn &&
            pl.list[i].id.magid.vol == p->id.magid.vol &&
            pl.list[i].id.magid.issue== p->id.magid.issue)
          return i;
      }
    }
}
  return -1;
}
PubList getallbooks(PubList pl){
  PubList result;
  result.count=0;
  int i,j;
  for(i=0;i<pl.count;i++){
    if(pl.list[i].pttype==Book){
      result.count++;
    }
  }
  if(result.count>0)
  {
    result.list=(Publication*)malloc(result.count*sizeof(Publication));
    if(result.list){
        for(i=0,j=0;i<pl.count;i++){
    if(pl.list[i].pttype==Book){
      result.list[j++]=pl.list[i];
    }
  }
    }
    else{
      result.list=NULL;
    }
  }
  
  return result;
}
void printpublist(PubList pl){ 
  int i;
  for (i=0; i < pl.count; i++){
    printf("\n[%s]\n===========\n", pl.list[i].pttype==Book?"Book":"Magazine");
    printf("%s\n", pl.list[i].title);
    printf("%d pages @ S.R.%.2f\n", pl.list[i].npages, pl.list[i].price);
    if (pl.list[i].pttype == Book) printf("ISBN: %010u\n", pl.list[i].id.Bookid.isbn);
    else printf("ISSN: %08d Vol. %d(%d)\n", pl.list[i].id.magid.issn,
                                            pl.list[i].id.magid.issue,
                                            pl.list[i].id.magid.vol);
  }
}