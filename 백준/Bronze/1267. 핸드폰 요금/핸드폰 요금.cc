#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, t, Y = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		Y += (t / 30 + 1) * 10;
		M += (t / 60 + 1) * 15;
	}
	if (Y == M)
		cout << "Y M " << Y;
	else if (Y < M)
		cout << "Y " << Y;
	else
		cout << "M " << M;
}