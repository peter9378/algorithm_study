/**
*	BOJ
*	No.2503	숫자 야구
*	@author	peter9378
*	@date		2020.01.12
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

vector<int> v;

void init()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				if (i == j || j == k || k == i)
					continue;
				v.push_back(i * 100 + j * 10 + k);
			}
		}
	}
}

pair<int, int> check(int a, int b)
{
	string sa = to_string(a);
	string sb = to_string(b);
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (sa[i] == sb[j])
					strike++;
			}
			else
			{
				if (sa[i] == sb[j])
					ball++;
			}
		}
	}
	return { strike, ball };
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	init();
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vector<int> temp;
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			pair<int, int> result = check(a, *iter);
			if (b == result.first && c == result.second)
				temp.push_back(*iter);
		}

		v.clear();
		v = temp;
	}

	cout << v.size();

	return 0;
}
