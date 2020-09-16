/**
*	BOJ
*	No.14939	ºÒ ²ô±â
*	@author	peter9378
*	@date		2020.09.17
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

#define MAX 10
#define INF 987654321

int arr[11];
int check[11];

void go(int a, int b)
{
	check[a] ^= (1 << (MAX - b - 1));
	if (a)
		check[a - 1] ^= (1 << (MAX - b - 1));
	if (a != MAX - 1)
		check[a + 1] ^= (1 << (MAX - b - 1));
	if (b)
		check[a] ^= (1 << (MAX - b));
	if (b != MAX - 1)
		check[a] ^= (1 << (MAX - b - 2));
	return;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < MAX; i++)
	{
		string temp;
		cin >> temp;

		for (int j = MAX - 1; j >= 0; j--)
		{
			if (temp[j] == 'O')
				arr[i] |= (1 << j);
		}
	}
	int answer = INF;

	for (int candidate = (1 << MAX) - 1; candidate >= 0; candidate--)
	{
		int press = 0;
		for (int i = 0; i < MAX; i++)
			check[i] = arr[i];

		for (int x = 0; x < MAX; x++)
		{
			if (candidate & (1 << x))
			{
				go(0, x);
				press++;
			}
		}

		for (int y = 1; y < MAX; y++)
		{
			for (int x = 0; x < MAX; x++)
			{
				if (check[y - 1] & (1 << (MAX - x - 1)))
				{
					go(y, x);
					press++;
				}
			}
		}

		if (check[MAX - 1] == 0)
			answer = min(answer, press);
	}

	cout << (answer == INF ? -1 : answer);

	return 0;
}