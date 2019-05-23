// May Cook-Off 2019 : Problem 1
// By Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int r,c,cnt=0;
		std::cin >> r>>c;
		int a[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			std::cin >> a[i][j];
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if((i==0 && j==0) || (i==0 && j==c-1) || (i==r-1 && j==0) || (i==r-1 && j==c-1))
				{
					if(a[i][j]>=2)
					{
						cnt++;
						//std::cout << "cond1" << '\n';
						break;
					}
				}
				else if((i==0) || (j==0) || (i==r-1) || (j==c-1))
					{
						if(a[i][j]>=3)
						{
							cnt++;
							//std::cout << "cond2" << '\n';
							break;
						}
					}
				else
				{
						if(a[i][j]>=4)
						{
							cnt++;
							//std::cout << "cond3" << '\n';
							break;
						}
				}
			}
			if(cnt>0)
			break;
		}
		//std::cout << "cnt=" << cnt<<'\n';
		if(cnt>0)
		std::cout << "Unstable" << '\n';
		else
		std::cout << "Stable" << '\n';
	}
	return 0;
}
