#include <iostream>
#include <queue>
using namespace std;
int N, K, c;
queue<int> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		q.push(i + 1);
	}
	cout << '<';
	while (q.size())
	{
		if (c == K - 1)
		{
			if (q.front() == K)
				cout << q.front();
			else
				cout << ", " << q.front();
			c -= (K - 1);
		}
		else
		{
			q.push(q.front());
			c++;
		}
		q.pop();
	}
	cout << '>';
}
