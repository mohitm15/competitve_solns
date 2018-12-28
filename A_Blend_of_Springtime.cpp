//contest: Codeforces Round #487 (Div. 2), problem: (A) A Blend of Springtime, Accepted, #
 #include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long int ll;


//Int data type
#define sc1(a)              scanf("%d", &a)
#define sc2(a, b)           scanf("%d %d", &a, &b)
#define sc3(a, b, c)        scanf("%d %d %d", &a, &b, &c)
#define sc4(a, b, c, d)     scanf("%d %d %d %d", &a, &b, &c, &d)

//Long Data type
#define scl1(a)             scanf("%lld", &a)
#define scl2(a, b)          scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)       scanf("%lld %lld %lld", &a, &b, &c)
#define scl4(a, b, c, d)    scanf("%lld %lld %lld %lld", &a, &b, &c, &d)


int main()
{
     ll i,j=0,n=0,m=0,ln,t=0,a,b,c,d,ck=0,dk=0;
     string arr;
     cin>>arr;
     n = arr.size();

     for(i=0; i<n-2; i++){
        if(arr[i]=='A' && arr[i+1]=='B' && arr[i+2]=='C'){
            ck = 1;
            break;
        }
        if(arr[i]=='A' && arr[i+1]=='C' && arr[i+2]=='B'){
            ck = 1;
            break;
        }
        if(arr[i]=='B' && arr[i+1]=='A' && arr[i+2]=='C'){
            ck = 1;
            break;
        }
        if(arr[i]=='B' && arr[i+1]=='C' && arr[i+2]=='A'){
            ck = 1;
            break;
        }
        if(arr[i]=='C' && arr[i+1]=='A' && arr[i+2]=='B'){
            ck = 1;
            break;
        }
        if(arr[i]=='C' && arr[i+1]=='B' && arr[i+2]=='A'){
            ck = 1;
            break;
        }

     }
     if(ck==1)
        cout<<"Yes"<<endl;
     else
        cout<<"No"<<endl;
}
