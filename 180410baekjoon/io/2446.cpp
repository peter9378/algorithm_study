/**
*	baekjoon online judge
*	No. 2446 별찍기-9
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
		for (int k = 0; k < i; k++)
			cout << " ";
		for (int j = 0; j < 2 * (N - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
			cout << " ";
		for (int k = 0; k < 2 * (i + 1) - 1; k++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}