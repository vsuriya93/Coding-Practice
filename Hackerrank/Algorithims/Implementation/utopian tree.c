#include<stdio.h>
#include<stdlib.h>
int getval(int n)
    {
    int height=1;
    if(n==0)
        return 1;
    else
        {
        int i;
        for(i=0;i<n;i++)
            {
            if(i%2==0)
                height*=2;
            else
                height+=1;
        }
    }
    return height;
}
int main()
    {
    int t,i;
    int *n,disp;
    scanf("%d",&t);
    if(!(t>=1 && t<=10) )
        {
             return -1;
        }
    n=malloc(t*sizeof(int));
    for(i=0;i<t;i++)
        {
        scanf("%d",&n[i]);
        if(!(n[i]>=0 && n[i]<=60) )
        {
             return -1;
        }
    }
    for(i=0;i<t;i++)
        {
        disp=getval(n[i]);
        printf("%d\n",disp);
    }
    
}