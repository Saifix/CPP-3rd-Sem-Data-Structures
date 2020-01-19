#include<iostream>
using namespace std;
struct node 
{
	int num;
	int coffx;
	int coffy;
	node* next;
};
class linked_list {
private:
	node* head, * last;
public:
	linked_list()
	{
		head = NULL;
		last = NULL;
	}
	void create_node(int n, int cx, int cy)
	{
		node* temp = new node;
		temp->num = n;
		temp->coffx = cx;
		temp->coffy = cy;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}
	}
	void display_node()
	{
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->num <<"x^" << temp->coffx <<"y^"<<temp->coffy<< " + " ;
			temp = temp->next;
		}
	}
};
int main()
{
	linked_list obj;
	int num, coffx, coffy;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the " << i + 1 << " part of expression" << endl;
		cout << "Enter the polynoial number : ";
		cin >> num;
		cout << "Enter the' x ' cofficient part : ";
		cin >> coffx;
		cout << "Enter the ' y ' cofficient part : ";
		cin >> coffy;
		obj.create_node(num, coffx, coffy);
	}
	cout << "Whole expression : ";
	obj.display_node();
	cout << endl;
	system("pause");
}

