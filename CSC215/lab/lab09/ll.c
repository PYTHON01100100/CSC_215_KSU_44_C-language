#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void concat(struct linked_list* list1, struct linked_list* list2){
  struct node* p = list1->head;
  if (!p) list1->head = list2->head;
  else {
    while (p->next) p=p->next;
    p->next = list2->head;
  } 
}