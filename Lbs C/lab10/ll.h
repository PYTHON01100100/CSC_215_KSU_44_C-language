#if !defined LL
#define LL

struct node{
  char data;
  struct node* next;
};

struct linked_list{
  struct node* head;
};

void add_node(struct linked_list* list, char val);

void concat(struct linked_list* list1, struct linked_list* list2);

void print_list(struct linked_list* list);

#endif