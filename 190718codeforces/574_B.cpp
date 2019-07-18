/**
*	Code Forces
*	#574 B.	Sport Mafia
*	@author	peter9378
*	@date		2019.07.18
*/
#include <iostream>
#include <algorithm>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long  n, k;
	cin >> n >> k;

	if (n == 1 && k == 1)
	{
		cout << 0;
		return 0;
	}

	long long  left = 0;
	long long  right = n - 1;
	long long mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;

		long long value = ((n - mid)*(n - mid + 1) / 2) - mid;
		if (value == k)
		{
			cout << mid;
			break;
		}
		else if (value > k)
			left = mid + 1;
		else if (value < k)
			right = mid - 1;
	}

	return 0;
}