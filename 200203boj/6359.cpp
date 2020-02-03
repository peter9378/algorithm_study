/**
*	BOJ
*	No.6359	만취한 상범
*	@author	peter9378
*	@date		2020.02.03
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

bool arr[101];

void init()
{
	for (int i = 0; i < 101; i++)
		arr[i] = false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		init();
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
				arr[j] ^= true;
		}

		int answer = 0;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i])
				answer++;
		}

		cout << answer << "\n";
	}

	return 0;
}
