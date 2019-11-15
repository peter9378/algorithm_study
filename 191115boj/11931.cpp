/**
*	BOJ
*	No.11931	수 정렬하기 4
*	@author	peter9378
*	@date		2019.11.15
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < N; i++)
		cout << v[i] << "\n";

	return 0;
}