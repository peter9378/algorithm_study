/**
*	BOJ
*	No.1264	모음의 개수
*	@author	peter9378
*	@date		2021.02.02
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

bool check(char target)
{
	for (int i = 0; i < 10; i++)
	{
		if (target == vowels[i])
			return true;
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string s;
		getline(cin, s);

		if (s == "#")
			break;

		int result = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (check(s[i]))
				result++;
		}

		cout << result << "\n";
	}

	return 0;
}
