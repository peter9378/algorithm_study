/**
*	BOJ
*	No.9527	1의 개수 세기
*	@author	peter9378
*	@date		2020.08.04
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

long long go(long long a)
{
	long long save = ++a, target = 1, result = 0;

	while (save)
	{
		if (a & target)
			result += a % target + (a - a % (target * 2)) / 2;
		else
			result += (a - a % target) / 2;
		target *= 2;
		save /= 2;
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;
	cout << go(B) - go(A - 1);

	return 0;
}