#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void * ca, const void * cb)
{
    char **a = (char **)ca;
    char **b = (char **)cb;
    return strcmp(*a, *b);
} 

int main()
{
     int num, i;
     char *names[] = {"Ram","Shyam","Pizza","Water","Array"};
     num = sizeof(names)/sizeof(char *);
     qsort(names, num, sizeof(char *), compare);
     printf("\n Sorted name list:\n");
     for (i = 0 ; i < num; i++)
         printf("%s \n", names[i]);
     
return 0;
}