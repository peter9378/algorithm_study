/**
*	BOJ
*	No.5585	°Å½º¸§µ·
*	@author	peter9378
*	@date		2019.12.15
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

int coin[] = { 500, 100, 50, 10, 5, 1 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	N = 1000 - N;
	int answer = 0;
	while (N)
	{
		for (int i = 0; i < 6; i++)
		{
			if (N >= coin[i])
			{
				N -= coin[i];
				break;
			}
		}
		answer++;
	}

	cout << answer;

	return 0;
}
