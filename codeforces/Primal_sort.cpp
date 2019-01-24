/* 
 SOLUTIONS BY MOHIT MAROLIYA
 */
 
 #include<cstdio>
#include<algorithm>
using namespace std;

int n,tmp,Ans=1e9,f[1000010];

void Init(){
    for(int i=2;i<=n;++i){
        if(!f[i]) for(int j=2;i*j<=1000000;++j)
            f[i*j]=i;
        f[i]=i-f[i]+1;
    }       
}

int main(){
    scanf("%d",&n);
    Init();
    for(int i=f[n];i<=n;++i) Ans=min(Ans,f[i]);
    printf("%d\n",Ans);
    return 0;
}
