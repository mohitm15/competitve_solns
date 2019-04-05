//April Long Challenge 2019: Problem 1 : Partially accepted

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	std::cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	std::cin >> a[i];
	//sort(a,a+n);
	int max=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]!=0 && a[j]!=0)
			{
				if((a[j]%a[i])>=(a[i]%a[j]))
					{
						if(max<(a[j]%a[i]))
						max=a[j]%a[i];
						//std::cout << "maxif=" << max<<'\n';
					}
				else
				   {
						 if(max<(a[i]%a[j]))
						 max=a[i]%a[j];
						 //std::cout << "maxelse=" << max<<'\n';
					 }
			}
			// else
			//   break;
		}
	}
	std::cout << max << '\n';
	return 0;
}
