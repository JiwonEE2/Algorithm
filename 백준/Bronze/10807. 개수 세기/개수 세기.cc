#include <iostream>
using namespace std;
int N, v, i;
int arr[201];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (; i < N; i++)
	{
		cin >> v;
		arr[v + 100]++;
	}
	cin >> v;
	cout << arr[v + 100];
}