// GCD, LCD
#include <stdio.h>

int main()
{
    int gcd,lcd,num1, num2,i=1,o;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1, &num2);
    printf("Enter 1 for GCD and 2 for LCD");
    scanf("%d", &o);

    switch(o)
    {
    case 1:
    {
    for(i=1;i<num1 && i<num2;i++)
    {
        if(num1%i==0 && num2%i==0)
        {
            gcd=i;
        }
    }
    printf("The greatest common divisor is: %d",gcd);
    break;
}
case 2:
{
 for(i=2;i<num1 && i<num2;i++)
    {
        if(num1%i==0 && num2%i==0)
        {
            lcd=i;
            break;
        }
    }
    if(lcd==-1)
    {
        printf("No Common Divisor");
    }
    else
{
    printf("\nLeast Common Divisor is: %d",lcd);
}
break;
}
}
}