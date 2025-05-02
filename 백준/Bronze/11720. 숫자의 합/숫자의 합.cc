#include <iostream>
using namespace std;
int N, a;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> s;
	for (int i = 0; i < N; i++)
		a += s[i] - '0';
	cout << a;
}