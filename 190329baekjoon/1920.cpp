/**
*	baekjoon online judge
*	No. 1920	수 찾기
*	@author	peter9378
*	@date		2019.03.29
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool binary_search(int left, int right, int target)
{
	int mid = (left + right) / 2;
	bool flag;

	if (left > right)
		return false;
	else
	{
		if (arr[mid] > target)
			flag = binary_search(left, mid - 1, target);
		else if (arr[mid] < target)
			flag = binary_search(mid + 1, right, target);
		else
			return true;
	}
	return flag;
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int M;
	cin >> M;
	
	sort(arr, arr + N);

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		int left = 0, right = N - 1, mid;

		if (binary_search(left, right, temp))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}