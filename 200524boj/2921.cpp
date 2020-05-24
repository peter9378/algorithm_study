/**
*	BOJ
*	No.2921	µµ¹Ì³ë
*	@author	peter9378
*	@date		2020.05.24
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

	int N;
	cin >> N;
	cout << (N*(N + 1)*(N + 2)) / 2;

	return 0;
}