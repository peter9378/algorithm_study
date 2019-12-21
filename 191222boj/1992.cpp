/**
*	BOJ
*	No.1992	ÄõµåÆ®¸®
*	@author	peter9378
*	@date		2019.12.22
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

int arr[66][66];

void quad(int x, int y, int size)
{
	int current = arr[x][y];
	bool flag = true;

	for (int i = x; i < x + size && flag; i++)
	{
		for (int j = y; j < y + size && flag; j++)
		{
			if (current != arr[i][j])
				flag = false;
		}
	}

	if (flag)
		cout << current;
	else
	{
		cout << "(";
		quad(x, y, size / 2);
		quad(x, y + size / 2, size / 2);
		quad(x + size / 2, y, size / 2);
		quad(x + size / 2, y + size / 2, size / 2);
		cout << ")";
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';
	}

	quad(0, 0, N);

	return 0;
}
