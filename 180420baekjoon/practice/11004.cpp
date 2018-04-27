/**
*	baekjoon online judge
*	No. 11004 K번째 수
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
#include <algorithm>
using namespace std;

// 배열
long long arr[5000001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 숫자 입력
	int N, K;
	cin >> N >> K;

	// 숫자 입력
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 정렬
	sort(arr, arr + N);

	// 출력
	cout << arr[K-1];

	return 0;
}