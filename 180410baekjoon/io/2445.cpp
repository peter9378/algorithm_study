/**
*	baekjoon online judge
*	No. 2445 별찍기-8
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
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		for (int k = 0; k < 2 * (N - i - 1); k++)
			cout << " ";
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		cout << "\n";
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
			cout << "*";
		for (int k = 0; k < 2 * (i + 1); k++)
			cout << " ";
		for (int j = 0; j < N - i - 1; j++)
			cout << "*";
		cout << "\n";
	}
	
	return 0;
}