
#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
};
class Linked_list {
private:
	node* head;
	node* tail;
public:
	Linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	void create_node(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void print_node()
	{
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
	void move(int value, int newpos)
	{
		node* pre = new node;
		node* cur = new node;
		node* temp = new node;
		cur = head;
		for (int i = 0; i < newpos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data = value-1;
		pre->next = temp;
		temp->next = cur;

		delete_position(value);
	}
	void delete_position(int pos)
	{
		node* current = new node;
		node* previous = new node;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}
};
int main()
{
	Linked_list obj;
	int value, newpos;
	for (int i = 0; i < 5; i++)
	{
		obj.create_node(i);
	}
	cout << "Linked list : ";
	obj.print_node();
	cout <<endl<< "Enter the value of node which is to be moved : ";
	cin >> value;
	cout << "At which place do you want to move that node : ";
	cin >> newpos;
	obj.move(value, newpos);
	cout << "New linked list : ";
	obj.print_node();
	cout << endl;
	system("pause");
}
