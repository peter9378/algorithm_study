/**
*	baekjoon online judge
*	No. 6603	로또
*	@author	peter9378
*	@date		2019.04.11
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 15
int k;
int arr[MAX];
int lotto[MAX];

// dfs
void dfs(int index, int count)
{
	if (count == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << lotto[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i < k; i++)
	{
		lotto[count] = arr[i];
		dfs(i + 1, count + 1);
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	while (cin >> k && k)
	{
		for (int i = 0; i < k; i++)
			cin >> arr[i];

		// dfs
		dfs(0, 0);
		cout << "\n";
	}


	return 0;
}