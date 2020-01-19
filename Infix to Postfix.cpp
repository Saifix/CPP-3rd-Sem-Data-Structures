#include<iostream>
#include<deque>
using namespace std;

int optr(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
 
void Postfix_covert(string s)
{
	deque<char> d;
	d.push_front('N');
	int l = s.length();
	string ds;
	for (int i = 0; i < l; i++)
	{		
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			ds += s[i];
		}
		else if (s[i] == '(')
		{
			d.push_front('(');
		}
		else if (s[i] == ')')
		{
			while (d.front() != 'N' && d.front() != '(')
			{
				char c = d.front();
				d.pop_front();
				ds += c;
			}
			if (d.front() == '(')
			{
				char c = d.front();
				d.pop_front();
			}
		}
		else {
			while (d.front() != 'N' && optr(s[i]) <= optr(d.front()))
			{
				char c = d.front();
				d.pop_front();
				ds += c;
			}
			d.push_front(s[i]);
		}
	}
	while (d.front() != 'N')
	{
		char c = d.front();
		d.pop_front();
		ds += c;
	}

	cout << ds << endl;

}
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	cout << "Giver infix expression : " << exp << endl;
	cout << "Conversion of infix to postfix : ";
	Postfix_covert(exp);
	cout << endl;
	system("pause");
}