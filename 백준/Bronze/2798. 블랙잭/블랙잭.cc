#include <iostream>
#include <algorithm>
using namespace std;
int N, M, s;
bool b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int a[N];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = N - 1; i > 1 && !b; i--)
	{
		if (i > M - 2)
			continue;
		for (int j = i - 1; j > 0 && !b; j--)
		{
			if (a[i] + a[j] > M - 1)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{

				if (a[i] + a[j] + a[k] > M)
					continue;
				if (a[i] + a[j] + a[k] == M)
				{
					s = a[i] + a[j] + a[k];
					b = true;
					break;
				}
				if (a[i] + a[j] + a[k] >= s)
				{
					s = a[i] + a[j] + a[k];
					break;
				}
			}
		}
	}
	cout << s;
}