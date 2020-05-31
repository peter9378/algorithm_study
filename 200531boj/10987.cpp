/**
*	BOJ
*	No.10987	모음의 개수
*	@author	peter9378
*	@date		2020.05.31
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

char arr[] = { 'a', 'e', 'i', 'o', 'u' };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (s[i] == arr[j])
			{
				answer++;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}