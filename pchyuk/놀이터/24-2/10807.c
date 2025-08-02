#include<stdio.h>

int main()
{
    int i,v,n=0;
    //printf("enter the number of integers ");
    scanf("%d",&i);
    int arr[i];

        for(int j=0; j<i;j++)
        {
            scanf("%d",&arr[j]);
        }
     
    scanf("%d",&v);
    for(int j=0; j<i;j++)
    {
        if (arr[j]==v)
        {
            n++;
        }
    }
    printf("%d",n);

    return 0;
}