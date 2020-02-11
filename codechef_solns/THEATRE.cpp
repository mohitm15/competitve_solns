//  February Challenge 2020 Division 2 » The Theatre Problem 
#include<bits/stdc++.h>
using namespace std;

#define next cout<<endl;

int maxi(int a,int b)
{
    int ans;
    if(a>=b)
        ans =a;
    else
        ans =b;
    return ans;
}

int mini(int a,int b)
{
    int ans;
    if(a>b)
        ans =b;
    else
        ans =a;
    return ans;
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int main()
{
    int tt,sum=0;
    cin>>tt;
    while(tt--)
    {
        int n;
        int subsum=0;
        cin>>n;
        if(n==0)
        subsum = -400;
        else
        {
            int mat[4][4];
            memset(mat,0,sizeof(mat));
            for(int i=0;i<n;i++)
            {
                pair<char,int> p;
                cin>>p.first>>p.second;
                if(p.first == 'A')
                {
                    if(p.second == 12)
                        mat[0][0]++;
                    else if(p.second == 3)
                        mat[1][0]++;
                    else if(p.second == 6)
                        mat[2][0]++;
                    else if(p.second == 9)
                        mat[3][0]++;
                }
                else if(p.first == 'B')
                {
                    if(p.second == 12)
                        mat[0][1]++;
                    else if(p.second == 3)
                        mat[1][1]++;
                    else if(p.second == 6)
                        mat[2][1]++;
                    else if(p.second == 9)
                        mat[3][1]++;
                }
                else if(p.first == 'C')
                {
                    if(p.second == 12)
                        mat[0][2]++;
                    else if(p.second == 3)
                        mat[1][2]++;
                    else if(p.second == 6)
                        mat[2][2]++;
                    else if(p.second == 9)
                        mat[3][2]++;
                }
                else if(p.first == 'D')
                {
                    if(p.second == 12)
                        mat[0][3]++;
                    else if(p.second == 3)
                        mat[1][3]++;
                    else if(p.second == 6)
                        mat[2][3]++;
                    else if(p.second == 9)
                        mat[3][3]++;
                }
            }
            //matrix print 
            // for(int j=0;j<4;j++)
            // {
            //     for(int i=0;i<4;i++)
            //     cout<<mat[i][j]<<" ";
            //     next;
            // }
            int cntzero=0;
            vector<pair<char,int>> v;
            int indmark[4] = {0,0,0,0};
            for(int i=0;i<4;i++)
            {
                int mxcol=-1,index;
                //cout<<"for col "<<i<<" : ";
                //har col ka max nikala
                for(int j=0;j<4;j++)
                {
                    //cout<<mat[i][j]<<" ";
                    if(mxcol<mat[i][j] && (indmark[j]==0))
                    {
                        mxcol = mat[i][j];
                        index = j;
                        
                    }
                    //mxcol = maxi(mxcol,mat[i][j]);
                    //index = -1;
                }
                if(mxcol>0)
                    indmark[index]=1;
                if(mxcol==0)
                    cntzero++;
                // cout<<"indmark = ";
                // for(int k=0;k<4;k++)
                //     cout<<indmark[k]<<" ";
                // next;
                if(index == 0)
                    v.push_back(make_pair('A',mxcol));
                    //cout<<"A -"<<mxcol<<endl;
                else if(index == 1)
                    v.push_back(make_pair('B',mxcol));
                    //cout<<"B -"<<mxcol<<endl;                cout<<"B -"<<mxcol<<endl;
                else if(index == 2)
                    v.push_back(make_pair('C',mxcol));
                    //cout<<"C -"<<mxcol<<endl;
                else if(index == 3)
                    v.push_back(make_pair('D',mxcol));
                    //cout<<"D -"<<mxcol<<endl;         
            }
            // for(int i=0;i<4;i++)
            // {
            //     cout<<v[i].first<<" "<<v[i].second<<endl;
            // }
            sort(v.begin(),v.end(), sortbysec);
            int paisa =25;
            for(int i=0;i<4;i++)
            {
                subsum+=(v[i].second)*paisa;
                //cout<<subsum<<endl;
                paisa+=25;
            }
            subsum = subsum - (100*cntzero);
        }
        cout<<subsum<<endl;
        sum+=subsum;
    }
    cout<<sum<<endl;
    return 0;
}
