#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	do
	{
		if ((a * a + b * b + c * c - 2 * max({a, b, c}) * max({a, b, c})))
			cout << "wrong\n";
		else
			cout << "right\n";
		cin >> a >> b >> c;
	} while (a | b | c);
}