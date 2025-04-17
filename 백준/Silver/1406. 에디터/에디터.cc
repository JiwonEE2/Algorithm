#include <iostream>
#include <list>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int M;
	cin >> s >> M;

	list<char> L;
	list<char>::iterator t = L.begin();
	for (int i = 0; i < s.length(); i++)
	{
		L.insert(t, s[i]);
	}

	// 명령어
	char a;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (a == 'L' && t != L.begin())
		{
			// cout << "[ L ]: 왼쪽으로 이동\n";
			t--;
		}
		else if (a == 'D' && t != L.end())
		{
			// cout << "[ D ]: 오른쪽으로 이동\n";
			t++;
		}
		else if (a == 'B')
		{
			// cout << "[ B ]: 왼쪽 삭제\n";
			if (t != L.begin())
			{
				t--;
				t = L.erase(t);
			}
		}
		else if (a == 'P')
		{
			// cout << "[ P ]: 왼쪽에 추가\n";
			cin >> a;
			L.insert(t, a);
		}
		// cout << "\nt (커서 오른쪽의 수): " << *t << '\n';
	}

	// L 출력
	for (list<char>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it;
	}
}
