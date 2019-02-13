//Feb Long Challenge 2019- Problem 02
//By Mohit Maroliya


#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

void commonCharacters(string str[], int n)
{
	// primary array for common characters
	// we assume all characters are seen before.
	bool prim[MAX_CHAR];int cnt=0;
	memset(prim, true, sizeof(prim));

	// for each string
	for (int i = 0; i < n; i++) {

		// secondary array for common characters
		// Initially marked false
		bool sec[MAX_CHAR] = { false };

		// for every character of ith string
		for (int j = 0; str[i][j]; j++) {

			// if character is present in all
			// strings before, mark it.
			if (prim[str[i][j] - 'a'])
				sec[str[i][j] - 'a'] = true;
		}

		// copy whole secondary array into primary
		memcpy(prim, sec, MAX_CHAR);
	}

	// displaying common characters
	for (int i = 0; i < 26; i++)
		if (prim[i])
    cnt+=1;
			std::cout << cnt << '\n';
}

// Driver's Code
int main()
{
int t;
std::cin >> t;
while(t--)
{
   int n;
   std::cin >> n;
   std::string str[n];
   for(int i=0;i<n;i++)
   std::cin >> str[i];
	commonCharacters(str, n);
}
	return 0;
}
