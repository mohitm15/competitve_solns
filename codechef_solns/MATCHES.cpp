//Codechef September Cook-off 2019 : Problem 1
// By MOhit Maroliya

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int p,b;
	    cin>>p>>b;
	    int sum=0,ans=0;
	    sum=p+b;
	    int a[10]={6,2,5,5,4,5,6,3,7,6};
	    while(sum!=0)
	    {
	        ans=ans+(a[sum%10]);
	        sum=sum/10;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
