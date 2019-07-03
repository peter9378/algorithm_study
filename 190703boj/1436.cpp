/**
*	BOJ
*	No.1436	영화감독 숌
*	@author	peter9378
*	@date		2019.07.03
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	int count = 0;
	int target = 666;
	while (count != N)
	{
		if (to_string(target).find("666") != string::npos)
		{
			count++;
		}
		target++;
	}

	cout << target-1;

	return 0;
}