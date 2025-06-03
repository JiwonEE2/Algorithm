#include <iostream>
#include <algorithm>
using namespace std;
int N, i;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	pair<int, string> a[N];
	for (; i < N; i++)
	{
		cin >> s;
		a[i] = make_pair(s.length(), s);
	}
	sort(a, a + N);
	cout << a[0].second << ' ';
	for (i = 1; i < N; i++)
	{
		if (a[i - 1].second != a[i].second)
			cout << a[i].second << ' ';
	}
}