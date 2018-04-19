/**
*	baekjoon online judge
*	No. 2442 별찍기-5
*	@date		2018.04.20
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
			cout << " ";
		for (int k = 0; k < 2 * (i + 1) - 1; k++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}