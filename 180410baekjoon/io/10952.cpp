/**
*	baekjoon online judge
*	No. 10952 A+B-5
*	@author	peter9378
*	@date		2018.04.19
*/
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a + b << "\n";
	}

	return 0;
}