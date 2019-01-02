#include<iostream>
using namespace std;
int main()
{
	int n,k=0,c=0,l=0,max=0;
   int pos,p,m,st;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> m;
		if(m==1)
		{
		    if(c==0){
		    st=i;
		    }
			k++;
			c++;
			if(k>max)
			{
				max=k;
				pos=i;
			}
 
		}
		else
		{
			k--;
			c++;
			if(k==0)
			{
			    if(c>l){
			     l=c;
			     p = st;
			}
			c=0;
	
		}
	}
	}
	cout << max << " " << pos << " " << l << " " << p  ;
}
