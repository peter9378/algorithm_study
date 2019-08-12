/**
*	Code Forces
*	#578 B.	Block Adventure
*	@author	peter9378
*	@date		2019.08.12
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long int arr[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		long long int n, m, k;
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int i;
		for (i = 0; i < n - 1; i++)
		{
			if (arr[i + 1] - arr[i] > k)
			{
				m -= (arr[i + 1] - arr[i] - k);
				if (m < 0)
					break;
			}
			else
			{
				if (k > arr[i + 1])
					m += arr[i];
				else
					m += (arr[i] - arr[i + 1] + k);
			}
		}
		if (i == n - 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}