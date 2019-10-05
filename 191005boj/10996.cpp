/**
*	BOJ
*	No.10996	별 찍기 - 21
*	@author	peter9378
*	@date		2019.10.05
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N == 1)
		cout << "*";
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int i = 0; i < (N + 1) / 2; i++)
			{
				cout << "* ";
			}
			cout << "\n ";
			for (int i = 0; i < N / 2; i++)
			{
				cout << "* ";
			}
			cout << "\n";
		}
	}

	return 0;
}