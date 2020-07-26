/* String_Split.c */
#include<stdio.h>
#include<string.h>

int main(void)
{
    char main_string[1024];
    char substr[256];

    printf("\nEnter a string:");
    scanf("%s",main_string);
    
    printf("\nEnter a sub-string to be searched:");
    scanf("%s",substr);
    
    if(strstr(main_string, substr) != NULL) 
    {
        printf("\nsub string present in main string");
    }
    else
    {
        printf("\nsub string not present in main string");
    }
}
