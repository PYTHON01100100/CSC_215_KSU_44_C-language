#include <stdlib.h>
#include<stdio.h>
#include"todo.h"
#include"todo.c"
//define INITIAL_SIZE 3
#define DIM 3

int main(void){
    todoList todos={NULL,0 , DIM};
    todos.task=malloc(3*sizeof(*todos.task));

    if(!todos.task){
    puts("exit: cannot allocate initial takes space.");
return 1;
    }
    printf("finsihed :\n");
    
    insert(&todos,"check my uni email. ");
    insert(&todos,"submit CSC215 LAB.");
    insert(&todos,"BUY WATER FROM SUPERMARKET .");
    insert(&todos,"CALL MY GRAND. ");
    
   print_list(&todos);
    complete(&todos,1);
    printf("---------------------\n");
    print_list(&todos);
    
    printf("---------------------\n");
    Delete(&todos,2);
    
    printf("---------------------\n");
    print_list(&todos);
    write_to_file(&todos,"output.txt");
    destroylist(&todos);
  

     return 0;
}