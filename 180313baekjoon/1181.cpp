/**
*	baekjoon_stepbystep
*	No. 1181 단어 정렬
*	@author	peter9378
*	@date		2018.03.28
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Word 구조체
struct Word 
{
	int len;
	char arr[51];
};

// 정렬에 사용할 비교 함수 구현
bool comp(const Word &s1, const Word &s2) 
{
	if (s1.len == s2.len) 
	{ 
		for (int i = 0; i< s1.len; i++) 
		{
			if (s1.arr[i] == s2.arr[i])
				continue;
			else if (s1.arr[i] < s2.arr[i])
				return true;
			else 
				return false;
		}
	}
	return s1.len < s2.len;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N; 

	Word* word = new Word[N];

	for (int i = 0; i<N; i++)
	{
		cin >> word[i].arr;   
		word[i].len = strlen(word[i].arr);
	}

	// algorithm의 sort함수 이용, comp기준으로 비교
	sort(word, word + N, comp);

	for (int i = 0; i<N; i++)
	{   
		if (i != 0) 
		{
			if (!strcmp(word[i].arr, word[i - 1].arr)) 
				continue;
		}
		cout << word[i].arr << "\n";
	}


	delete[] word;
	return 0;
}
