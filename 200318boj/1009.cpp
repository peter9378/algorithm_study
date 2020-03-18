/**
*	BOJ
*	No.1009	분산처리
*	@author	peter9378
*	@date		2020.03.18
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

int calc(int base, int index)
{
	int result = 1;
	while (index != 0)
	{
		if (index & 1)
			result = (result*base) % 10;
		base = base * base % 10;
		index >>= 1;
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;

		int answer = calc(a, b);
		if (answer == 0)
			cout << "10\n";
		else
			cout << answer << "\n";
	}

	return 0;
}