/**
*	BOJ
*	No.1431	시리얼 번호
*	@author	peter9378
*	@date		2019.12.04
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

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		int asum = 0, bsum = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] >= '1' && a[i] <= '9')
				asum += (a[i] - '0');
		}
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] >= '1' && b[i] <= '9')
				bsum += (b[i] - '0');
		}
		if (asum == bsum)
			return a < b;
		return asum < bsum;
	}
	return a.length() < b.length();
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++)
		cout << v[i] << "\n";

	return 0;
}
