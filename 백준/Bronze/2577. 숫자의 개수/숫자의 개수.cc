#include <iostream>
using namespace std;
int n[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	string s = to_string(A * B * C);
	int i = 0;
	for (; i < s.length(); i++)
	{
		n[s[i] - '0']++;
	}

	for (i = 0; i < 10; i++)
	{
		cout << n[i] << '\n';
	}
}