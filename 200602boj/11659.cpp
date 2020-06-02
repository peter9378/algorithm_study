/**
*	BOJ
*	No.11659	구간 합 구하기 4
*	@author	peter9378
*	@date		2020.06.02
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

	int N, M;
	cin >> N >> M;

	vector<int> v(N + 1);
	v[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		v[i] = temp + v[i - 1];
	}


	while (M--)
	{
		int i, j;
		cin >> i >> j;
		cout << v[j] - v[i - 1] << "\n";
	}

	return 0;
}