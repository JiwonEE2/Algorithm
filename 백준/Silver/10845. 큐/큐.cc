#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, X;
	string a;
	queue<int> q;
	cin >> N;
	while (N--)
	{
		cin >> a;
		if (a == "push")
		{
			cin >> X;
			q.push(X);
		}
		else if (a == "size")
			cout << q.size() << '\n';
		else if (a == "empty")
			cout << q.empty() << '\n';
		else if (q.empty())
			cout << "-1\n";
		else if (a == "pop")
		{
			cout << q.front() << '\n';
			q.pop();
		}
		else if (a == "front")
			cout << q.front() << '\n';
		else
			cout << q.back() << '\n';
	}
}