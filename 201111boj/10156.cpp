/**
*	BOJ
*	No.10156	°úÀÚ
*	@author	peter9378
*	@date		2020.11.11
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

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N, M;
	cin >> K >> N >> M;
	
	if (K*N < M)
		cout << 0;
	else
		cout << K * N - M;

	return 0;
}