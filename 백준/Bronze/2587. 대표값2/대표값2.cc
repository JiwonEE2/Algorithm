#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> n;
	int sum = 0;
	int a;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		n.push_back(a);
		sum += n[i];
	}

	sort(n.begin(), n.end());
	cout << sum / 5 << '\n'
			 << n[2];
}