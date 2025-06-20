#include <iostream>
using namespace std;
string s;
int a, b, i;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (; i < 13; i++)
	{
		if (s[i] == '*')
			b = i;
		else if (i % 2)
			a += (s[i] - '0') * 3;
		else
			a += s[i] - '0';
	}
	if (b % 2)
	{
		for (i = 0; i < 10; i++)
		{
			if ((a + 3 * i) % 10 == 0)
			{
				cout << i;
				return 0;
			}
		}
	}
	cout << 10 - a % 10;
}