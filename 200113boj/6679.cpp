/**
*	BOJ
*	No.6679 싱기한 네자리 숫자
*	@author	peter9378
*	@date		2020.01.13
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

int get(int target, int base)
{
    int result = 0;
    while (target)
    {
        result += target % base;
        target /= base;
    }
    return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    for(int i=1000;i<10000;i++)
    {
        int temp = get(i, 10);
        if(temp == get(i, 12) && temp == get(i, 16))
            cout << i << "\n";
    }

	return 0;
}
