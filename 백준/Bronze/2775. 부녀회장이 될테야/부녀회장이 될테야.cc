#include <iostream>
using namespace std;
int T, k, n;
int F(int k, int n)
{
	if (!k || n == 1)
		return n;
	return F(k, n - 1) + F(k - 1, n);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> k >> n;
		cout << F(k, n) << '\n';
	}
}