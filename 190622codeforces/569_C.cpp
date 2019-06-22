/**
*	Code Forces
*	#569 C.	Valeriy and Deque
*	@author	peter9378
*	@date		2019.06.22
*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> d;
int dp[100001];
pair<int, int> arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int n, q;
	cin >> n >> q;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		d.push_back(temp);
	}

	// process first
	for (int i = 1; i < n; i++)
	{
		int A = d[0], B = d[1];
		arr[i] = make_pair(A, B);
		d.pop_front();
		d.pop_front();

		if (A > B)
		{
			d.push_front(A);
			d.push_back(B);
		}
		else
		{
			d.push_front(B);
			d.push_back(A);
		}
	}
	// and check max number(the first one)
	int max_num = d[0];

	// print answer by size of l
	for (int i = 0; i < q; i++)
	{
		long long l;
		cin >> l;

		if (l < n)
			cout << arr[l].first << " " << arr[l].second << "\n";
		else
			cout << max_num << " " << d[(l - n) % (n - 1) + 1] << "\n";
	}

	return 0;
}