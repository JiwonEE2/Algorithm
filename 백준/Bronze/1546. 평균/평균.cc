#include <iostream>
using namespace std;
int N, i, a, m;
float s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (; i < N; i++)
	{
		cin >> a;
		s += a;
		if (a > m)
			m = a;
	}
	cout << s / N / m * 100;
}