/**
*	BOJ
*	No.1871	좋은 자동차 번호판
*	@author	peter9378
*	@date		2020.04.23
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

char arr[33];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int counting = 0;
		int a = 0, b = 0;
		cin >> arr;
		a = (arr[0] - 'A') * 26 * 26 + (arr[1] - 'A') * 26 + (arr[2] - 'A');
		b += (arr[4] - 48) * 1000 + (arr[5] - 48) * 100 + (arr[6] - 48) * 10 + (arr[7] - 48);
		if (abs(a - b) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}

	return 0;
}