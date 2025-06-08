#include <iostream>
#include <queue>
using namespace std;
int N;
queue<int> q;
bool b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		if (b)
			q.push(q.front());
		b = !b;
		q.pop();
	}
	cout << q.front();
}
