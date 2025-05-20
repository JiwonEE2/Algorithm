#include <iostream>
using namespace std;
int N, K, a = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = N; i > K; i--)
		a *= i;
	for (int i = N - K; i > 0; i--)
		a /= i;
	cout << a;
}
