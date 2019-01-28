/* SOLUTION BY MOHIT MAROLIYA */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
 
#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200001
 
int main(){
  char s[MAXN];
  scanf("%s",s);
  int n = strlen(s);
  if (s[0]=='1'||s[n-1]=='1'){
    printf("-1\n");
    return 0;
  }
  vector<vector<int>> subs;
  vector<int> temp = {0};
  queue<int> inds;
  queue<int> inds2;
  int tot = 0, cur;
  for (int i=0;i<n;i++){
    if (s[i]=='0'&&!inds2.size()){
      temp[0] = i;
      subs.push_back(temp);
      inds.push(tot);
      tot++;
    }else if(s[i]=='0'){
      cur = inds2.front();
      inds2.pop();
      subs[cur].push_back(i);
      inds.push(cur);
    }else{
      if (inds.size()){
        cur = inds.front();
        inds.pop();
        subs[cur].push_back(i);
        inds2.push(cur);
      }else{
        printf("-1\n");
        return 0;
      }
    }
  }
  if (inds2.size()) printf("-1\n");
  else{
    printf("%d\n",subs.size());
    for (int i = 0;i<subs.size();i++){
      printf("%d ",subs[i].size());
      for (int j:subs[i]) printf("%d ",j+1);
      printf("\n");
    }
  }
}
