#include <iostream>
using namespace std;
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int a = i;
		int b = 1;
		int c = 0;
		while (a)
		{
			c += ((i % (b * 10) - i % b) / b);
			b *= 10;
			a /= 10;
		}
		if (N == c + i)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
