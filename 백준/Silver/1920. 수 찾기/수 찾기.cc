#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> A;
int N, M, b, c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> b;
		A[b] = true;
	}
	cin >> M;
	while (M--)
	{
		cin >> c;
		cout << A[c] << ' ';
	}
}
