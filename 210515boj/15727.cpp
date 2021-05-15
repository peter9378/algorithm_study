/**
*	BOJ
*	No.15727	조별과제를 하려는데 조장이 사라졌다
*	@author	peter9378
*	@date		2021.05.15
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

	int L;
	cin >> L;
	cout << L / 5 + (L % 5 ? 1 : 0);

	return 0;
}
