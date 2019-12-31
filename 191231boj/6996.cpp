/**
*	BOJ
*	No.6996	애너그램
*	@author	peter9378
*	@date		2019.12.31 - Goodbye 2019
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string a, b;
		cin >> a >> b;

		map<char, int> am, bm;
		if (a.length() != b.length())
		{
			cout << a << " & " << b << " are NOT anagrams.\n";
			continue;
		}

		for (int i = 0; i < a.length(); i++)
		{
			am[a[i]]++;
			bm[b[i]]++;
		}

		if (am == bm)
			cout << a << " & " << b << " are anagrams.\n";
		else
			cout << a << " & " << b << " are NOT anagrams.\n";
	}

	return 0;
}
