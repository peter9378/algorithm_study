/**
*	BOJ
*	No.2845	파티가 끝나고 난 뒤
*	@author	peter9378
*	@date		2019.12.16
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

	int L, P;
	cin >> L >> P;

	vector<int> v(5);
	for (int i = 0; i < 5; i++)
		cin >> v[i];

	for (int i = 0; i < 5; i++)
		cout << v[i] - (L*P) << " ";

	return 0;
}
