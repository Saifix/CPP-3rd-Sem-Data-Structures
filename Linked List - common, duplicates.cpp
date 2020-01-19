#include <iostream> 
using namespace std;
struct Node {
	int data;
	Node* next;
};
void common(Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;
	int count = 0;
	cout << "Common elements : ";
	while (current1 != NULL) 
	{
		while (current2 != NULL) 
		{
			if (current1->data == current2->data)
			{
				count++;
				cout << current1->data << "  ";
			}
			current2 = current2->next;
		}
		current1 = current1->next;
		current2 = head2;
	}
}
void create_node( Node** head, int x)
{
	Node* new_node = new Node;
	new_node->data = x;
	new_node->next = *head;
	*head = new_node;
}
void print_node( Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void removeDuplicates(Node* start)
{
	struct Node* ptr1, * ptr2, * dup;
	ptr1 = start;
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		while (ptr2->next != NULL)
		{
			if (ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else 
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}
int main()
{
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;

	int arr[] = { 17,10,12,4,3,12,34,575,8,4};

	create_node(&head1, arr[0]);
	create_node(&head1, arr[1]);
	create_node(&head1, arr[2]);
	create_node(&head1, arr[3]);
	create_node(&head1, arr[4]);
	create_node(&head2, arr[5]);
	create_node(&head2, arr[6]);
	create_node(&head2, arr[7]);
	create_node(&head2, arr[8]);
	create_node(&head2, arr[9]);
	for (int i = 0; i < 10; i++)
	{
		create_node(&head3, arr[i]);
	}
	cout << "Given Linked List A: \n";
	print_node(head1);
	cout << "Given Linked List B: \n";
	print_node(head2);
	common(head1, head2);
	cout << endl;
	cout << "Combine linkeed list after removing duplicates : ";
	removeDuplicates(head3);
	print_node(head3);
	cout << endl;
	system("pause");
}
