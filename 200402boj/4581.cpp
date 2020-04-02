/**
*	BOJ
*	No.4581	Voting
*	@author	peter9378
*	@date		2020.04.02
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
#include <iterator>
#include <numeric>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string s;
		cin >> s;

		if (s == "#")
			break;

		int yes = 0, no = 0, absent = 0, all = s.length();
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'Y')
				yes++;
			else if (s[i] == 'N')
				no++;
			else if (s[i] == 'A')
				absent++;
		}
		if (absent > (s.length() - 1) / 2)
			cout << "need quorum\n";
		else if (yes == no)
			cout << "tie\n";
		else if (yes > no)
			cout << "yes\n";
		else if (yes < no)
			cout << "no\n";
	}
	return 0;
}