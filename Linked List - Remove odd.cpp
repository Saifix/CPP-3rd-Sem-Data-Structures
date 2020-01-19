#include<iostream>
using namespace std;
struct Node
{
	int data;
 Node* next;
};
void insert_node(Node*& head)
{
    Node* temp;
	int num = NULL;
	cout << "Enter random numbers : ";
	for (int i = 0; i < 5; i++)
	{
		temp = new Node;
		if (temp == NULL)
			exit(EXIT_FAILURE);
		temp->data = num;
		temp->next = head;
		head = temp;
		cin >> num;
	}
}
void print_node( Node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void delete_odd( Node** root)
{
	if (*root == NULL)
	{

		cout << " No element in this linked list." << endl;
	}
	else
	{
	    Node* temp = *root, * helper = *root;
		while (temp)
		{
			if (temp->data % 2 != 0)
			{
				if (temp == *root)
				{
					helper = temp;
					*root = (*root)->next;
					temp = *root;
					helper->next = NULL;
					free(helper);
					helper = NULL;
				}
				else
				{
					helper->next = temp->next;
					temp->next = NULL;
					free(temp);
					temp = helper->next;
				}
			}
			else
			{
				helper = temp;
				temp = temp->next;
			}
		}
	}
}

int main()
{
    Node* head = NULL;
	insert_node(head);
	delete_odd(&head);
	cout << "Linked list after removing odd number : ";
	print_node(head);
	system("pause");
}

