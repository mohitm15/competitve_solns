// Successful Submission:International Coding League 2019 -Problem 1

//By Mohit Maroliya

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,c=0;
		cin>>n;
		while(n!=0)
		{
			float k = (sqrt(n));
			k=round(k);
			//cout<<k;
			if((k*k)>n)
				k=k-1;
			n = n-(k*k);
			//cout<<n;
			c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}


//Earlier solution was time consuming so latest soln above:
