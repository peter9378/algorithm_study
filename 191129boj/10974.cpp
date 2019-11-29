/**
*	BOJ
*	No.10974	모든 순열
*	@author	peter9378
*	@date		2019.11.29
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	do
	{
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
