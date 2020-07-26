/* JumpSearch.c*/
/* Execute with number of elements*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>

#define PRINT(array,i,n)  for(i=0; i<n; i++)\
                            printf("%d\t",array[i]);


#define SWAP(temp,x,y)   temp = *x;\
                    *x = *y;\
                    *y = temp;

#define MIN(x,y) ((x>y)?y:x)

int partition(int *array, int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  int temp;
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {
      i++;
      SWAP(temp,&array[i], &array[j]);
    }
  }

  SWAP(temp, &array[i + 1], &array[high]);
  return (i + 1);
}

void quicksort(int *array, int low, int high)
{
  int pi;
  if (low < high) 
  {
    pi = partition(array, low, high);
    quicksort(array, low, pi - 1);
    quicksort(array, pi + 1, high);
  }
}

int floorsqrt(int x) 
{ 
    // Base cases 
    if (x == 0 || x == 1) 
    return x; 
  
    /* Staring from 1, try all numbers until 
     i*i is greater than or equal to x.*/ 
    int i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
} 

int jumpSearch(int *arr, int search_num, int arraysize) 
{ 
    int step = floorsqrt(arraysize); 

    /*Block of segment where present*/
    int prev = 0; 
    while (arr[MIN(step, arraysize)-1] < search_num) 
    { 
        prev = step; 
        step += floorsqrt(arraysize); 
        if (prev >= arraysize) 
            return -1; 
    } 
  
    /* Search the block*/
    while (arr[prev] < search_num) 
    { 
        prev++; 
  
        /* element not present if end is reached*/ 
        if (prev == MIN(step, arraysize)) 
            return -1; 
    } 
    /* element found*/
    if (arr[prev] == search_num) 
        return prev; 
  
    return -1; 
} 

int main(int argc, char **argv)
{
    int *array;
    int i;
    int num, num_elem;
    int search;

    num_elem = atoi(argv[1]);

    array = malloc(num_elem*sizeof(int));
    
    for(i = 0; i < num_elem; i++ )
    {
        printf("\nEnter a number:");
        scanf("%d",&num);
        array[i] = num;
    }
    printf("\narray before sorting:\n");
    PRINT(array,i, num_elem);
 
    /* sort the list using quicksort algorithm */
    quicksort(array,0,num_elem-1);
 
    printf("\n array after sorting:\n");
    PRINT(array,i,num_elem);

    printf("\nEnter element to be searched:");
    scanf("%d", &search);

    if (jumpSearch(array, search, num_elem) > 0)
        printf("\nElement found");
    else
        printf("Element not found");


    return 0;
}
 
