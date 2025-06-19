#include <iostream>
using namespace std;
int A, B, V, c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> V;
	c = (V - A) / (A - B) - 1;
	while (V > (A * c - B * (c - 1)))
		c++;
	cout << c;
}
