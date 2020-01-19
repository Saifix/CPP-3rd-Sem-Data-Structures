#include <iostream> 
#include <stack>
using namespace std;
void balance_parentheses()
{
	stack<char> a;
	string s;
	cout << "Enter string containing parentheses:";
	cin >> s;
	int flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			a.push(s[i]);
			flag = 1;
		}
		if (!a.empty()) {
			if (s[i] == '}') {
				if (a.top() == '{')
				{
					a.pop();
					continue;
				}
				else
					break;
			}
			if (s[i] == ']') {
				if (a.top() == '[') {
					a.pop();
					continue;
				}
				else
					break;
			}
			if (s[i] == ')') {
				if (a.top() == '(') {
					a.pop();
					continue;
				}
				else
					break;
			}
		}
		else {
			break;
		}
	}

	if ((a.empty()) && (flag == 1))
		cout << "Parenthesis are balanced" << endl;
	else
		cout << "Parenthesis are not balanced" << endl;
}
int main()
{
	balance_parentheses();
	system("pause");
}


