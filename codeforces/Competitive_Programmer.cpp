
// contest: Codeforces Global Round #6 (Div. 2), problem: (A) ,Competitive Programmer, Accepted, 
// BY :
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int zero=0,sum=0;
        bool flag2=false;
        bool flag3=false;
        bool flag6=false;
        for(auto c:s)
        {
            //cout<<c<<endl;
            if(c=='0')
            {
                zero++;
            }
            sum+=c-48;
            if(c%2 ==0 && c!='0')
            flag2=true;
        }
        //cout<<s[s.length()-1]<<"--";
        if(zero>1)
        flag2=true;
        if(sum%3 == 0)
        flag3=true;
        if(flag3==true && flag2==true)
        flag6=true;
        //cout<<sum<<endl;
        //cout<<"flag2="<<flag2<<" flag3="<<flag3<<endl;
        if(zero>=1 && flag6==true)
        cout<<"red"<<endl;
        else
        cout<<"cyan"<<endl;
    }
    return 0;
}
