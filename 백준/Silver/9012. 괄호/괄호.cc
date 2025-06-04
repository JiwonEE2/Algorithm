#include <iostream>
#include <stack>
using namespace std;
int T;
string a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		bool b = false;
		stack<char> c;
		cin >> a;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '(')
				c.push('(');
			else if (c.empty())
			{
				b = true;
				break;
			}
			else
				c.pop();
		}
		if (b)
			cout << "NO\n";
		else if (c.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
