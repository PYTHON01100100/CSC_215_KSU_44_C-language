#include <stdio.h> 
#include <stdlib.h> 
#include "emp.h"

struct Employee{ 
  char name[25]; 
  int id; 
  float salary; 
}; 

void read_employee(Employee* e){ 
  char c;
  printf("Enter the name: ");
  while ((c=getchar())=='\n'); 
  ungetc(c, stdin);
  gets(e->name);   
  printf("Enter the id: ");
  scanf("%d", &(e->id)); 
  printf("Enter the salary: ");
  scanf("%f", &(e->salary)); 
} 

void print_employee(Employee e){ 
  printf("Name:%s\n", e.name); 
  printf("Id:%d\n", e.id); 
  printf("Salary:%.2f\n", e.salary); 
  printf("--------------\n");
} 

Employee* copy_employee(Employee e){ 
    Employee* result; 
    result = (Employee*)malloc(sizeof(Employee));
    *result = e;
    /* you can also do this:
       sprintf(result->name, "%s", e.name); 
       result->id = e.id; 
       result->salary = e.salary; */
    return result; 
} 

Employee* emp_sal_gte_5000(Employee* earr, int size, int* res_size){ 
    int i, j; 
    Employee* result; 
    *res_size = 0; 
    for (i=0; i< size; i++) 
      if (earr[i].salary > 5000) (*res_size)++; 
    result = (Employee*)malloc((*res_size)*sizeof(Employee)); 
    for(i=0,j=0; i<size; i++) 
      if (earr[i].salary >= 5000) 
        result[j++] = *(copy_employee(earr[i])); 
    return result; 
} 

int save_to_file(char* fn, Employee* earr, int size){ 
    int i; 
    FILE* fp = fopen(fn, "w"); 
    fwrite(&size, sizeof(int), 1, fp); 
    for (i=0; i<size; i++)
        fwrite(&(earr[i]), sizeof(Employee), 1, fp); 
    fclose(fp); 
    return size;
} 

int main(void) { 
  int num, num_5000, i; 
  Employee *emp_arr, *emp_5000; 

  /* ask the user to enter number of employees num */
  printf("Enter number of employees:"); 
  scanf("%d", &num); 

  /* allocate enough memory for array emp_arr to store num employees */
  emp_arr = (Employee*)malloc(num*sizeof(Employee)); 

  /* read the information of the num employees from the keyboard */
  for (i=0; i < num; i++) 
    read_employee(&(emp_arr[i])); 

  /* store employees who receive a salary = 5000 in the array emp_5000 
     of size num_5000 */
  emp_5000 = emp_sal_gte_5000(emp_arr, num, &num_5000); 

  /* print the information of all employees in emp_5000 to the screen */
  printf("\nEmployees receiving more than 5000 as salary\n");
  printf("============================================\n");
  for (i=0; i < num_5000; i++) 
    print_employee(emp_5000[i]); 

  /* store the number of employees in emp_5000 and their information in 
     the file "emp-5000.dat"*/
  save_to_file("emp-5000.dat", emp_5000, num_5000); 

  return 0; 
}