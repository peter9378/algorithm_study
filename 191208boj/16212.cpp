/**
*	BOJ
*	No.16212	정열적인 정렬
*	@author	peter9378
*	@date		2019.12.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		cout << v[i] << " ";

	return 0;
}