// contest: Codeforces Round #607 (Div. 2), problem: (C) Cut and Paste, Time limit exceeded

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 
int main()
{
    int t;
    cin>>t;
    for(int y=0;y<t;y++)
    {
        int x,l=0;
        string s;
        string cut="";
        cin>>x>>s;
        for(int i=1;i<=x;i++)
        {
            cut="";
            int rep = s[i-1]-48;
            for(int k=i;k<s.length();k++)
            {
                cut = cut+s[k];
            }
            //cout<<"cut = "<<cut<<endl;
            //cout<<"rep = "<<rep<<endl;
            for(int j=0;j<rep-1;j++)
            {
                s = s+cut;
            }
            //cout<<"s after append = "<<s<<endl;
 
        }
        //cout<<"STOP"<<endl;
        cout<<s.length()%MOD<<endl;
        
    }
    return 0;
}
