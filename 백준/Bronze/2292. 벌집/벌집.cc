#include <iostream>
using namespace std;
int N, s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if (N <= 1 + s)
		{
			cout << i + 1;
			break;
		}
		else
			s += 6 * (i + 1);
	}
}
