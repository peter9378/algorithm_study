/**
*	BOJ
*	No.1076	저항
*	@author	peter9378
*	@date		2019.06.23
*/
#include <iostream>
#include <string>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	string a, b, c;
	cin >> a >> b >> c;

	if (a == "brown")
		cout << 1;
	else if (a == "red")
		cout << 2;
	else if (a == "orange")
		cout << 3;
	else if (a == "yellow")
		cout << 4;
	else if (a == "green")
		cout << 5;
	else if (a == "blue")
		cout << 6;
	else if (a == "violet")
		cout << 7;
	else if (a == "grey")
		cout << 8;
	else if (a == "white")
		cout << 9;
	
	if (b == "black")
		cout << "0";
	else if (b == "brown")
		cout << 1;
	else if (b == "red")
		cout << 2;
	else if (b == "orange")
		cout << 3;
	else if (b == "yellow")
		cout << 4;
	else if (b == "green")
		cout << 5;
	else if (b == "blue")
		cout << 6;
	else if (b == "violet")
		cout << 7;
	else if (b == "grey")
		cout << 8;
	else if (b == "white")
		cout << 9;

	if (a != "black" || b != "black")
	{
		if (c == "brown")
			cout << "0";
		else if (c == "red")
			cout << "00";
		else if (c == "orange")
			cout << "000";
		else if (c == "yellow")
			cout << "0000";
		else if (c == "green")
			cout << "00000";
		else if (c == "blue")
			cout << "000000";
		else if (c == "violet")
			cout << "0000000";
		else if (c == "grey")
			cout << "00000000";
		else if (c == "white")
			cout << "000000000";
	}

	return 0;
}