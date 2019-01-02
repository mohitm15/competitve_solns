#include <stdio.h>
int main()
{
	long long int n,k;
	scanf("%lld%lld",&n,&k);
	long long int a[n];
	for (long long int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long int count=0;
	for (long long int i=0;i<n-1;i++)
	{
		for (long long int j=i+1;j<n;j++)
		{
			if (a[i]+a[j]<k)
				count++;
		}
	}
	printf("%lld\n",count);
	return 0;
}
