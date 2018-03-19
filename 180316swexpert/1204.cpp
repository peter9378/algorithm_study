/**
*	sw Expert Academy
*	No. 1204 최빈수 구하기
*	@author	peter9378
*	@date		2018.03.20
*/
#include <iostream>
using namespace std;

int score[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	// 테스트 케이스 개수 입력

	int T = 10;
	int temp_score;
	while(T--)
	{
		for (int i = 0; i < 101; i++)
			score[i] = 0;

		// 점수 입력, 입력한 점수대로 counting
		for (int i = 0; i < 1000; i++)
		{
			cin >> temp_score;
			score[temp_score]++;
		}

		int max_count = 0, max_number;
		for (int i = 0; i < 101; i++)
		{
			if (max_count <= score[i])
			{
				max_count = score[i];
				max_number = i;
			}
		}

		cout << "#" << 10-T << " " << max_number << "\n";
	}

	return 0;
}