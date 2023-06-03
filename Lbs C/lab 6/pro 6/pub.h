#if !defined PUB
#define PUB

typedef enum  PubType {Book, Magazine} PubType;

typedef enum CoverType {ctHardcover, ctPaperback} CoverType;

typedef struct Publication{
  PubType pttype;
  char title[1024];
  int npages;
  CoverType ctype;
  float price;
  union{
    struct{
      int issn;
      int vol;
      int issue;
    } magid;
    struct{
      int isbn;
    }Bookid;
  } id;
} Publication;

typedef struct {
  int count;
  Publication* list;
} PubList;

Publication readpub();
int findpub(Publication* , PubList );
PubList getallbooks(PubList );
void printpublist(PubList);
#endif