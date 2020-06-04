/**
*	BOJ
*	No.11966	2의 제곱인가?
*	@author	peter9378
*	@date		2020.06.04
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

	int N;
	cin >> N;

	while (true)
	{
		if (N == 1)
		{
			cout << 1;
			break;
		}
		if (N % 2)
		{
			cout << 0;
			break;
		}
		N /= 2;
	}

	return 0;
}