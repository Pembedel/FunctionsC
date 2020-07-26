/*Sort_string.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 26
  
// function to print string in sorted order 
void sortString(char *str,int len) 
{ 
    int charCount[MAX_CHAR] = { 0 }; 
    int uniqueCount[MAX_CHAR] = { 0 };
    int i;
    int sum=0;

    /* Traverse string and increment 
     count of characters*/ 
    for (int i = 0; i < len; i++) 
    {
        charCount[str[i] - 'a']++;
        uniqueCount[str[i] -'a'] = 1;
    }
    
    for (i = 0;i<MAX_CHAR;i++)
        sum += uniqueCount[i];

    printf("\nUnique characters count:%d", sum);

    /* Traverse the hash array and print 
     characters*/ 
    printf("\nDescending order Sorted string:\n");
    for (i = MAX_CHAR - 1; i >= 0; i--) 
        for (int j = 0; j < charCount[i]; j++) 
            printf("%c", (char)('a' + i)); 
} 
  
int main(int argc, char ** argv) 
{ 
    char *str;
    int len = strlen(argv[1]);
    
    str = (char *) malloc((len+1)*sizeof(char));
    strncpy(str,argv[1],strlen(argv[1]));
    str[len]='\0';
    
    sortString(str, len); 
    return 0; 
} 
