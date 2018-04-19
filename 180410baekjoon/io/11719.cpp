/**
*	baekjoon online judge
*	No. 11719 그대로 출력하기 2
*	@author	peter9378
*	@date		2018.04.19
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[105] = "";

	while (fgets(str, 100, stdin))
		printf("%s", str);

	return 0;
}