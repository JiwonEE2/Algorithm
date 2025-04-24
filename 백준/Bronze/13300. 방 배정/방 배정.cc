#include <iostream>
using namespace std;
int N, K, S, Y, r;
int arr[13];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	while (N--)
	{
		cin >> S >> Y;
		arr[S * 6 + Y]++;
	}
	for (int i = 1; i < 13; i++)
	{
		r += (arr[i] / K) + (arr[i] % K != 0);
	}
	cout << r;
}