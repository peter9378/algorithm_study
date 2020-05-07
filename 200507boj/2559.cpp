/**
*	BOJ
*	No.2559	¼ö¿­
*	@author	peter9378
*	@date		2020.05.07
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

int arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int answer = -987654321;
	int sum = 0;
	for (int i = 0; i < K; i++)
		sum += arr[i];
	answer = max(answer, sum);
	for (int i = K; i < N; i++)
	{
		sum += (arr[i] - arr[i - K]);
		answer = max(answer, sum);
	}

	cout << answer;

	return 0;
}