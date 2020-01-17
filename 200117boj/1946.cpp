/**
*	BOJ
*	No.1946	신입 사원
*	@author	peter9378
*	@date		2020.01.17
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

int arr[100001];

void init()
{
	for (int i = 0; i < 100001; i++)
		arr[i] = 0;
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
		int N;
		cin >> N;

		init();
		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;

			arr[a] = b;
		}

		int answer = 1, temp = arr[1];
		for (int i = 2; i <= N; i++)
		{
			if (temp >= arr[i])
			{
				temp = arr[i];
				answer++;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}
