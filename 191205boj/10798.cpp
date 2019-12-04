/**
*	BOJ
*	No.10798	세로읽기
*	@author	peter9378
*	@date		2019.12.05
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

char arr[5][16];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 16; j++)
			arr[i][j] = '.';
	}

	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] != '.')
				cout << arr[j][i];
		}
	}


	return 0;
}
