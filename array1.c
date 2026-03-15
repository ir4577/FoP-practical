#include <stdio.h>

int main()
{
    int arr[10],i,even=0,odd=0;
    for(i=0;i<10;i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }
    for(i=0;i<10;i++)
    {
        if(arr[i]%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("The number of even values are: %d",even);
    printf("The number of odd values are:  %d",odd);
}