/**
*	SW Expert Academy
*	No. 1961 숫자 배열 회전
*	@author	peter9378
*	@date		2018.03.27
*/
#include <iostream>
using namespace std;

#define MAX 7

int arr[MAX][MAX];
int arr90[MAX][MAX];
int arr180[MAX][MAX];
int arr270[MAX][MAX];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int length;
		cin >> length;

		// 배열 입력
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				cin >> arr[i][j];
		}

		// 회전 로직은 모두 같지만 그냥 세번 씀.
		// 90도 회전
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				arr90[j][length-i-1] = arr[i][j];
		}

		// 180도 회전(90도 회전 + 90도 회전)
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				arr180[j][length-i-1] = arr90[i][j];
		}

		// 270도 회전(180도 회전 + 90도 회전)
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				arr270[j][length - i - 1] = arr180[i][j];
		}

		// 출력
		cout << "#" << test_case << "\n";
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				cout << arr90[i][j];
			cout << " ";
			for (int j = 0; j < length; j++)
				cout << arr180[i][j];
			cout << " ";
			for (int j = 0; j < length; j++)
				cout << arr270[i][j];
			cout << "\n";
		}
	}
	return 0;
}