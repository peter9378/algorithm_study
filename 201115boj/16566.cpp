/**
*	BOJ
*	No.16566	카드 게임
*	@author	peter9378
*	@date		2020.11.15
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
#include <complex>
using namespace std;

int arr[2002];
int counting[4000004];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int a = sqrt(N);
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		arr[temp / a]++;
		counting[temp]++;
	}
	for (int i = 0; i < K; i++)
	{
		int temp, target = 0;
		cin >> temp;
		bool flag = false;
		for (int j = temp / a; j <= N / a && !flag; j++)
		{
			if (arr[j] != 0)
			{
				for (int k = j * a; k <= (j + 1)*a; k++)
				{
					if (counting[k] != 0 && k > temp)
					{
						target = k;
						flag = true;
						break;
					}
				}
			}
		}

		arr[target / a]--;
		counting[target]--;
		cout << target << "\n";
	}

	return 0;
}