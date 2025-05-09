#include <iostream>
#include <algorithm>
using namespace std;
int N, b, i;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int a[N];
	for (; i < N; i++)
	{
		cin >> b;
		a[i] = b;
	}
	sort(a, a + N);
	cout << a[0] << ' ' << a[N - 1] << '\n';
}
