#include <iostream>
#include <algorithm>
using namespace std;
int M, N, d = 64;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string a[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			int b = 0, c = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2)
					{
						if (a[k][l] == 'W')
							b++;
						else
							c++;
					}
					else
					{
						if (a[k][l] == 'B')
							b++;
						else
							c++;
					}
				}
			}
			d = min({b, c, d});
		}
	}
	cout << d;
}