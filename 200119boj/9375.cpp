/**
*	BOJ
*	No.9375	패션왕 신해빈
*	@author	peter9378
*	@date		2020.01.19
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
		int n;
		cin >> n;

		map<string, int> m;
		for (int i = 0; i < n; i++)
		{

			string a, b;
			cin >> a >> b;

			if (m.find(b) == m.end())
				m.insert({ b, 1 });
			else
				m[b]++;
		}

		int answer = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++)
			answer *= iter->second + 1;

		cout << --answer << "\n";
	}

	return 0;
}
