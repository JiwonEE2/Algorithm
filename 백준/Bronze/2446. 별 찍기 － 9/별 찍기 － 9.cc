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
		int j = 0;
		for (; j < N - abs(i) - 1; j++)
			cout << ' ';
		for (j = 0; j < abs(i) * 2 + 1; j++)
			cout << '*';
		cout << '\n';
	}
}