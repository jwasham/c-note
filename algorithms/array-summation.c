/***********************************************************
* You can use all the programs on  www.c-program-example.com
* for personal and learning purposes. For permissions to use the
* programs for commercial purposes,
* contact info@c-program-example.com
* To find more C programs, do visit www.c-program-example.com
* and browse!
*
*                       Happy Coding
***********************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,sum=0;
    int *a;

    printf("Enter the size of array A\n");
    scanf("%d", &n);

    a=(int *) malloc(n*sizeof(int));

    printf("Enter Elements of First List\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }

    /*Compute the sum of all elements in the given array*/
    for(i=0;i<n;i++)
    {
        sum = sum + *(a+i);
    }

    printf("Sum of all elements in array = %d\n", sum);

    return 0;
}