/**
*	BOJ
*	No.1789	수들의 합
*	@author	peter9378
*	@date		2021.01.14
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

	long long S;
	cin >> S;

	int temp = 1, answer = 0;
	long long sum = 0;
	while (true)
	{
		sum += temp;
		answer++;

		if (sum > S)
		{
			answer--;
			break;
		}

		temp++;
	}

	cout << answer;

	return 0;
}
