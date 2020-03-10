/**
*	BOJ
*	No.1296	µ•¿Ã∆Æ
*	@author	peter9378
*	@date		2020.03.10
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

string arr[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string s;
	cin >> s >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int maxi = -1, index = 0;
	for (int i = 0; i < N; i++)
	{
		string temp = s + arr[i];
		int l = 0, o = 0, v = 0, e = 0;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == 'L')
				l++;
			else if (temp[i] == 'O')
				o++;
			else if (temp[i] == 'V')
				v++;
			else if (temp[i] == 'E')
				e++;
		}

		int compare = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
		if (maxi < compare)
		{
			maxi = compare;
			index = i;
		}
	}

	cout << arr[index];

	return 0;
}
