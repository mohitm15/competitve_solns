#include<stdio.h>

int main(void)
{
    int t,n,test,f,zero,one,i;
    scanf("%d",&t);
    while(t--)
    {
        f = 1;
        zero = one = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&test);
            if(test==0)
                zero++;
            else
                one++;
            if(zero>one)
                f = 0;
        }
        if(f)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
