#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
        {
           for(k=n-1;k>i;k--)
               printf(" ");
           for(j=0;j<=i;j++)
               printf("#");
           printf("\n");
    }
    return 0;
}
