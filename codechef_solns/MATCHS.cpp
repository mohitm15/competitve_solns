// May Long Challenge 2019 - Problem 2

#include <iostream>
using namespace std;

int main() {
	long long int t;
	cin>>t;
	
	while(t--)
	{
	    long long int a,b,x,y,i;
	    cin>>a>>b;
	if(a==max(a,b))
	{
	    x= a;
	    y=b;
	}
	else
	{
	    x=b;
	    y=a;
	}
	if(x/y >1)
	{
	    cout<<"Ari"<<endl;
	}
	else
	{
	for(i=0;;i++)
	{
	    x=x-(x/y)*y;
	   
	    if(x<=0)
	    {
	        
	        //cout<<i<<endl;
	        break;
	    }
	    else
	    {
	    a=x;
	    if(x!=max(a,y))
	    {
	        x=y;
	        y=a;
	    }
	    }
	    if(x/y>1)
	    {
	        i++;
	        break;
	    }
	}
	if(i%2==0)
	{
	    cout<<"Ari"<<endl;
	    
	}
	else
	{
	    cout<<"Rich"<<endl;
	}
	}
}

	return 0;
}
