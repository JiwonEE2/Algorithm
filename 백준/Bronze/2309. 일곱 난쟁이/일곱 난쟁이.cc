#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[9];
	int sum = -100;
	bool isFind = false;

	for (int i = 0; i < 9; i++)
	{
		cin >> n[i];
		sum += n[i];
	}

	sort(n, n + 9);
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (n[i] + n[j] == sum)
			{
				isFind = true;
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						cout << n[k] << '\n';
					}
				}
				break;
			}
		}
		if (isFind)
			break;
	}
}