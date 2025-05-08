#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, x, y;
vector<pair<int, int>> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> x >> y;
		pair<int, int> p = make_pair(x, y);
		v.push_back(p);
	}
	sort(v.begin(), v.begin() + v.size());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
}
