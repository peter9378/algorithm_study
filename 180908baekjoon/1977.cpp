/**
*	baekjoon online judge
*	No. 1977	완전제곱수
*	@author	peter9378
*	@date		2018.09.08
*/
#include <iostream>
using namespace std;

int arr[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	for (int i = 0; i*i <= 10000; i++)
		arr[i] = i * i;

	int sum = 0, min;
	bool flag = true;
	for (int i = 0; i < 101; i++)
	{
		if (arr[i] >= M && arr[i] <= N)
		{
			sum += arr[i];
			if (flag)
			{
				min = arr[i];
				flag = false;
			}
		}
	}

	if (sum)
		cout << sum << '\n' << min;
	else
		cout << "-1";

	return 0;
}