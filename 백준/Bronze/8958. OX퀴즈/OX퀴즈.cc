#include <iostream>
using namespace std;
int t, sum, weight;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	string s;
	while (t--)
	{
		sum = 0;
		weight = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'O')
			{
				weight++;
				sum += weight;
			}
			else
			{
				weight = 0;
			}
		}
		cout << sum << '\n';
	}
}