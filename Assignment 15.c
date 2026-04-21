#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,n;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d",&n);
    srand(time(0));
    printf("Pseudo-random numbers are:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\n",rand() % 900000+100000);
    }
}
