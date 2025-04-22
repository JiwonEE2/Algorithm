#include <iostream>
using namespace std;
int n, x, count;
bool b[1000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (x - a[i] >= 1 && x - a[i] <= 1000000 && b[x - a[i]])
			count++;
		b[a[i]] = true;
	}
	cout << count;
}