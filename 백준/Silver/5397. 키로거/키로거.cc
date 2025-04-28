#include <iostream>
#include <list>
using namespace std;
int t;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		list<char> l;
		auto c = l.begin();
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '-')
			{
				if (c != l.begin())
					c = l.erase(--c);
			}
			else if (s[i] == '<')
			{
				if (c != l.begin())
					--c;
			}
			else if (s[i] == '>')
			{
				if (c != l.end())
					++c;
			}
			else
				l.insert(c, s[i]);
		}
		for (c = l.begin(); c != l.end(); ++c)
			cout << *c;
		cout << '\n';
	}
}