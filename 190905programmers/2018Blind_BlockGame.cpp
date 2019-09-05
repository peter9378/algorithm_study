/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	블록 게임
*	@author	peter9378
*	@date		2019.09.05
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
	int answer = 0;
	int size = board.size();

	while (true)
	{
		int check = answer;
		for (int i = 0; i < size; i++)
		{
			int target = -1;
			for (int j = 0; j < size; j++)
			{
				if (board[j][i])
				{
					target = j - 1;
					break;
				}
			}
			// bottom side
			if (target == -1 || target == size - 1)
				continue;   // no possibility
			else    // on the another block
			{
				int number = board[target + 1][i];
				if (i == 0)
				{
					//       ㅁ
					// ㅁㅁㅁ
					if (target < size - 1 && board[target][i + 1] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i + 2] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 1] = 0;
							answer++;
						}
					}
					//    ㅁ
					//    ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target][i + 1] == number && board[target - 1][i + 1] == number)
					{
						board[target + 1][i] = board[target + 1][i + 1] = board[target][i + 1] = board[target - 1][i + 1] = 0;
						answer++;
					}
				}
				else if (i == 1)
				{
					//       ㅁ
					// ㅁㅁㅁ
					if (target < size - 1 && board[target][i + 1] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i + 2] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 1] = 0;
							answer++;
						}
					}
					//    ㅁ
					//    ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target][i + 1] == number && board[target - 1][i + 1] == number)
					{
						board[target + 1][i] = board[target + 1][i + 1] = board[target][i + 1] = board[target - 1][i + 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target][i - 1] == number && board[target - 1][i - 1] == number)
					{
						board[target + 1][i] = board[target + 1][i - 1] = board[target][i - 1] = board[target - 1][i - 1] = 0;
						answer++;
					}
				}
				else if (i < size - 2)
				{
					//       ㅁ
					// ㅁㅁㅁ
					if (target < size - 1 && board[target][i + 1] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i + 2] == 0 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target + 1][i + 2] == number && board[target][i + 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i + 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i + 1] = board[target + 1][i + 2] = board[target][i + 1] = 0;
							answer++;
						}
					}
					//    ㅁ
					//    ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target][i + 1] == number && board[target - 1][i + 1] == number)
					{
						board[target + 1][i] = board[target + 1][i + 1] = board[target][i + 1] = board[target - 1][i + 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target][i - 1] == number && board[target - 1][i - 1] == number)
					{
						board[target + 1][i] = board[target + 1][i - 1] = board[target][i - 1] = board[target - 1][i - 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 1] == 0 && board[target][i - 2] == number && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target][i - 2] = board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 2] == 0 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number && board[target][i - 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = board[target][i - 1] = 0;
							answer++;
						}
					}
				}
				else if (i == size - 2)
				{
					//    ㅁ
					//    ㅁ
					// ㅁㅁ
					if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i + 1] == number && board[target][i + 1] == number && board[target - 1][i + 1] == number)
					{
						board[target + 1][i] = board[target + 1][i + 1] = board[target][i + 1] = board[target - 1][i + 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁ
					// ㅁㅁ
					else if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target][i - 1] == number && board[target - 1][i - 1] == number)
					{
						board[target + 1][i] = board[target + 1][i - 1] = board[target][i - 1] = board[target - 1][i - 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 1] == 0 && board[target][i - 2] == number && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target][i - 2] = board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 2] == 0 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number && board[target][i - 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = board[target][i - 1] = 0;
							answer++;
						}
					}
				}
				else
				{
					// ㅁ
					// ㅁ
					// ㅁㅁ
					if (target > 0 && target < size - 1 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target][i - 1] == number && board[target - 1][i - 1] == number)
					{
						board[target + 1][i] = board[target + 1][i - 1] = board[target][i - 1] = board[target - 1][i - 1] = 0;
						answer++;
					}
					// ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 1] == 0 && board[target][i - 2] == number && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 1])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target][i - 2] = board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = 0;
							answer++;
						}
					}
					//    ㅁ
					// ㅁㅁㅁ
					else if (target < size - 1 && board[target][i - 2] == 0 && board[target + 1][i] == number && board[target + 1][i - 1] == number && board[target + 1][i - 2] == number && board[target][i - 1] == number)
					{
						bool flag = true;
						// check if another black block can reach
						for (int a = 0; a < target; a++)
						{
							if (board[a][i - 2])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							board[target + 1][i] = board[target + 1][i - 1] = board[target + 1][i - 2] = board[target][i - 1] = 0;
							answer++;
						}
					}
				}
			}
		}
		if (answer == check)
			break;
	}

	return answer;
}