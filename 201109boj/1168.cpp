/**
*	BOJ
*	No.1168	요세푸스 문제 2
*	@author	peter9378
*	@date		2020.11.09
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

	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int temp = M - 1;
	int position = N;
	cout << "<";

	for (int i = 0; i < N; i++)
	{
		cout << v[temp];
		if (i == N - 1)
			cout << ">\n";
		else cout << ", ";

		v.erase(v.begin() + temp);
		temp += (M - 1);
		if (--position > 0)
			temp %= position;
	}

	return 0;
}