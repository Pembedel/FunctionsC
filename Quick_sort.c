/* Quick_sort.c*/
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
 
int main(int argc, char **argv)
{
    int *array;
    int i;
    int num, num_elem;

    if (argc !=2)
        exit(-1);

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
    
    return 0;
}
 
