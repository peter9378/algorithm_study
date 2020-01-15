/**
*	BOJ
*	No.2858 기숙사 바닥
*	@author	peter9378
*	@date		2020.01.15
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int R, B;
    cin >> R >> B;
    
    int W, L = 1, temp;
	while (true)
	{
		if (!(B % L))
			W = B / L;
		temp = W * 2 + L * 2 + 4;
		if (temp == R)
		{
			if (W > L)
				cout << W + 2 << " " << L + 2;
			else
				cout << L + 2 << " " << W + 2;
			break;
		}
        L++;
	}

	return 0;
}
