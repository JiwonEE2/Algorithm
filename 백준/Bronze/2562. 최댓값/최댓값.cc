#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int n, c;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		if (max < n)
		{
			max = n;
			c = i + 1;
		}
	}
	cout << max << '\n'
			 << c;
}