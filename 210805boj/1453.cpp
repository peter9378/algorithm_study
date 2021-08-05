/**
*	BOJ
*	No.1453	피시방 알바
*	@author	peter9378
*	@date		2021.08.05
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

bool arr[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (arr[temp])
			answer++;
		else
			arr[temp] = true;
	}

	cout << answer;

	return 0;
}
