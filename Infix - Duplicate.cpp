#include<iostream> 
#include<stack>
#include<string>
using namespace std;

struct node
{
	char value;
	node* left, * right;
};

class tree 
{
public:

	void convert_inorder(node* tree)
	{
		if (tree)
		{
			convert_inorder(tree->left);
			convert_inorder(tree->right);
		}
	}

	bool check_operator(char c)
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			return true;
		else
			return false;
	}

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

	node* new_node(int v)
	{
		node* temp = new node;
		temp->left = NULL;
		temp->right = NULL;
		temp->value = v;
		return temp;
	};
};

int main()
{
	tree t;
	char postfix[] = "12+45*8*4";
	int lenght = strlen(postfix);
    for (int i = 0; i <= lenght; i++)
	{
		for (int counter = i+1; counter <= lenght; counter++)
		{
			if (postfix[i] == postfix[counter])
			{
				cout << "Duplicates at position " << i << " and " << counter << " (value : " << postfix[i]<<")" << endl;
			}
		}
	}
	node* r = t.constructTree(postfix);
	t.convert_inorder(r);
	cout << endl;
	system("pause");
}
