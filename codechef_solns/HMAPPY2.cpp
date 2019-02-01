//By Mohit Maroliya
//February Long Challenge '19 : Problem-1


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int n,a,b,k,cnt=0,i=0;
		std::cin >> n>>a>>b>>k;
	  while(i<n)
		{
			if((((i+1)%a)==0)||(((i+1)%b)==0))
			cnt+=1;
			if((((i+1)%a)==0)&&(((i+1)%b)==0))
			cnt-=1;
			i++;
		}
		if(cnt>=k)
		std::cout << "Win" << '\n';
		else
		std::cout << "Lose" << '\n';
	}
	return 0;
}
