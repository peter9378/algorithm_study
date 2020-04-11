/**
*	BOJ
*	No.17103	°ñµå¹ÙÈå ÆÄÆ¼¼Ç
*	@author	peter9378
*	@date		2020.04.11
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
#include <iterator>
#include <numeric>
using namespace std;

int counting = 0;
int arr[1000001];
bool check[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	check[1] = true;
	for (int i = 2; i < 1000001; i++)
	{
		if (!check[i])
		{
			arr[counting++] = i;
			for (int j = i + i; j < 1000001; j += i)
				check[j] = true;
		}
	}

	while (T--)
	{
		int N;
		cin >> N;

		int answer = 0;
		for (int i = 0; arr[i] < N; i++)
		{
			if (!check[N - arr[i]])
				answer++;
		}
		if (!check[N / 2])
			cout << answer / 2 + 1 << "\n";
		else
			cout << answer / 2 << "\n";
	}

	return 0;
}