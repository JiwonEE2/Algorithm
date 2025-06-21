#include <iostream>
using namespace std;
string a, b, c;
int d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	if (a != "Fizz" && a != "Buzz" && a != "FizzBuzz")
		d = stoi(a) + 3;
	else if (b != "Fizz" && b != "Buzz" && b != "FizzBuzz")
		d = stoi(b) + 2;
	else if (c != "Fizz" && c != "Buzz" && c != "FizzBuzz")
		d = stoi(c) + 1;
	if (d % 3 == 0 && d % 5 == 0)
		cout << "FizzBuzz";
	else if (d % 3 == 0)
		cout << "Fizz";
	else if (d % 5 == 0)
		cout << "Buzz";
	else
		cout << d;
}