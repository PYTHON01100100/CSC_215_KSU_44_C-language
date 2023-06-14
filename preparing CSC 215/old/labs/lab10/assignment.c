#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

struct stack{
  struct node* top;
} *stack;

void push(char val){
  struct node* nn = (struct node*)malloc(sizeof(struct node));
  if (!nn) return;
  nn->data = val;
  nn->next = stack->top;
  stack->top = nn;
}

char pop(){
  char result;
  if (!stack->top) return 0;
  result = stack->top->data;
  struct node* p = stack->top;
  stack->top = stack.top->next;
  free(p);
  return result;
}

int main(){
  char *word, ch;
  word = (char*)malloc(25);
  fgets(word, 25, stdin);
  while((ch=*word++)) push(ch);
  while((ch=pop())) printf("%c", ch); 
  return 0;
}