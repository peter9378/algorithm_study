/**
*	BOJ
*	No.15353	큰 수 A+B(2)
*	@author	peter9378
*	@date		2019.09.01
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char a[10001], b[10001], answer[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int flag = 0, length = 0;
	cin >> a >> b;

	int alength = strlen(a);
	int blength = strlen(b);

	int count = 0;
	for (int i = alength - 1, j = blength - 1; i > -1 || j > -1; i--, j--)
	{
		count = 0;
		if (i > -1)
			count += a[i] - '0';
		if (j > -1)
			count += b[j] - '0';
		count += flag;
		flag = count > 9;
		answer[length++] = (count % 10) + 48;
	}

	if (flag)
		cout << 1;
	for (int i = length - 1; i > -1; i--)
		cout << answer[i];

	return 0;
}