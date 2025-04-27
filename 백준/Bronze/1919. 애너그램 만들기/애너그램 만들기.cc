#include <iostream>
#include <cmath>
using namespace std;
string a, b;
int c[26], n, i;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	for (; i < a.length(); i++)
		c[a[i] - 'a']++;
	for (i = 0; i < b.length(); i++)
		c[b[i] - 'a']--;
	for (i = 0; i < 26; i++)
		n += abs(c[i]);
	cout << n;
}