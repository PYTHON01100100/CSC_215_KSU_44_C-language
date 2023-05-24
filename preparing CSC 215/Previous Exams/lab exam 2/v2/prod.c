#include <stdio.h> 
#include <stdlib.h> 
#include "prod.h"

struct Product{ 
  int serial; 
  char name[25]; 
  float price; 
}; 

void read_product(Product* p){
  char c;
  printf("Enter the serial number: ");
  scanf("%d", &(p->serial)); 
  printf("Enter the name: ");
  while ((c=getchar())=='\n'); 
  ungetc(c, stdin);
  gets(p->name);   
  printf("Enter the price: ");
  scanf("%f", &(p->price)); 
}

void print_product(Product p){
  printf("Serial number: %d\n", p.serial); 
  printf("Name: %s\n", p.name); 
  printf("Price: %.2f\n", p.price); 
  printf("--------------\n");
}

Product* discounted_copy(Product p){
  Product* result; 
  result = (Product*)malloc(sizeof(Product)); 
  result->serial = p.serial;
  sprintf(result->name, "%s", p.name); 
  result->price = p.price * 0.9; 
  return result; 
}

Product* prod_gt_999(Product* parr, int s, int* res_s){
  int i, j; 
  Product* result; 
  *res_s = 0; 
  for (i=0; i< s; i++) 
  if (parr[i].price > 999.99) (*res_s)++; 
  result = (Product*)malloc((*res_s)*sizeof(Product)); 
  for(i=0,j=0; i<s; i++) 
    if (parr[i].price > 999.99) 
      result[j++] = *(discounted_copy(parr[i])); 
  return result; 
}

int save_to_file(char* fn, Product* parr, int size){ 
  int i; 
  FILE* fp = fopen(fn, "w"); 
  fwrite(&size, sizeof(int), 1, fp); 
  for (i=0; i<size; i++)
    fwrite(&(parr[i]), sizeof(Product), 1, fp); 
  fclose(fp); 
  return size;
} 

int main(void) { 
  int num, num_999, i; 
  Product *prod_arr, *prod_999; 

  /* ask the user to enter number of products num */
  printf("Enter number of products:"); 
  scanf("%d", &num); 

  /* allocate enough memory for array prod_arr to store num products */
  prod_arr = (Product*)malloc(num*sizeof(Product)); 

  /* read the information of the num products from the keyboard */
  for (i=0; i < num; i++) 
    read_product(&(prod_arr[i])); 

  /* store products with price > 999.99 in the array prod_999 
     of size num_999 */
  prod_999 = prod_gt_999(prod_arr, num, &num_999); 

  /* print the information of all products in prod_999 to the screen */
  printf("\nProducts with price more than 999.99\n");
  printf("============================================\n");
  for (i=0; i < num_999; i++) 
    print_product(prod_999[i]); 

  /* store the number of products in prod_999 and their information in 
     the file "prod-999.dat"*/
  save_to_file("prod-999.dat", prod_999, num_999); 

  return 0; 
}