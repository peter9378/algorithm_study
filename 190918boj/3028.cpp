/**
*	BOJ
*	No.3028	창영마을
*	@author	peter9378
*	@date		2019.09.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int arr[3] = { 1, 0, 0 };
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'A':
			swap(arr[0], arr[1]);
			break;
		case 'B':
			swap(arr[2], arr[1]);
			break;
		case 'C':
			swap(arr[0], arr[2]);
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i])
			cout << i + 1;
	}

	return 0;
}