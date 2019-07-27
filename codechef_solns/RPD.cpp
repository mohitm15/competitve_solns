//Codechef : July LunchTime 2019: Problem 1
// Byb Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ull unsigned long long int

 int getSum(int n) 
 { 
    int sum; 
  
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
  
    return sum; 
 }
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ull n;
        cin>>n;
        ull a[n];
        ull sum,max=0,pro;
        f(i,n)
        {
            cin>>a[i];
        }
        f(i,n)
        {
            for(int j=i+1;j<n;j++)
            {
                pro=a[i]*a[j];
                //cout<<"pro= "<<pro<<endl;
                sum=getSum(pro);
                //cout<<"sum"<<sum<<endl;
                if(sum>=max)
                max=sum;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
