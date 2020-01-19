#include <iostream>
using namespace std;
class Node {

public:
	int data;
	Node* next;
	Node* prev;
};
Node* head, * last;
void popularity(Node* head)
{
	Node* temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data < temp->next->data)
		{
			temp->next = head;
			temp = NULL;
		}
		else
		{
			temp->next = temp;
		}
	}
}
void print_node()
{
	Node* temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}
void createnode(int value)
{
	Node* temp = new Node;
	temp->data = value;
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

int main()
{
	int num;
	Node* a = NULL;
	for (int i = 0; i < 5; i++)
	{
		createnode(i);
	}
	cout << "Friend List before sorting \n";
	print_node();
	popularity(a);
	cout << endl << "Friend List after sorting \n";
	print_node();
	cout << endl;
	system("pause");
}
