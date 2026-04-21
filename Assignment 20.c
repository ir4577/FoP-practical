#include <stdio.h>

void swap_simple(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("After swapping without pointers:\n");
    printf("a = %d, b = %d\n",a,b);
}
void swap_pointers(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("After swapping with pointers:\n");
    printf("a = %d, b = %d\n",*a,*b);
}
int main()
{
    int x,y;
    printf("Enter numbers for swapping: ");
    scanf("%d%d",&x,&y);
    swap_simple(x,y);
    swap_pointers(&x,&y);
}
