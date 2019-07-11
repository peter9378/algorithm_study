/**
*	BOJ
*	No.2747	피보나치 수
*	@author	peter9378
*	@date		2019.07.11
*/
#include <iostream>
#include <algorithm>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int a = 0, b = 1;
	N--;
	if (N == -1)
	{
		cout << 0;
		return 0;
	}
	while (N--)
	{
		int temp = a;
		a = b;
		b = a + temp;
	}

	cout << b;

	return 0;
}
