#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = -N + 1; i < N; i++)
	{
		int j = abs(i);
		for (; j > 0; j--)
		{
			cout << ' ';
		}
		for (j = 0; j <= 2 * (N - abs(i) - 1); j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
}