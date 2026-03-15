#include <stdio.h>

int main()
{
    int arr[10], i;
    int even = 0; 
    int odd = 0;
    for(i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }
    for(i = 0; i < 10; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("\nThe number of even values are: %d\n", even);
    printf("The number of odd values are:  %d\n", odd);

    return 0;
}