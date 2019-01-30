//By Mohit Maroliya
//Chewing.cpp  :ZCO Practice Contest

#include<iostream>
#include <cmath>  
#include<cstdio>
#include <algorithm>
#include <vector>
#define gc getchar
using namespace std;
void scanint(long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	long long N,K;
	scanint(N);
	scanint(K);
	long hardness[N];
	long long i,j,tmp,c=0;
	long long pairCount = 0;

	for(i=0;i<N;++i)
	{
		scanint(tmp);
		if(tmp<K)
		{
			hardness[c]=tmp;
			c++;
		}		
	}
	sort(hardness,hardness+c);
 	for(i=0,j=c-1;i<j; )
    {
        
		if( hardness[i]+hardness[j]<K)
        {
         	pairCount += j-i;
            i++;
        }
        else
        {
            j--;
        }
 	}
   	cout<<pairCount;
	return 0;
}
