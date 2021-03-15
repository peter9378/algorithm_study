/**
*	BOJ
*	No.17496	½ºÅ¸ÈÄ¸£Ã÷
*	@author	peter9378
*	@date		2021.03.15
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T, C, P;
	cin >> N >> T >> C >> P;

	int answer = N / T;
	if (N%T)
		cout << answer * C * P;
	else
		cout << (answer - 1) * C * P;

	return 0;
}
