#include <stdio.h>

struct student 
{
    int id;
    float gpa;
    char name[15];
};
int findhighest(struct student s[], int n)
{ 
    int max = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (s[i].gpa > s[max].gpa)
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student s[n]; 
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the id  of student %d: \n ", i + 1);
        scanf("%d", &s[i].id);
        printf("Enter the name  of student %d: \n ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter the GPA  of student %d:  \n", i + 1);
        scanf("%f", &s[i].gpa);
    }
    int maxind = findhighest(s, n);
    printf("%s\n", s[maxind].name); 
    for (i = 0; i < n; i++)
    {
        if (i != maxind)
        {
            printf("%s\n", s[i].name);
        }
    }

    return 0;
}