/**
*	BOJ
*	No.3047	ABC
*	@author	peter9378
*	@date		2019.12.09
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

	string s;
	cin >> s;
	for (int i = 0; i < 3; i++)
	{
		switch (s[i])
		{
		case 'A':
			cout << v[0];
			break;
		case 'B':
			cout << v[1];
			break;
		case 'C':
			cout << v[2];
			break;
		}
		cout << " ";
	}
	return 0;
}