/**
*	BOJ
*	No.2525	¿Àºì ½Ã°è
*	@author	peter9378
*	@date		2020.08.15
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

	int A, B;
	cin >> A >> B;

	int total = A * 60 + B;
	int C;
	cin >> C;

	total += C;
	total %= 24 * 60;

	cout << total / 60 << " " << total % 60;

	return 0;
}