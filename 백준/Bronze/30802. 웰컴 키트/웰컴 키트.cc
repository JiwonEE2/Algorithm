#include <iostream>
using namespace std;
int N, T, P, b;
int a[6];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	cin >> T >> P;
	for (int i = 0; i < 6; i++)
		b += a[i] / T + (a[i] % T ? 1 : 0);
	cout << b << '\n'
			 << N / P << ' ' << N % P;
}