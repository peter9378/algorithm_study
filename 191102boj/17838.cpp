/**
*	BOJ
*	No.17838	Ä¿¸Çµå
*	@author	peter9378
*	@date		2019.11.02
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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
		string s;
		cin >> s;

		if (s.length() != 7)
		{
			cout << "0\n";
			continue;
		}

		set<char> ss;
		for (int i = 0; i < s.length(); i++)
			ss.insert(s[i]);

		if (ss.size() != 2)
		{
			cout << "0\n";
			continue;
		}

		if (s[0] == s[1] && s[2] == s[3] && s[0] == s[4] && s[5] == s[6])
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}