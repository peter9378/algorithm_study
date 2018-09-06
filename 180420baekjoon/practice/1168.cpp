/**
*	baekjoon online judge
*	No. 1168	조세퍼스 문제 2
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
#include <vector>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 입력
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> q;

	// 벡터 초기화
	for (int i = 1; i <= N; i++)
		q.push_back(i);

	// 순열 출력 루프
	printf("<");
	int index = 0;
	while (q.size() != 1)
	{
		index += (M - 1);
		if (index >= q.size())
			index %= q.size();

		printf("%d, ", q[index]);
		q.erase(q.begin() + index);
	}
	// 마지막 요소
	printf("%d>", q[0]);

	return 0;
}