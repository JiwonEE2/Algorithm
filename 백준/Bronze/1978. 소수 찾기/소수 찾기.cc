#include <iostream>
using namespace std;
int N, a, c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		bool b = true;
		cin >> a;
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0)
			{
				b = false;
				break;
			}
		}
		if (b && a > 1)
			c++;
	}
	cout << c;
}
