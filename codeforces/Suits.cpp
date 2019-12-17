// contest: Codeforces Round #608 (Div. 2), problem: (A) Suits, Accepted, 
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
 
int min(int x,int y)
{
    int ans;
    x<y?ans = x:ans = y;
    return ans;
}
 
int main()
{
    int t,s,v,j,e,f,res=0;
    cin>>t>>s>>v>>j>>e>>f;
    int mini = min(s,v);
    if(j<=mini && j<=t)
    {
        if(e>=f)
        {
            //cout<<"j<mini && j<t && e>=f"<<endl;
            res = e*j;
        }
        else
        {
           // cout<<"j<mini && j<t && e<f"<<endl;
            res = f*j;
        }
    }
    else if(j>mini && j<=t)
    {
        if(f>e)
        {
           // cout<<"j>mini && j<t && e<f"<<endl;
            res = f*(mini)+ e*(j-mini);
        }
        else
        {
          //  cout<<"j>mini && j<t && e>=f"<<endl;
            res = e*j;
        }
    }
    else if(j>t && j<=mini)
    {   
        if(e>f)
        {
          //  cout<<"j<mini && j>t && e>f"<<endl;
            res = e*(t) + f*(j-t);
        }
        else
        {
          //  cout<<"j<mini && j>t && e<f"<<endl;
            res = f*(j);
        }
    }
    else if(j>t && j>mini)
    {
        if((mini + t)<=j)
        {
            if(t > mini)
            {
                if(e>f)
                {
               //  cout<<"j>(mini+t) && mini<t && e>f "<<endl;
                 res = t*e + mini*f;   
                }
                else
                {
                   // cout<<"j>(mini+t) && mini<t && e<=f "<<endl;
                    res = t*e + mini*f;
                }
                
            }
            else 
            {
                if(e>f)
                {
                 //   cout<<"j>(mini+t) && mini>t  && e>f"<<endl;
                    res = t*e + mini * f;
                }
                else
                {
                  //  cout<<"j>(mini+t) && mini>t  && e<=f"<<endl;
                    res = t*e + mini * f;                    
                }
            }
        }
        else // j<(mini + t)
        {
            if(t > mini)
            {
                if(e>f)
                {
               //  cout<<"j<(mini+t) && mini<t && e>f"<<endl;   
                 res = t*e +(j-t)*f;
                }
                else
                {
                 //   cout<<"j<(mini+t) && mini<t && e<=f"<<endl;
                    res = mini*f +(j-mini)*e;
                }
            }
            else
            {
                if(e>f)
                {
                  //cout<<"j<(mini+t) && mini>t && e>f"<<endl;  
                  res = t*e + (j-t)*f; 
                }
                else
                {
                   // cout<<"j<(mini+t) && mini>t && e<=f"<<endl;
                    res = f*mini + (j-mini)*e;
                }
                
            }
        }
        
    }
    cout<<res<<endl;
    return 0;
}
