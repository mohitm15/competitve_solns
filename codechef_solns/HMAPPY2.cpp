//By Mohit Maroliya
//February Long Challenge '19 : Problem-1


#include <iostream>
#include <numeric>
#include<cmath>
using namespace std;
//typedef long long long long;
class gfg
{
 public : int gcd(long int a,long int b)
 {
    // Everything divides 0
    if (a == 0 || b == 0)
        return 0;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
 }


// Function to return LCM of two numbers
  int lcm(long int a,long int b)
 {
    return (a*b)/gcd(a, b);
 }
} ;
int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		long long n,k;
		long int a ,b,c,cnt1,cnt2,cnt3,res;
		std::cin >> n >> a >> b >> k;
		cnt1=n/a;
		cnt2=n/b;
		gfg g;
		if((a>b)&&(a % b ==0))
		res=cnt1-cnt2;
		else if((a<=b)&&(b % a ==0))
		res=cnt2-cnt1;
		else
		{
			cnt3=n/(g.lcm(a,b));
		//if(n % a == 0)
		  cnt1-=cnt3;
		//if(n % b == 0)
		  cnt2-=cnt3;
			res=cnt1+cnt2;
		}
		//if(n % (a*b) == 0)
		//cnt3--;
		//std::cout << cnt1 << '\n';
		//std::cout << cnt2 << '\n';
		//std::cout << cnt3 << '\n';
		res=abs(res);
	//	std::cout << "res" << res << '\n';
		if((res>k)||(res==k))
		std::cout << "Win" << '\n';
		else if(res<k)
		std::cout << "Lose" << '\n';
 	}
	return 0;
}

