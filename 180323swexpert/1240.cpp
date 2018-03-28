/**
*	SW Expert Academy
*	No. 1240 단순 2진 암호코드
*	@author	peter9378
*	@date		2018.03.27
*/
#include <iostream>
#include <string>
using namespace std;

// 코드 입력 배열
int arr[50][100];
// 암호 코드
int code[10][7] = { {0, 0, 0, 1, 1, 0, 1}, {0, 0, 1, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 1},
{0, 1, 1, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1}, {0, 1, 1, 0, 0, 0, 1}, {0, 1, 0, 1, 1, 1, 1},
{0, 1, 1, 1, 0, 1, 1}, {0, 1, 1, 0, 1, 1, 1}, {0, 0, 0, 1, 0, 1, 1} };
// 성능향상을 위한 체크 배열
bool check[50];
// 추출한 코드 배열
int answer[8];


// 해당 인덱스부터 매칭되는 코드를 리턴하는 함수
int find_match_code(int* target_arr)
{
	for (int i = 0; i < 10; i++)
	{
		bool flag = true;
		for (int j = 0; j < 7; j++)
		{
			// 암호코드와 비교해서 하나라도 일치하지않으면
			if (target_arr[j] != code[i][j])
			{
				// flag를 false로 만들고 루프종료
				flag = false;
				break;
			}
		}
		// flag가 true면 현재의 i(암호 코드 번호)를 리턴, false면 재탐색
		if (flag)
			return i;
	}
	// 일치하는 코드가 없음
	return -1;
}


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
		// 가로/세로 입력
		int width, height;
		cin >> height >> width;

		// 한 줄 먼저 입력받기 위한 string
		string this_line;
		for (int i = 0; i < height; i++)
		{
			// 한 줄을 먼저 입력받고
			cin >> this_line;

			// 한 가로줄이 모두 0이면 애초에 check하지 않기 위한 flag
			bool flag = false;
			// 한 줄을 차례로 탐색하며 배열에 입력
			for (int j = 0; j < this_line.length(); j++)
			{
				if (this_line[j] == '0')
					arr[i][j] = 0;
				else
					arr[i][j] = 1;
				// flag 확인
				if (arr[i][j])
					flag = true;
			}
			// 체크 배열에 flag 입력
			check[i] = flag;
		}

		// 검증 루프 순회
		for (int i = 0; i < height; i++)
		{
			// 성능 향상을 위해 check
			if (check[i])
			{
				// 읽어야하는 암호 코드의 시작 좌표
				int start_i = -1;
				int start_j = -1;

				// 가로줄 순회
				for (int j = 0; j < width; j++)
				{
					bool find_flag = true;

					// 암호코드 추출 시작
					for (int k = 0; k < 8; k++)
					{
						// 해당 좌표로부터 암호 코드가 일치하지 않는 경우가 있으면 추출하지않음
						if (find_match_code(&arr[i][j + k * 7]) == -1)
						{
							find_flag = false;
							break;
						}
					}
					// 해당 좌표로부터 모든 암호 코드가 일치하는 경우만 좌표 추출
					if (find_flag)
					{
						start_i = i;
						start_j = j;
						break;
					}
				}

				// 추출한 좌표로부터 코드 56자리를 따로 배열에 입력
				int get_code[56];
				for (int j = 0; j < 56; j++)
					get_code[j] = arr[start_i][start_j + j];

				// 암호 코드를 변환하여 검증 코드 배열에 입력
				for (int j = 0; j < 8; j++)
					answer[j] = find_match_code(&get_code[j * 7]);

				// 검증 코드 계산
				int get_check_code = 0;
				get_check_code += answer[1];
				get_check_code += answer[3];
				get_check_code += answer[5];
				get_check_code += answer[0] * 3;
				get_check_code += answer[2] * 3;
				get_check_code += answer[4] * 3;
				get_check_code += answer[6] * 3;

				int count = 0;
				while (get_check_code % 10 != 0)
				{
					get_check_code++;
					count++;
				}

				// 검증 코드의 일치 여부에 따라 출력
				cout << "#" << test_case << " ";
				if (count == answer[7])
				{
					int sum = 0;
					for (int j = 0; j < 8; j++)
						sum += answer[j];
					cout << sum << "\n";
					break;
				}
				else
				{
					cout << "0\n";
					break;
				}
			}
		}
	}
	return 0;
}