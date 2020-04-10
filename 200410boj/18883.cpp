/**
*	BOJ
*	No.18883	N M Âï±â
*	@author	peter9378
*	@date		2020.04.10
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
			cout << i * M + j << " ";
		cout << i * M + M << "\n";
	}

	return 0;
}