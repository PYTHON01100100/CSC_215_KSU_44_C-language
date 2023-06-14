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

/* 4- function insert_after_i inserts the node after the node at
      position i of the linked list ll and returns nothing. Note:
      if there is not position i, insert the node at the end. */
void insert_after_i(linkedlist ll, int d, int i){
  Node* nn = (Node*)calloc(1,sizeof(Node));
  nn->data = d;
  Node* p = ll->head;
  int count=0;
  if (!p || i<0){
    nn->next = ll->head;
    ll->head = nn;
  }
  else {
    while (count < i && p->next) {
      count++;
      p = p->next;
    }
    nn->next = p->next;
    p->next = nn;
  }
}

/* 5- function delete_from_front deletes the first node of the
      linked list ll and returns nothing */
void delete_from_front(linkedlist ll){
  Node* p = ll->head;
  if (!p) return;
  ll->head = p->next;  
  free(p);
}

/* 6- function delete_duplicates removes all duplicates from the
      ordered linked list ll and returns number of deleted nodes */
int delete_duplicates(linkedlist ll){
  Node* p = ll->head;
  int count = 0;
  while (p && p->next){
    if (p->data == p->next->data){
      Node* pp = p->next;
      p->next = p->next->next;
      free(pp);
      count++;
    }
    else p = p->next;
  }
  return count;
}

/* 7- function delete_list deletes all nodes of the linked list ll,
      releases their memory and returns nothing */
void delete_list(linkedlist ll){
  while(ll->head) delete_from_front(ll);
}

/* 8- function split_alternate copies all nodes at odd positions
      of linked list ll to the empty list odd, and the rest of the
      nodes to the empty list even, and returns nothing */
void split_alternate(linkedlist ll,linkedlist odd,linkedlist even){
  Node* p = ll->head;
  int i=0;
  while (p){
    if (i%2==1) insert_after_i(odd, p->data, i);
    else insert_after_i(even, p->data, i);
    i++;
    p=p->next;
  }  
}

/* 9- function print_list prints the values stored in the nodes of
      the linked list ll to standard output in the format:
      data1 -> data2 -> … -> NULL and returns nothing */
void print_list(linkedlist ll){
  Node* p = ll->head;
  while (p) {
    printf("%d->", p->data);
    p = p -> next;
  }
  printf("NULL\n");
}

/* 10- function main:
      - creates three empty linked lists: L1, L2 and L3
      - inserts into L1 the values: 10, 1, 10, 1, 20, 2, 20, 3
      - splits L1 into L2 for the odd positions and L3 for the rest
      - prints the data stored in the three lists
      - deletes the duplicates from L2 and L3 independently 
      - prints the data stored in the three lists  */
int main(){
  linkedlist l1,l2,l3;
  l1 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  l2 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  l3 = (linkedlist)calloc(1, sizeof(struct linkedlist));
  int i, nums[] = {10, 1, 10, 1, 20, 2, 20, 3};
  for (i=0; i<8; i++)
    insert_after_i(l1, nums[i], i-1);
  split_alternate(l1, l2, l3);
  print_list(l1);
  print_list(l2);
  print_list(l3);
  delete_duplicates(l2);
  delete_duplicates(l3);
  print_list(l1);
  print_list(l2);
  print_list(l3);
  return 0;
}