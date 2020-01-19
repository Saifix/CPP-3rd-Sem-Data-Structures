#include <iostream> 
using namespace std;
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}
	void reverse()
	{
		Node* current = head;
		Node* prev = NULL, * next = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void print_node()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void insert_node(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};
int main()
{
	LinkedList obj;
	obj.insert_node(20);
	obj.insert_node(4);
	obj.insert_node(15);
	obj.insert_node(85);
	cout << "Given linked list\n";
	obj.print_node();
	obj.reverse();
	cout << "\nReversed Linked list \n";
	obj.print_node();
	cout << endl;
	system("pause");
}
