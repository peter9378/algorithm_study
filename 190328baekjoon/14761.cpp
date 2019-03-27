/**
*	baekjoon online judge
*	No. 14761	FizzBuzz
*	@author	peter9378
*	@date		2019.03.28
*/
#include <iostream>
using namespace std;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	short X, Y, N;
	cin >> X >> Y >> N;

	for (int i = 1; i <= N; i++)
	{
		if (i%X && i%Y)
			cout << i;
		if (i%X == 0)
			cout << "Fizz";
		if (i%Y == 0)
			cout << "Buzz";
		cout << "\n";
	}

	return 0;
}