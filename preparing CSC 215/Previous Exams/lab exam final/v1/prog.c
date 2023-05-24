/* 1- include the needed header files */
#include <stdio.h>
#include <stdlib.h>


/* 2- Define Node structure that contains:
     an int data and a next node pointer */
typedef struct node{
  int data;
  struct node* next;
} Node;


/* 3- Define LinkedList structure that contains:
     a header node pointer */
typedef struct linkedlist{
  Node* head;
}*linkedlist;


/* 4- function insert_at_front insert a node containing data d to
     the front of the linked list ll and returns nothing */
void insert_at_front(linkedlist ll, int d){
  Node* nn = (Node*)calloc(1,sizeof(Node));
  nn->data = d;
  nn->next = ll->head;
  ll->head = nn;
}

/* 5- function delete_from_back deletes the last node from the
     linked list ll and returns nothing */
void delete_from_back(linkedlist ll){
  Node* p = ll->head;
  if (!p) return;
  if (!(p->next)){
    free(p);
    ll->head = NULL;
  }
  else{
    while(p->next->next) p = p->next;
    free(p->next);
    p->next=NULL;
  }
}

/* 6- function delete_from_i deletes the node at position i from
     the linked list ll and returns nothing */
void delete_from_i(linkedlist ll, int i){
  Node *p = ll->head, *pp;
  int count=0;
  if (i==0){
    if (!p) return;
    else {
      ll->head = p->next;
      free(p);
      return;
    }
  }
  while (count<(i-1) && p && p->next) {
    count++;
    p = p->next;
  }
  if (!p || !(p->next)) return;
  pp = p->next;
  p->next = p->next->next;
  free(pp);
}

/* 7- function split_list copies all nodes of the 1st half of the
     linked list ll to the empty list left, and all nodes of the
     2nd half to the empty list right and returns nothing Note:
     if count of nodes in ll is odd, make left the longer list */
void split_list(linkedlist ll, linkedlist left, linkedlist right){
  int count=0, i=0;
  Node* p = ll->head;
  while (p) {
    count++;
    p=p->next;
  }
  p = ll->head;
  while (p){
    if (i<(count+1)/2)
      insert_at_front(left, p->data);
    else
      insert_at_front(right, p->data);
    i++;
    p = p->next;
  }
}

/* 8- function print_list prints the values stored in the nodes of
     the linked list ll to standard output in the format:
     data1 -> data2 -> ...  -> NULL and returns nothing */
void print_list(linkedlist ll){
  Node* p = ll->head;
  while (p) {
    printf("%d->", p->data);
    p = p -> next;
  }
  printf("NULL\n");
}

/* 9- function main:
     - creates three empty linked lists: L1, L2 and L3
     - inserts the values 15, 23, 47, 3, 9, 17 respectively in L1
     - splits L1 into L2 for the 1st half and L3 for the 2nd
     - prints the data stored in the three lists
     - deletes the element at position 2 from L3
     - prints the data stored in the three lists  */

int main(){
  linkedlist l1,l2,l3;
  l1 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  l2 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  l3 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  insert_at_front(l1,15);
  insert_at_front(l1,23);
  insert_at_front(l1,47);
  insert_at_front(l1,3);
  insert_at_front(l1,9);
  insert_at_front(l1,17);
  split_list(l1, l2, l3);
  print_list(l1);
  print_list(l2);
  print_list(l3);
  delete_from_i(l3, 2);
  print_list(l1);
  print_list(l2);
  print_list(l3);
 return 0;

}