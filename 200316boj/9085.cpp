/**
*	BOJ
*	No.9085	¥ı«œ±‚
*	@author	peter9378
*	@date		2020.03.16
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

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		int answer = 0;
		while (N--)
		{
			int temp;
			cin >> temp;
			answer += temp;
		}

		cout << answer << "\n";
	}

	return 0;
}