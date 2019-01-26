//By  Mohit Maroliya

#include <iostream>
#include<cstring>
using namespace std;
// string strOne = " not ";
int main(int argc, char* argv[])
{
  int t;
  std::cin >> t;
  string str,s;
  getline(cin,s);
  while(t--)
  {
      getline(cin,str);
      string str1=" not ",str4="not ",str5=" not";
      int a=str.length(),b=str.find(str1),c=str.find(str4),d=str.find(str5);;
      if(c>=0 || b>=0 || ((a-d)==4))
      std::cout << "Real Fancy" << '\n';
      else
      std::cout << "regularly fancy" << std::endl;
  }
   return 0;
}
