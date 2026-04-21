#include <stdio.h>
int main()
{
    int A[10][10],B[10][10],C[10][10];
    int i,j,r,c,n;
    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);
    printf("Enter Matrix A:\n");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter Matrix B:\n");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("Addition:\n");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    int found=0;
    for (i=0;i<r;i++)
    {
        int min=A[i][0],col=0;
        for (j=1;j<c;j++)
        {
            if (A[i][j]<min)
            {
                min=A[i][j];
                col=j;
            }
        }
        int flag=1;
        for (int k=0;k<r;k++)
        {
            if (A[k][col]>min)
            {
                flag=0;
                break;
            }
        }
        if (flag)
        {
            printf("Saddle Point = %d\n",min);
            found=1;
        }
    }
    if (!found)
    {
        printf("No Saddle Point\n");
    }
    int M[2][2];
    float det;
    printf("Enter 2x2 matrix:\n");
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    det=M[0][0]*M[1][1]-M[0][1]*M[1][0];
    if (det==0)
    {
        printf("Inverse not possible\n");
    }
    else 
    {
        printf("Inverse:\n");
        printf("%.2f %.2f\n",M[1][1]/det,-M[0][1]/det);
        printf("%.2f %.2f\n",-M[1][0]/det,M[0][0]/det);
    }
    int sum=0,temp;
    printf("Enter order of square matrix: ");
    scanf("%d",&n);
    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(j=0;j<n;j++)
    {
        sum+=A[0][j];
    }
    for(i=0;i<n;i++) 
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            temp+=A[i][j];
        }
        if(temp!=sum) 
        {
            printf("Not Magic Square\n");
            return 0;
        }
    }
    for(j=0;j<n;j++)
    {
        temp=0;
        for(i=0;i<n;i++)
        {
            temp+=A[i][j];
        }
        if(temp!=sum) 
        {
            printf("Not Magic Square\n");
            return 0;
        }
    }
    temp=0;
    for(i=0;i<n;i++)
    {
        temp+=A[i][i];
    }
    if(temp!=sum) 
    {
        printf("Not Magic Square\n");
        return 0;
    }
    temp=0;
    for(i=0;i<n;i++)
    {
        temp+=A[i][n-i-1];
    }
    if(temp!=sum)
    {
        printf("Not Magic Square\n");
        return 0;
    }
    printf("Magic Square\n");
    return 0;
}
