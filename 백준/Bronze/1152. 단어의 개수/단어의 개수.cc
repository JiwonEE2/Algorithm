#include <iostream>
using namespace std;
string s;
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] != ' ' && s[i + 1] == ' ')
			n++;
	}
	if (s[s.length() - 1] != ' ')
		n++;
	cout << n;
}
