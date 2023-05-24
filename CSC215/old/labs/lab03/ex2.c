#include <stdio.h>

int main(){
  float series;
  float term;
  int i;

  /* Part 1 */
  series = 0;  
  for (i = 1; i <= 1000; i++) {
    int sign = (i+1)%2 == 0? 1:-1;
    int isq = i*i;
    int i5sq = (i+5)*(i+5);

    term = (float)sign * isq / i5sq;
    series += term;
  }
  printf("%f\n", series);

  /* Part 2 */
  series = term = 0;
  i=0;
  do {
    series += term;
    i++;
    int sign = (i+1)%2 == 0? 1:-1;
    int isq = i*i;
    int i5sq = (i+5)*(i+5);
    term = (float)sign * isq / i5sq;
  } while ( (series+term) < 0.5);  
  printf("%d\n", i-1);

  return 0;
}