/**
*	Code Forces
*	#570 C.	Computer Game
*	@author	peter9378
*	@date		2019.06.28
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

	while (T--)
	{
		long long k, n, a, b;
		cin >> k >> n >> a >> b;

		if (k <= n*b)
			cout << "-1\n";
		else
			cout << min((k - 1 - n*b) / (a - b), n) << "\n";
	}

	return 0;
}