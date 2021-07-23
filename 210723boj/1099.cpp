/**
*	BOJ
*	No.1099	알 수 없는 문장
*	@author	peter9378
*	@date		2021.07.23
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

#define MAX 26

string arr[MAX * 2];
int alpha[MAX * 2];
int cnt[MAX * 2][MAX];

bool compare(int* a, int* b)
{
	for (int i = 0; i < MAX; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int n;
	cin >> s >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		for (auto w : arr[i])
			cnt[i][w - 'a']++;
	}

	fill(alpha, alpha + 51, 987654321);
	alpha[0] = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int temp[MAX] = {};
		for (int j = i; j >= 0; j--)
		{
			temp[s[j] - 'a']++;
			for (int k = 0; k < n; k++)
			{
				if (compare(temp, cnt[k]))
				{
					int best = 0;
					for (int z = j; z <= i; z++)
					{
						if (arr[k][z - j] != s[z])
							best++;
					}

					alpha[i + 1] = min(alpha[i + 1], alpha[j] + best);
				}
			}
		}
	}

	if (alpha[s.size()] == 987654321)
		alpha[s.size()] = -1;
	cout << alpha[s.size()];

	return 0;
}
