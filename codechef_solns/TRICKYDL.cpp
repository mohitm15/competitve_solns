//February Lunch Time 2019-Problem 2
//By mohit maroliya

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,a,i,j,max,sum,s;
    cin>>t;
    for(long int a0=0;a0<t;a0++)
    {
        cin>>a;
        sum=0;s=0;
        max=0;
        for(i=0;sum>s-1;i++)
        {
            sum+=a;
            s+=pow(2,i);
            if(sum-s>max)
            {
                max=sum-s;
                j=i;
            }
        }
        cout<<i-1<<" "<<j+1<<"\n";
    }
    return 0;
}
