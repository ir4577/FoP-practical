#include <stdio.h>
int fact(int n);
int main()
{
    int n;
    printf("Enter Value :");
    scanf("%d",&n);
    printf("Factorial of %d is: %d\n", n, fact(n));
    return 0;
}

    int fact(int n)
    {
        if (n<= 1)
        {
            return 1;
        }
        {
            return n * fact(n-1);
        }
    }
