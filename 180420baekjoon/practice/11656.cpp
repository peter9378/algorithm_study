/**
*	baekjoon online judge
*	No. 11656	접미사 배열
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 문자열 입력
	string str;
	cin >> str;

	// vector 사용
	vector<string> v;
	v.push_back(str);

	// 접미사 추가
	string temp;
	for (int i = 1; i < str.length(); i++)
	{
		temp = str.substr(i, str.length() - 1);
		v.push_back(temp);
	}

	// 정렬
	sort(v.begin(), v.end());

	// 출력
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}