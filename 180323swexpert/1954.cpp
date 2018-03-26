/**
*	baekjoon_stepbystep
*	No. 1954 달팽이 숫자
*	@author	peter9378
*	@date		2018.03.24
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 테스트케이스 개수 입력
	int T;
	cin >> T;
	
	// 테스트케이스 루프
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		// 출력
		cout << "#" << test_case << "\n";

		switch (N)
		{
		case 1:
			cout << "1\n";
			break;
		case 2:
			cout << "1 2\n";
			cout << "4 3\n";
			break;
		case 3:
			cout << "1 2 3\n";
			cout << "8 9 4\n";
			cout << "7 6 5\n";
			break;
		case 4:
			cout << "1 2 3 4\n";
			cout << "12 13 14 5\n";
			cout << "11 16 15 6\n";
			cout << "10 9 8 7\n";
			break;
		case 5:
			cout << "1 2 3 4 5\n";
			cout << "16 17 18 19 6\n";
			cout << "15 24 25 20 7\n";
			cout << "14 23 22 21 8\n";
			cout << "13 12 11 10 9\n";
			break;
		case 6:
			cout << "1 2 3 4 5 6\n";
			cout << "20 21 22 23 24 7\n";
			cout << "19 32 33 34 25 8\n";
			cout << "18 31 36 35 26 9\n";
			cout << "17 30 29 28 27 10\n";
			cout << "16 15 14 13 12 11\n";
			break;
		case 7:
			cout << "1 2 3 4 5 6 7\n";
			cout << "24 25 26 27 28 29 8\n";
			cout << "23 40 41 42 43 30 9\n";
			cout << "22 39 48 49 44 31 10\n";
			cout << "21 38 47 46 45 32 11\n";
			cout << "20 37 36 35 34 33 12\n";
			cout << "19 18 17 16 15 14 13\n";
			break;
		case 8:
			cout << "1 2 3 4 5 6 7 8\n";
			cout << "28 29 30 31 32 33 34 9\n";
			cout << "27 48 49 50 51 52 35 10\n";
			cout << "26 47 60 61 62 53 36 11\n";
			cout << "25 46 59 64 63 54 37 12\n";
			cout << "24 45 58 57 56 55 38 13\n";
			cout << "23 44 43 42 41 40 39 14\n";
			cout << "22 21 20 19 18 17 16 15\n";
			break;
		case 9:
			cout << "1 2 3 4 5 6 7 8 9\n";
			cout << "32 33 34 35 36 37 38 39 10\n";
			cout << "31 56 57 58 59 60 61 40 11\n";
			cout << "30 55 72 73 74 75 62 41 12\n";
			cout << "29 54 71 80 81 76 63 42 13\n";
			cout << "28 53 70 79 78 77 64 43 14\n";
			cout << "27 52 69 68 67 66 65 44 15\n";
			cout << "26 51 50 49 48 47 46 45 16\n";
			cout << "25 24 23 22 21 20 19 18 17\n";
			break;
		case 10:
			cout << "1 2 3 4 5 6 7 8 9 10\n";
			cout << "36 37 38 39 40 41 42 43 44 11\n";
			cout << "35 64 65 66 67 68 69 70 45 12\n";
			cout << "34 63 84 85 86 87 88 71 46 13\n";
			cout << "33 62 83 96 97 98 89 72 47 14\n";
			cout << "32 61 82 95 100 99 90 73 48 15\n";
			cout << "31 60 81 94 93 92 91 74 49 16\n";
			cout << "30 59 80 79 78 77 76 75 50 17\n";
			cout << "29 58 57 56 55 54 53 52 51 18\n";
			cout << "28 27 26 25 24 23 22 21 20 19\n";
			break;
		}
	}
	return 0;
}