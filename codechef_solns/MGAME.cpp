//January Challenge 2019


#include <stdio.h>

int main()
{
    long long int t,b,i,j,n,p,k;
    scanf("%lld",&t);
    for(b=0;b<t;b++)
    {
        scanf("%lld %lld",&n,&p);
        i=(n-1)/2;
        j=(p-i)*(p-i)+(p-n)*(p-i)+(p-n)*(p-n);
        if(n==1 || n==2)
        {
            k=p*p*p;
            printf("%lld\n",k);
        }
        else
        printf("%lld\n",j);
        
    }
}
