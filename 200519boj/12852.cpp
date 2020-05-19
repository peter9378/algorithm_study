/**
*	BOJ
*	No.12852	1로 만들기 2
*	@author	peter9378
*	@date		2020.05.19
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

int arr[1000001];

void dfs(int target)
{
	if (target == 0)
		return;
	cout << target << " ";
	if (target % 3 == 0 && arr[target] == arr[target / 3] + 1)
		dfs(target / 3);
	else if (target % 2 == 0 && arr[target] == arr[target / 2] + 1)
		dfs(target / 2);
	else if (target)
		dfs(target - 1);
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (!(i % 2))
			arr[i] = min(arr[i], arr[i / 2] + 1);

		if (!(i % 3))
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[N] << "\n";

	dfs(N);

	return 0;
}