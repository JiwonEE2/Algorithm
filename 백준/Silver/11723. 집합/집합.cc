#include <iostream>
using namespace std;
int M, x;
int a[20];
string c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M;
	while (M--)
	{
		cin >> c;
		if (c == "all")
		{
			for (int i = 0; i < 20; i++)
				a[i] = 1;
		}
		else if (c == "empty")
		{
			for (int i = 0; i < 20; i++)
				a[i] = 0;
		}
		else
		{
			cin >> x;
			if (c == "add")
				a[x - 1] = 1;
			else if (c == "remove")
				a[x - 1] = 0;
			else if (c == "check")
				cout << a[x - 1] << '\n';
			else
				a[x - 1] = !a[x - 1];
		}
	}
}