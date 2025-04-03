#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int arr[3] = {a, b, c};
	for (int i = 0; i < 2; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}

	cout << arr[0] << " " << arr[1] << " " << arr[2];
}
