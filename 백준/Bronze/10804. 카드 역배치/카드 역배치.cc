#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < (b - a) / 2 + 1; j++)
		{
			swap(arr[a - 1 + j], arr[b - 1 - j]);
		}
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << ' ';
	}
}