/**
*	baekjoon online judge
*	No. 11021 A+B-7
*	@author	peter9378
*	@date		2018.04.19
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int a, b;
		cin >> a >> b;

		cout << "Case #" << test_case + 1 << ": " << a + b << "\n";
	}

	return 0;
}