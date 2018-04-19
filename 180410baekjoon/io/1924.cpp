/**
*	baekjoon online judge
*	No. 2739 구구단
*	@date		2018.04.20
*/
#include <iostream>
#include <string>
using namespace std;

string chkday(int num)
{
	switch (num)
	{
	case 0:
		return "SUN";
	case 1:
		return "MON";
	case 2:
		return "TUE";
	case 3:
		return "WED";
	case 4:
		return "THU";
	case 5:
		return "FRI";
	case 6:
		return "SAT";
	default:
		break;
	}
	return "ERROR";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cldr[364];
	int m, d;
	int chk;
	cin >> m >> d;

	for (int i = 0; i < 364;)
	{
		cldr[i] = 0;
		cldr[i + 1] = 1;
		cldr[i + 2] = 2;
		cldr[i + 3] = 3;
		cldr[i + 4] = 4;
		cldr[i + 5] = 5;
		cldr[i + 6] = 6;
		i += 7;
	}
	if (m == 1)
	{
		chk = 0;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 2)
	{
		chk = 31;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 3)
	{
		chk = 59;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 4)
	{
		chk = 90;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 5)
	{
		chk = 120;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 6)
	{
		chk = 151;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 7)
	{
		chk = 181;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 8)
	{
		chk = 212;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 9)
	{
		chk = 243;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 10)
	{
		chk = 273;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 11)
	{
		chk = 304;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}
	else if (m == 12)
	{
		chk = 334;
		chk += d;
		chk %= 7;
		cout << chkday(cldr[chk]);
		return 0;
	}

	return 0;
}