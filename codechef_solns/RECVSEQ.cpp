// May Cook-Off 2019 ; Problem 2
// by Mohit maroliya

#include<bits/stdc++.h>
using namespace  std;
#define f(i,n) for(int i=1;i<n;i++)
int main()
{
	int t;
	cin>>t;
	while(t--)
  {
    int n,a1,a2,a3,a4;
		cin>>n;
		int a[n],b[n],k=0;
		for(int i=0;i<n;i++)
		cin>>a[i];
		if(n>=5)
    {
		a1=a[1]-a[0];
		a2=a[2]-a[1];
		a3=a[3]-a[2];
		a4=a[4]-a[3];
		if(a1==a2)
    {
			cout<<a[0]<<" ";
			f(i,n)
      {
				cout<<a[i-1]+a1<<" ";
				a[i]=a[i-1]+a1;
			}
		}
		else if(a1==a3)
    {
			cout<<a[0]<<" ";
			f(i,n)
      {
				cout<<a[i-1]+a1<<" ";
				a[i]=a[i-1]+a1;
			}
		}
		else if(a1==a4)
    {
			cout<<a[0]<<" ";
			f(i,n){
				cout<<a[i-1]+a1<<" ";
				a[i]=a[i-1]+a1;
		}
	}
		else if(a2==a3)
    {
			cout<<a[1]-a2<<" ";
			f(i,n){
				cout<<a[i]<<" ";
				//a[i]=a[i-1]+a1;
			}
		}
		else if(a2==a4)
    {
			cout<<a[1]-a2<<" ";
			f(i,n){
				cout<<a[i]<<" ";
			}
		}
		else if(a3==a4)
    {
			a[1]=a[2]-a3;
			a[0]=a[1]-a3;
			cout<<a[0]<<" "<<a[1]<<" ";
			for(i=2;i<n;i++)
      {
				cout<<a[i-1]+a3<<" ";
				a[i]=a[i-1]+a3;
			}
		}
		cout<<endl;
	}
	else
  {
		int b1,b2,b3;
		b1=a[1]-a[0];
		b2=a[2]-a[1];
		b3=a[3]-a[2];
		if(b2==b3)
    {
			a[0]=a[1]-b2;
			cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
		}
		else if(b1==b2)
    {
			cout<<a[0]<<" "<<a[0]+b1<<" "<<a[1]+b1<<" "<<a[2]+b1;
		}
		else
    {
			int diff=(a[n-1]-a[0])/(n-1);
			cout<<a[0]<<" ";
			f(i,n)
      {
			    cout<<a[i-1]+diff<<" ";
			    a[i]=a[i-1]+diff;
		    }
		}
		cout<<endl;
	}
	}
}
