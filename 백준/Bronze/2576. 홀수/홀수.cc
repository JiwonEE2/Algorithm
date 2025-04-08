#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[7];
	int sum = 0;
	vector<int> odd;

	for (int i = 0; i < 7; i++)
	{
		cin >> n[i];
		if (n[i] % 2 == 1)
		{
			odd.push_back(n[i]);
			sum += n[i];
		}
	}

	if (odd.empty())
		cout << -1;
	else
	{
		sort(odd.begin(), odd.end());
		cout << sum << '\n'
				 << odd[0];
	}
}