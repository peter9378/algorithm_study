/**
*	BOJ
*	No.4690	완전 세제곱
*	@author	peter9378
*	@date		2019.10.03
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i < 101; i++)
	{
		for (int j = 2; j < i; j++)
		{
			for (int k = j + 1; k < i; k++)
			{
				for (int a = k + 1; a < i; a++)
				{
					if (i*i*i == j * j*j + k * k*k + a * a*a)
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << a << ")\n";
				}
			}
		}
	}

	return 0;
}