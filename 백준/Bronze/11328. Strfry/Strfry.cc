#include <iostream>
using namespace std;
int N, i;
string a, b;
int aa[26], bb[26];
bool impo;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		if (a.length() != b.length())
			impo = true;
		else
		{
			for (i = 0; i < a.length(); i++)
			{
				aa[a[i] - 'a']++;
				bb[b[i] - 'a']++;
			}
			for (i = 0; i < 26; i++)
			{
				if (aa[i] != bb[i])
				{
					impo = true;
					break;
				}
			}
		}
		if (impo)
			cout << "Impossible\n";
		else
			cout << "Possible\n";
		fill(aa, aa + 26, 0);
		fill(bb, bb + 26, 0);
		impo = false;
	}
}