/* sum_array.c
 * 
 * Implementation of sum of array
 * 
 *
 * Author: Kapil
 *
 */

#include <stdio.h>


int sum_array(int *array,size_t num)
{
	int i;
	int sum=0;
	printf("\n size in sum_array:%ld",num);
    for(i=0;i<num;i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

int main(void)
{
    int a[] ={1,2,3,4,5,6,7,8,9};
    size_t num = sizeof(a) / sizeof(int);
    printf("\n Sum of array is: %d\n", sum_array(a,num));
	return 0;
}
