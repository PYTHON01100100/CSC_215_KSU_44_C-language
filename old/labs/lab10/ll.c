#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void add_node(struct linked_list* list, char val){
  struct node* nn = (struct node*)malloc(sizeof(struct node));
  if (!nn)
    printf("Could not add the node.\n");
  else {
    nn->data = val;
    nn->next = NULL;
    struct node* p = list->head;
    if (!p) list->head = nn;
    else {
      while (p->next) p=p->next;
      p->next = nn;
    }
    printf("The node (%c) was added successfully\n", val);
  }
}

void concat(struct linked_list* list1, struct linked_list* list2){
  struct node* p = list1->head;
  if (!p) list1->head = list2->head;
  else {
    while (p->next) p=p->next;
    p->next = list2->head;
  } 
}

void print_list(struct linked_list* list){
  struct node* p = list->head;
  while(p){
    printf("(%c)", p->data);
    p=p->next;
    if (p) printf("->");
  }
  printf("-|\n");
}

