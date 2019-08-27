/**
*	BOJ
*	No.2873	롤러코스터
*	@author	peter9378
*	@date		2019.08.27
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int arr[1001][1001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;

	string answer = "";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}

	if (r % 2)
	{
		for (int i = 0; i < r; i++)
		{
			if (!(i % 2))
			{
				for (int j = 0; j < c - 1; j++)
					answer += 'R';
				if (i != r - 1)
					answer += 'D';
			}
			else
			{
				for (int j = 0; j < c - 1; j++)
					answer += 'L';
				answer += 'D';
			}
		}
	}
	else if (c % 2)
	{
		for (int j = 0; j < c; j++)
		{
			if (!(j % 2))
			{
				for(int k=0;k<r-1;k++)
					answer += 'D';
				if (j != c - 1)
					answer += 'R';
			}
			else
			{
				for (int k = 0; k < r - 1; k++)
					answer += 'U';
				answer += 'R';
			}
		}
	}
	else
	{
		int a = 0, b = 1;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if ((i + j) % 2)
				{
					if (arr[a][b] > arr[i][j])
					{
						a = i;
						b = j;
					}
				}
			}
		}

		int a1 = 0, b1 = 0;
		int a2 = r - 1, b2 = c - 1;
		string temp = "";

		while (a2 - a1 > 1)
		{
			if (a1 / 2 < a / 2)
			{
				for (int i = 0; i < c - 1; i++)
					answer += 'R';
				answer += 'D';
				for (int i = 0; i < c - 1; i++)
					answer += 'L';
				answer += 'D';
				a1 += 2;
			}
			if (a / 2 < a2 / 2)
			{
				for (int i = 0; i < c - 1; i++)
					temp += 'R';
				temp += 'D';
				for (int i = 0; i < c - 1; i++)
					temp += 'L';
				temp += 'D';
				a2 -= 2;
			}
		}
		while (b2 - b1 > 1)
		{
			if (b1 / 2 < b / 2)
			{
				answer += "DRUR";
				b1 += 2;
			}
			if (b / 2 < b2 / 2)
			{
				temp += "DRUR";
				b2 -= 2;
			}
		}

		if (b == b1)
			answer += "RD";
		else
			answer += "DR";

		reverse(temp.begin(), temp.end());
		answer += temp;
	}

	cout << answer;


	return 0;
}