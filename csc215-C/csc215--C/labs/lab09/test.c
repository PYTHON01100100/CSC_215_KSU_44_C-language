#include <stdio.h>
#include "functions.h"
#include "functions.c"
void myFree(char**arr, int count){
int i;
for(i = 0; i < count; i++)
free(arr[i]);
free(arr);
}

int main() {
char orig[] = "The white cat invited the red cat to a caterpillar lunch. What a cat";
char old[] = "cat";
char new[] = "tiger";
char* result = str_replace(old, new, orig);
puts("==========================================");
printf("Old string: %s\n", orig);
printf("New string: %s\n", result);
puts("==========================================");
int count,i;
char** carr = explode(" ", orig, &count);
for (i=0; i < count; i++)
printf("[%s] ", carr[i]);
puts("");
puts("==========================================");
char* imp = implode("|", carr, count);
printf("imp = %s\n", imp);
puts("==========================================");
free(result);
free(imp);
myFree(carr, count);
return 0;
}
