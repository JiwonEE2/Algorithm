#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, X, t;
	cin >> N >> X;
	while (N--)
	{
		cin >> t;
		if (t < X)cout << t << ' ';
	}
}