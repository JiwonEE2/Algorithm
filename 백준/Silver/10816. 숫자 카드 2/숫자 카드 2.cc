#include <iostream>
using namespace std;
int N, M, b;
int a[20000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> b;
		a[b + 10000000]++;
	}
	cin >> M;
	while (M--)
	{
		cin >> b;
		cout << a[b + 10000000] << ' ';
	}
}