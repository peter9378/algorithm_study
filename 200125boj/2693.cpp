/**
*	BOJ
*	No.2693	N번째 큰 수
*	@author	peter9378
*	@date		2020.01.25
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		vector<int> v(10);
		for (int i = 0; i < 10; i++)
			cin >> v[i];

		sort(v.begin(), v.end());
		cout << v[7] << "\n";
	}

	return 0;
}
