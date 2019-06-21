/**
*	baekjoon online judge
*	No. 1011	Fly me to the Alpha Centauri
*	@author	peter9378
*	@date		2019.06.21
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		long long x, y;
		cin >> x >> y;

		long long answer = 0, distance = y - x;
		long long pivot, min, max;

		for (long long i = 1;; i++)
		{
			pivot = i*i;
			min = pivot - i + 1;
			max = pivot + i;

			if (min <= distance && distance <= max)
			{
				if (min <= distance && distance <= pivot)
					answer = i * 2 - 1;
				else
					answer = i * 2;
				break;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}