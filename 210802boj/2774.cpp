/**
*	BOJ
*	No.2774 ¿¿¿¿ ¿
*	@author	peter9378
*	@date		2021.08.02
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

char arr[11];
int answer[11];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int temp = 0;
        for(int i = 0; i < 11; i++)
        {
            arr[i] = '0';
            answer[i] = 0;
        }

        cin >> arr;
        
        for(int i = 0; i < strlen(arr); i++)
            answer[arr[i] - '0']++;
        for(int i = 0; i < 10; i++)
        {
            if (answer[i] > 0)
                temp++;
        }
        cout << temp << "\n";
    }

	return 0;
}
