#include <iostream>
using namespace std;
int N, b;
int a[2000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> b;
		a[b + 1000000]++;
	}
	for (int i = 0; i < 2000001; i++)
	{
		for (int j = 0; j < a[i]; j++)
			cout << i - 1000000 << '\n';
	}
}
