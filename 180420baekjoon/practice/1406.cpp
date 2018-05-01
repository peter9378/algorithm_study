/**
*	baekjoon online judge
*	No. 11656	접미사 배열
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 문자열 입력
	string str;
	cin >> str;

	// list 사용(동적 컨테이너)
	list<char> v;
	for (int i = 0; i < str.length(); i++)
		v.push_back(str[i]);

	// 명령 개수 입력
	int N;
	cin >> N;

	// 커서(iterator) 설정
	list<char>::iterator iter = v.end();

	// 명령 루프
	while (N--)
	{
		// 명령 입력
		char command;
		cin >> command;

		// 해당 명령 수행
		if (command == 'L' && iter != v.begin())
			iter--;
		else if (command == 'D' && iter != v.end())
			iter++;
		else if (command == 'B' && iter != v.begin())
		{
			// 커서를 전으로 옮기고 삭제 후 커서 재할당
			iter--;
			iter = v.erase(iter);
		}
		else if(command == 'P')
		{
			// 현재 커서 위치에 문자 추가
			cin >> command;
			v.insert(iter, command);
		}
	}

	// 출력
	for (list<char>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it;

	return 0;
}