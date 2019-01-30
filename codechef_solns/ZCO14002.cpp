//By Mohit Maroliya


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

long long sup(vector<long long> &v, ll index, map<long long, long long> &memo)
{
	if(index > v.size()-1)
  return -1;
	if(index == v.size()-1 or index == v.size()-2 or index == v.size()-3)
  return v[index];
	if(memo.find(index) != memo.end())
  return memo[index];
	ll tmp = v[index] + min(sup(v, index+1, memo), min(sup(v, index+2, memo), sup(v, index+3, memo)));
	memo[index] = tmp;
	return tmp;
}

int main(void)
{
	ll n, tmp;
  cin >> n;
	vector<long long> v;
	map<long long, long long> memo;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
    v.push_back(tmp);
	}

	cout << min(sup(v, 0LL, memo), min(sup(v, 1LL, memo), sup(v, 2LL, memo))) << endl;
}
