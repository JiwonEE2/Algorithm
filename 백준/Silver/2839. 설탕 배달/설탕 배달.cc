#include <iostream>
using namespace std;
int N, c, i, j;
bool b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	if (N == 4 || N == 7)
		cout << -1;
	else
	{
		for (; i < N && !b; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (N == j * 5 + i * 3)
				{
					b = true;
					cout << j + i;
					break;
				}
			}
		}
	}
}