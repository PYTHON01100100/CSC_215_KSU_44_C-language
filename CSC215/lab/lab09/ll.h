#if !defined LL
#define LL

struct node{
  char data;
  struct node* next;
};

struct linked_list{
  struct node* head;
};


void concat(struct linked_list* list1, struct linked_list* list2);

int delete_duplicates(linkedlist ll);

#endif