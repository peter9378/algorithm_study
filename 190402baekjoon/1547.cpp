/**
*	baekjoon online judge
*	No. 1547	공
*	@author	peter9378
*	@date		2019.04.02
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[4] = { 0, 1, 0, 0 };

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		swap(arr[a], arr[b]);
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[i])
			cout << i;
	}
	return 0;
}