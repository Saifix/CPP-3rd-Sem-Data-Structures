#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* newNode(int k)
{
	Node* temp = new Node;
	temp->data = k;
	temp->next = NULL;
	return temp;
}
Node* addNode(Node* head, int k) {
	if (head == NULL) {
		head = newNode(k);
	}
	else {
		Node* temp = head;
		Node* node = newNode(k);
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
	}

	return head;
}
Node* createNewLL() {
	int data;
	Node* head = NULL;
	for(int i =1;i<7;i++)
	{
		cout << "Enter the data of the Node : ";
		cin >> data;
		head = addNode(head, data);
	}
	return head;
}
int findNodeInLL(Node* head, int data) {
	int index = 0;
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}
int main()
{
	Node* head = createNewLL();
	int data;
	cout << "Enter the data of the linked list to be found : ";
	cin >> data;
	int index = findNodeInLL(head, data);
	cout << "It is present at " << index+1 << endl;
	system("pause");
}

