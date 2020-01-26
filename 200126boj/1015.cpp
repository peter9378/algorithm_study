/**
*	BOJ
*	No.1015	수열 정렬
*	@author	peter9378
*	@date		2020.01.26
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

int arr[55];
int counting[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
				counting[j]++;
			else
				counting[i]++;
		}
	}

	for (int i = 0; i < N; i++)
		cout << counting[i] << " ";

	return 0;
}
