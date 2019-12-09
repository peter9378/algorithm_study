/**
*	BOJ
*	No.2875	대회 or 인턴
*	@author	peter9378
*	@date		2019.12.09
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	cout << min(min(N / 2, M), (N + M - K) / 3);

	return 0;
}