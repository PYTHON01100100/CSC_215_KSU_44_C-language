#if !defined MF
#define MF

typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct node{
  struct node* head;
}linkedlist;

//part I:
//I.2
char* word_wrap(char* orig, int width);
//I.4
char* implode(char* glue, char** pieces, int count);
//I.6
char* make_pw(int min_size, int dig, int mix_cap);

//part II:
//II.1
void delete_from_i(linkedlist ll, int i);
//II.2
int delete_duplicates(linkedlist ll);
//II.3
linkedlist* rev_list(linkedlist ll);

#endif