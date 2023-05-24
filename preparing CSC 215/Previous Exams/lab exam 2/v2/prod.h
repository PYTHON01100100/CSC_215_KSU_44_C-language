#if ! defined PROD
#define PROD

/* struct Product has the following members:
   - serial as integer
   - name as string of maximum length of 24 letters
   - price as floating point number */
typedef struct Product Product;

/* function read_product reads product’s information from
   the Keyboard and fills it in the parameter p */
void read_product(Product* p);

/* function print_product prints the information of
   the product p to the screen */
void print_product(Product p);

/* function discounted_copy takes a Product parameter p and
   returns a pointer to a new copy of p after applying a 10%
   discount on the price */
Product* discounted_copy(Product p);

/* function prod_gt_999 takes an array of products parr of size
   s and returns a new array contains discounted copies of
   products with prices greater than 999.99, of size res_s */
Product* prod_gt_999(Product* parr, int s, int* res_s);

/* function save_to_file stores the size of array parr in the file
   fn, then stores all products of parr in the file and returns
   1 if succeeds, and 0 otherwise */
int save_to_file(char* fn, Product* parr, int size);

#endif