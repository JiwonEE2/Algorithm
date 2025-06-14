#include <iostream>
using namespace std;
string s;
int L;
unsigned long long a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> s;
	for (int i = 0; i < L; i++)
	{
		a = s[i] + 1 - 'a';
		for (int j = 0; j < i; j++)
		{
			a *= 31;
			if (a > 1234567891)
				a %= 1234567891;
		}
		b += a;
	}
	cout << b % 1234567891;
}
