#include <iostream>
using namespace std;
int A, B, C, d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;
	if (B >= 1000)
		d = 10000;
	else if (B >= 100)
		d = 1000;
	else if (B >= 10)
		d = 100;
	else
		d = 10;
	cout << A + B - C << '\n'
			 << A * d + B - C;
}