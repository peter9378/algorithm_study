/**
*	Code Forces
*	#570 B.	Equalize Prices
*	@author	peter9378
*	@date		2019.06.27
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

void init()
{
	for (int i = 0; i < 101; i++)
		arr[i] = 0;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T;
	cin >> T;

	while (T--)
	{
		int n, k;
		cin >> n >> k;

		init();
		int min_number = 987654321, max_number = -1;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			min_number = min(min_number, arr[i]);
			max_number = max(max_number, arr[i]);
		}

		if (max_number - 2 * k > min_number)
			cout << "-1\n";
		else if ((max_number - min_number) == 2 * k)
			cout << max_number - k << "\n";
		else
			cout << min_number + k << "\n";
	}

	return 0;
}