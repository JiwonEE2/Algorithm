#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n[10], N, m;
float sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N)
	{
		n[N % 10]++;
		N /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
			sum += 0.5 * n[i];
		}
		else if (n[i] > m)
			m = n[i];
	}

	cout << max((int)ceil(sum), m);
}