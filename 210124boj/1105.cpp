/**
*	BOJ
*	No.1105	ÆÈ
*	@author	peter9378
*	@date		2021.01.24
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string L, R;
	cin >> L >> R;

	int answer = 0;
	if (L.length() == R.length())
	{
		bool flag = false;
		for (int i = 0; i < L.length(); i++)
		{
			if (L[i] != R[i])
				flag = true;

			if (flag)
				continue;

			if (L[i] == R[i] && L[i] == '8')
				answer++;
		}
	}

	cout << answer;

	return 0;
}
