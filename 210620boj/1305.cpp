/**
*	BOJ
*	No.1305	±¤°í
*	@author	peter9378
*	@date		2021.06.20
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

int L;
string S;

vector<int> go(const string& target)
{
	int size = target.size();
	vector<int> v(size, 0);

	int start = 1, correct = 0;
	while (start + correct < size)
	{
		if (target[start + correct] == target[correct])
		{
			correct++;
			v[start + correct - 1] = correct;
		}
		else
		{
			if (correct == 0)
				start++;
			else
			{
				start += correct - v[correct - 1];
				correct = v[correct - 1];
			}
		}
	}
	return v;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> S;
	vector<int> pi = go(S);
	cout << L - pi[L - 1];

	return 0;
}
