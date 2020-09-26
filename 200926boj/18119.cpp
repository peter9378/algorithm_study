/**
*	BOJ
*	No.18119	단어 암기
*	@author	peter9378
*	@date		2020.09.26
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
using namespace std;

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (auto& a : arr)
	{
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
			a |= 1 << (s[i] - 'a');
	}

	int memory = 0x3ffffff, cmd;
	char c;
	while (M--)
	{
		cin >> cmd >> c;
		if (cmd == 1)
			memory &= ~(1 << (c - 'a'));
		else
			memory |= 1 << (c - 'a');

		int answer = 0;
		for (auto& a : arr)
		{
			if ((a == (memory&a)))
				answer++;
		}

		cout << answer << "\n";
	}

	return 0;
}