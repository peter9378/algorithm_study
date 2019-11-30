/**
*	BOJ
*	No.14624	전북대학교
*	@author	peter9378
*	@date		2019.11.30
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N % 2)
	{
		for (int i = 0; i < N; i++)
			cout << "*";
		cout << "\n";
		N = N / 2 + 1;
		for (int i = 0; i < N - 1; i++)
			cout << " ";
		cout << "*\n";
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
				cout << " ";
			cout << "*";
			for (int j = 0; j < 2 * i - 1; j++)
				cout << " ";
			cout << "*\n";
		}
	}
	else
		cout << "I LOVE CBNU";

	return 0;
}
