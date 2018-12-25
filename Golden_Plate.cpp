//solution by MOHIT MAROLIYA

#include<iostream>

//typedef long long int ll;
//typedef unsigned long long int ull;

using namespace std;

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int w, h;

	std::cin >> w >> h;
  std::cin >> k;

	int cnt = 0;
	for (i = 1; i <= k; i++)
	{
		cnt += (w * 2 + ((h - 2) * 2));
		w -= 4;
    h -= 4;
	}

std::cout << cnt << '\n';

	return 0;
}
