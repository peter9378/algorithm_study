/**
*	Code Forces
*	#569 B.	Nick and Array
*	@author	peter9378
*	@date		2019.06.22
*/
#include <iostream>
using namespace std;

int arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int n;
	cin >> n;

	// update all data
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] >= 0)
			arr[i] = -arr[i] - 1;
	}

	// in odd case, find the max value O(N)
	if (n % 2)
	{
		int max = -1, index;
		for (int i = 0; i < n; i++)
		{
			if (max > arr[i])
			{
				max = arr[i];
				index = i;
			}
		}

		// check if there 0
		if (max == -1)
			arr[0] = 0;
		// reverse the max value to make positive
		else
			arr[index] = -arr[index] - 1;
	}

	// print answer
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}