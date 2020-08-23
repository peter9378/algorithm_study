/**
*	BOJ
*	No.2355	½Ã±×¸¶
*	@author	peter9378
*	@date		2020.08.23
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

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;

	if (A > B)
		swap(A, B);

	cout << (A + B) * (-A + B + 1) / 2;

	return 0;
}