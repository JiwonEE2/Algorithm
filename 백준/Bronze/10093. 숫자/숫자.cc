#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long A, B;
	cin >> A >> B;

	if (A - B > 1)
	{
		cout << A - B - 1 << '\n';
		for (long i = B + 1; i < A; i++)
		{
			cout << i << ' ';
		}
	}
	else if (B - A > 1)
	{
		cout << B - A - 1 << '\n';
		for (long i = A + 1; i < B; i++)
		{
			cout << i << ' ';
		}
	}
	else
		cout << 0;
}