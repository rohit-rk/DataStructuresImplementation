#include <stdio.h>
#include <malloc.h>
void main ( )
{
    int  i , n , sum = 0 ;
    int * a ;
    printf("\t\t\t\tARRAY SUM PROGRAM \n " ) ;
    printf(" Enter the size of array A \n " ) ;
    scanf("%d" , &n ) ;
    a = ( int *) malloc(n *sizeof (int) ) ;
    printf(" Enter Elements of the List \n " ) ;
    for( i = 0 ; i < n ; i++)
    {
        scanf ("%d" , a + i ) ;
    }
    // Compute the sum of all elements in the given array
    for( i = 0 ; i < n ; i++)
    {
        sum = sum + *( a + i ) ;
    }

    printf("Sum of all elements in array = %d\n" , sum) ;
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
