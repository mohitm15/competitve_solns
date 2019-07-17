// Problem 3 : July Long Challenge 2019
// By Mohit Maroliya

#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) 
{ 
    // base case 
    if (n == 0) 
        return 0; 
    else
        return 1 + countSetBits(n & (n - 1)); 
} 

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,p;
	    set<int> s;
	    stack<int> v;
	    int result = 0;
	    int c = 0;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>p;
	       
	        if(s.count(p)==0)
	        {
	            c=0;
	            for(auto x : s)
	            {
	                int y = x^p;
	                v.push(y);
					//cout<<"Now"<<'\n';
	            }

	            s.insert(p);
	            while(!v.empty())
	            {
	                int e = v.top();
	                v.pop();
	                s.insert(e);
	            }
	           
	            for(auto x : s)
	            {
					//cout<<"then"<<'\n';
	                int w = countSetBits (x);
	                if(w%2==0)
	                c++;
	            }
	            
	            cout<<c<<" "<<s.size()-c<<endl;
	            
	        }
	        else
	        {
	            cout<<c<<" "<<s.size()-c<<endl;
	        }
	        
	    }
	    
	}
	return 0;
}
