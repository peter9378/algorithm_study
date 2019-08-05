/**
*	Code Forces
*	#577 A.	Important Exam
*	@author	peter9378
*	@date		2019.08.05
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string arr[1001];
int counting[1001];
int score[1001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
		cin >> score[i];

	long long answer = 0;
	for (int i = 0; i < m; i++)
	{
		int A = 0, B = 0, C = 0, D = 0, E = 0;
		for (int j = 0; j < n; j++)
		{
			switch (arr[j][i])
			{
			case 'A':
				A++;
				break;
			case 'B':
				B++;
				break;
			case 'C':
				C++;
				break;
			case 'D':
				D++;
				break;
			case 'E':
				E++;
				break;
			}
		}
		answer += max(A, max(B, max(C, max(D, E))))*score[i];
	}
	cout << answer;

	return 0;
}