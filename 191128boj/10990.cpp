/**
*	BOJ
*	No.10990	º° Âï±â - 15
*	@author	peter9378
*	@date		2019.11.28
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

	return 0;
}
