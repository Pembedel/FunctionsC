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
     int numnam, j;
     char *names[] = {"Ram","Shyam","Pizza","Water","Array"};
     numnam = sizeof(names)/sizeof(char *);
     qsort(names, numnam, sizeof(char *), compare);
     for (j = 0 ; j < numnam; j++)
         printf("%s \n", names[j]);
     
return 0;
}