/**
*	BOJ
*	No.1915	가장 큰 정사각형
*	@author	peter9378
*	@date		2019.07.14
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[1001][1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			arr[i][j] = s[j-1] - 48;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j])
			{
				arr[i][j] = min(min(arr[i][j - 1], arr[i - 1][j]), arr[i - 1][j - 1]) + 1;
				answer = max(answer, arr[i][j]);
			}
		}
	}

	cout << answer * answer;
	
	return 0;
}
