#include <iostream>
using namespace std;
int N, b;
int a[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> b;
		a[b]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < a[i]; j++)
			cout << i << '\n';
	}
}
