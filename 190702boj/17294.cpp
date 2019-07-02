/**
*	BOJ
*	No.17294	귀여운 수~ε٩(๑> ₃ <)۶з
*	@author	peter9378
*	@date		2019.07.02
*/
#include <iostream>
#include <algorithm>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	long long int k;
	cin >> k;

	int diff = k%100/10 - k % 10;
	if (k < 100)
	{
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}
	else
	{
		while (k / 10)
		{
			if (k % 100 / 10 - k % 10 != diff)
			{
				cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
				return 0;
			}
			k /= 10;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return 0;
}