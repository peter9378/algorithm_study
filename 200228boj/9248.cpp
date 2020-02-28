/**
*	BOJ
*	No.9248	Suffix Array
*	@author	peter9378
*	@date		2020.02.28
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

string s;
int pivot;
int arr[1000001];
int temp[1000001];
int position[1000001];
int lcp[1000001];

bool compare(int a, int b)
{
	if (position[a] != position[b])
		return position[a] < position[b];
	a += pivot;
	b += pivot;
	return (a < s.length() && b < s.length()) ? (position[a] < position[b]) : (a > b);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		arr[i] = i;
		position[i] = s[i] - 'a';
		temp[i] = 0;
	}

	for (pivot = 1;; pivot *= 2)
	{
		sort(arr, arr + s.length(), compare);

		for (int i = 1; i <= s.length(); i++)
			temp[i] = temp[i - 1] + compare(arr[i - 1], arr[i]);
		for (int i = 0; i < s.length(); i++)
			position[arr[i]] = temp[i];

		if (temp[s.length() - 1] == s.length() - 1)
			break;
		for (int i = 0; i < 1000001; i++)
			temp[i] = 0;
	}

	for (int pivot = 0; pivot < s.length(); pivot++)
		cout << arr[pivot] + 1 << " ";
	cout << "\n";

	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (cnt > 0)
			cnt--;
		if (cnt < 0)
			cnt = 0;
		if (position[i] == 0)
			continue;

		int index = i;
		int next = arr[position[index] - 1];
		while (true)
		{
			if ((index + cnt) >= s.length() || (index + cnt) >= s.length())
				break;
			if (s[index + cnt] == s[next + cnt])
				cnt++;
			else
				break;
		}
		lcp[position[i]] = cnt;
	}
	cout << "x ";
	for (int i = 1; i < s.length(); i++)
		cout << lcp[i] << " ";

	return 0;
}