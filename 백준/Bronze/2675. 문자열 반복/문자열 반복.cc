#include <iostream>
using namespace std;
int N, a;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> a >> s;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < a; j++)
			{
				cout << s[i];
			}
		}
		cout << '\n';
	}
}