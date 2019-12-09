/**
*	BOJ
*	No.16433	주디와 당근농장
*	@author	peter9378
*	@date		2019.12.09
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
#include <cstring>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, R, C;
	cin >> N >> R >> C;

	bool flag = false;
	if (R % 2)
		flag = C % 2;
	else
		flag = !(C % 2);

	if (flag)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((i + j) % 2)
					cout << '.';
				else
					cout << 'v';
			}
			cout << "\n";
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((i + j) % 2)
					cout << 'v';
				else
					cout << '.';
			}
			cout << "\n";
		}
	}


	return 0;
}