#include <iostream> 
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
void swap_Nodes(Node** head, int x, int y)
{
	if (x == y) return;
	Node* prevX = NULL, * currX = *head;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}
	Node* prevY = NULL, * currY = *head;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return;
	if (prevX != NULL)
		prevX->next = currY;
	else
		*head = currY;
	if (prevY != NULL)
		prevY->next = currX;
	else
		*head = currX;
	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}
void insert_node(Node** head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}
void print_node(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
int main()
{
	int swap, swap1;
	Node* start = NULL;
	insert_node(&start, 7);
	insert_node(&start, 6);
	insert_node(&start, 5);
	insert_node(&start, 4);
	insert_node(&start, 3);
	insert_node(&start, 2);
	insert_node(&start, 1);
	cout << "Linked list before calling swapNodes : ";
	print_node(start);
	cout << endl;
	cout << "Enter nodes to be swapped : ";
	cin >> swap;
	cin >> swap1;
	swap_Nodes(&start, swap, swap1);
	cout << "Linked list after calling swapNodes : ";
	print_node(start);
	cout << endl;
	system("pause");
}

