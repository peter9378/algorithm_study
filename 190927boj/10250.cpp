/**
*	BOJ
*	No.10250	ACM 호텔
*	@author	peter9378
*	@date		2019.09.27
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int H, W, N;
		cin >> H >> W >> N;

		N--;
		int x = N / H + 1;
		int y = N % H + 1;

		cout << y;
		if (x < 10)
			cout << "0" << x << "\n";
		else cout << x << "\n";
	}

	return 0;
}