/**
*	BOJ
*	No.1920	¼ö Ã£±â
*	@author	peter9378
*	@date		2019.11.10
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;

		int left = 0;
		int right = N - 1;
		int mid;
		bool flag = true;

		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target < arr[mid])
				right = mid - 1;
			else if (target > arr[mid])
				left = mid + 1;
			else
			{
				cout << "1\n";
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "0\n";
	}

	return 0;
}