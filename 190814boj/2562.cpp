/**
*	BOJ
*	No.2562	최댓값
*	@author	peter9378
*	@date		2019.08.14
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	int max = -1;
	int max_index = -1;

	for (int i = 0; i < 9; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_index = i;
		}
	}

	cout << max << endl << max_index+1;

	return 0;
}