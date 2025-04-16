#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	char c[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int n;

	for (int i = 0; i < 26; i++)
	{
		n = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if (c[i] == s[j])
			{
				n++;
			}
		}
		cout << n << ' ';
	}
}