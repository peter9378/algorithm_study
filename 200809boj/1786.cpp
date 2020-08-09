/**
*	BOJ
*	No.1786	Ã£±â
*	@author	peter9378
*	@date		2020.08.09
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

string T, P;
vector<int> match(const string &N)
{
	int M = N.size();
	vector<int> pi(M, 0);
	int begin = 1, matched = 0;

	while (begin + matched < M)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}


vector<int> kmp(const string &H, const string &N)
{
	int m = N.size();

	vector<int> result;
	vector<int> pi = match(N);
	int matched = 0;

	for (int i = 0; i < H.size(); i++)
	{
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if (H[i] == N[matched])
		{
			matched++;
			if (matched == m)
			{
				result.push_back(i - m + 2);
				matched = pi[matched - 1];
			}
		}
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, T);
	getline(cin, P);
	vector<int> result = kmp(T, P);
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}