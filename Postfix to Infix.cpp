#include<iostream> 
#include<stack>
using namespace std;

struct node
{
	char value;
	node* left, * right;
};

class tree 
{
private:
public:
	int result = 0;
	bool check_operator(char c)
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			return true;
		else
			return false;
	}

	void convert_inorder(node* tree)
	{
		if (tree)
		{
			convert_inorder(tree->left);
			cout << tree->value;
			result = tree->value;
			convert_inorder(tree->right);
		}
	}

	node* new_node(int v)
	{
		node* temp = new node;
		temp->left = NULL;
		temp->right = NULL;
		temp->value = v;
		return temp;
	};

	node* constructTree(char postfix[])
	{
		stack<node*> st;
		node* t, * t1, * t2;
		for (int i = 0; i < strlen(postfix); i++)
		{
			if (!check_operator(postfix[i]))
			{
				t = new_node(postfix[i]);
				st.push(t);
			}
			else
			{
				t = new_node(postfix[i]);
				t1 = st.top();
				st.pop();
				t2 = st.top();
				st.pop();
				t->right = t1;
				t->left = t2;
				st.push(t);
			}
		}
		t = st.top();
		st.pop();

		return t;
	}
};

int main()
{
	tree t;
	char postfix[] = "12+45*8*-";
	node* r = t.constructTree(postfix);
	cout<<"infix expression is : ";
	t.convert_inorder(r);
	cout<<endl<<"Result of expression : "<<t.result;
	cout << endl;
	system("pause");
}