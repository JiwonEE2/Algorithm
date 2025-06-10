#include <iostream>
#include <map>
#include <vector>
using namespace std;
int N, a;
string b;
map<int, vector<string>> c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (c.count(a))
		{
			auto it = c.find(a);
			if (it != c.end())
			{
				it->second.push_back(b);
			}
		}
		else
		{
			vector<string> d = {b};
			c.insert({a, d});
		}
	}
	for (auto &[e, f] : c)
	{
		for (int i = 0; i < f.size(); i++)
			cout << e << ' ' << f[i] << '\n';
	}
}
