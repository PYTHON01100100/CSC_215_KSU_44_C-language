#if ! defined EMP
#define EMP

typedef struct Employee Employee; 

void read_employee(Employee* e);

void print_employee(Employee e);

Employee* copy_employee(Employee e);

Employee* emp_gte_5000(Employee* earr, int size, int* res_size);

int save_to_file(char* fn, Employee* earr, int size);

#endif