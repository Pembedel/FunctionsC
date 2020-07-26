#include <stdio.h>

int main() 
{
    long unsigned int number;
    int i;
    
    printf("\nEnter a number(>0): ");
    scanf("%lu", &number);

    if (number == 1) {
        printf("1 is neither prime nor composite.");
        return 0;
    }

    /* Check till half of the number*/
    for (i = 2; i <= number / 2; i++) 
    {
        /* If remainder is 0 then it is divisible and not prime*/
        if (number % i == 0) 
        {
            printf("\n%lu is not a prime number\n", number);
            return 0;
        }
    }

    printf("\n%lu is a prime number\n", number);
    return 0;
}
