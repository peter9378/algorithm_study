/**
*	BOJ
*	No.10984	내 학점을 구해줘
*	@author	peter9378
*	@date		2019.12.01
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
#include <iomanip>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	cout.precision(2);

	while (T--)
	{
		int N;
		cin >> N;

		int grade = 0;
		float sum = 0;
		for (int i = 0; i < N; i++)
		{
			int C;
			float G;
			cin >> C >> G;

			grade += C;
			sum += (C*G);
		}
		if (sum / grade == 0)
			cout << grade << " 0.0\n";
		else
			cout << grade << " " << sum / grade << "\n";
	}
	return 0;
}
