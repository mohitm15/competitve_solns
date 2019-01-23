#include <iostream>

using namespace std;
int parent [2005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            int x;
           cin>>x;
        parent[i]=x;
    }

    // find the depth of tree
    // root of tree has parent -1
    int depth=-1;
    for(int i=1;i<=n;i++){
            int nodecount=1;
            int x=i;// ith node that we are starting with is the first node
        while(parent[x]!=-1){
            x=parent[x];
    nodecount++;
        }
        depth=max(depth,nodecount);
    }
    cout<<depth<<endl;


    return 0;
}
