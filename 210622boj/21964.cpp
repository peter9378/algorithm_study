/**
*	BOJ
*	No.21964	선린인터넷고등학교 교가
*	@author	peter9378
*	@date		2021.06.22
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

	int N;
	string S;
	cin >> N >> S;

	for (int i = S.length() - 5; i < S.length(); i++)
		cout << S[i];

	return 0;
}
