#if !defined PUB
#define PUB

typedef enum {ptBook, ptMagazine} PubType;

typedef enum {ctHardcover, ctPaperback} CoverType;

typedef struct {
  PubType type;
  char title[100];
  int npages;
  CoverType cover;
  float price;
  union{
    struct{
      int issn;
      char vol;
      char issue;
    } details;
    unsigned int isbn;
  } more;
} Publication;

typedef struct {
  int count;
  Publication* items;
} PubList;

Publication readpub();

int findpub(Publication* , PubList );

PubList getallbooks(PubList );

void printpublist(PubList);

#endif