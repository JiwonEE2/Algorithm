#include <iostream>
using namespace std;
int a, b, c, d, e;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d >> e;
	cout << (a * a + b * b + c * c + d * d + e * e) % 10;
}