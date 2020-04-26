/**
*	BOJ
*	No.15059	Hard choice
*	@author	peter9378
*	@date		2020.04.26
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

	int answer = 0;
	int meal[3], want[3];
	for (int i = 0; i < 3; i++)
		cin >> meal[i];
	for (int i = 0; i < 3; i++)
		cin >> want[i];
	for (int i = 0; i < 3; i++)
		answer += (meal[i] < want[i]) ? want[i] - meal[i] : 0;
	cout << answer;

	return 0;
}