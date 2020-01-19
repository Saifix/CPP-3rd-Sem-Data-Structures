#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
node* head;
node* create_newnode(int data)
{
	node* newnode;
	newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
bool detectLoop( node* head)
{
	node* current1, * current2;
	current1 = head;
	current2 = head;
	while (current1 != NULL && current2 != NULL && current2->next != NULL)
	{
		current1 = current1->next;
		current2 = current2->next->next;
		if (current1 == current2)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	node* head= NULL, * temp;
	head = create_newnode(8);
	head->next = create_newnode(10);
	temp = head->next;
	head->next->next = create_newnode(12);
	head->next->next->next = create_newnode(14);
	head->next->next->next->next = create_newnode(16);
	head->next->next->next->next->next = temp;
	if (detectLoop(head))
	{
		cout << "Linked List has loop";
	}
	else
	{
		cout << "Linked List does not contain loop ";
	}
	system("pause");
}




