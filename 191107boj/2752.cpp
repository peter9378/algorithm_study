/**
*	BOJ
*	No.2752	세수정렬
*	@author	peter9378
*	@date		2019.11.06
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

	vector<int> v(3);
	for (int i = 0; i < 3; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++)
		cout << v[i] << " ";

	return 0;
}