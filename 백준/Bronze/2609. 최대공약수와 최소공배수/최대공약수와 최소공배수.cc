#include <iostream>
using namespace std;
int a, b, c, d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	for (int i = min(a, b); i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			cout << i << '\n';
			break;
		}
	}
	for (int i = 1;; i++)
	{
		if ((max(a, b) * i) % min(a, b) == 0)
		{
			cout << max(a, b) * i;
			break;
		}
	}
}