//DAY 17

#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
struct Calculator 
{
    static int power(const int n_, const int p_) 
    {
        if ( n_ < 0 || p_ < 0 ) 
        { throw std::invalid_argument("n and p should be non-negative");}
        return pow(n_, p_);
    }
};
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
