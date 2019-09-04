/**
*	BOJ
*	No.3048	개미
*	@author	peter9378
*	@date		2019.09.05
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

	// input data
	int N1, N2;
	cin >> N1 >> N2;

	string a, b;
	cin >> a;
	cin >> b;

	int T;
	cin >> T;

	string answer = "";
	int total = N1 + N2;

	if (T == 0)
	{
		reverse(a.begin(), a.end());
		cout << a + b;
		return 0;
	}

	for (int i = 0; i < total; i++)
		answer += ' ';

	for (int i = 0; i < N1; i++)
	{
		int temp = min(total - i - 1, N1 - 1 - i + max(T - i, 0));
		answer[temp] = a[i];
	}
	for (int i = 0; i < N2; i++)
	{
		int temp = max(i, N1 + i - max(T - i, 0));
		answer[temp] = b[i];
	}

	cout << answer;

	return 0;
}