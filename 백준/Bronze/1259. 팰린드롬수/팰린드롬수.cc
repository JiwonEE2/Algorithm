#include <iostream>
using namespace std;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	while (s != "0")
	{
		bool b = false;
		for (int i = 0; i <= s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - 1 - i])
			{
				cout << "no\n";
				b = true;
				break;
			}
		}
		if (!b)
			cout << "yes\n";
		cin >> s;
	}
}