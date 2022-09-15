// C++ program to Check that two circular
// linked list are identical or not

#include <bits/stdc++.h>
using namespace std;

// Circular Linked list Node Class
class Node {
public:
	int data;
	Node* next;

	// Constructor function
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

// Function to insert a node in
// tail in circular linked list
void insertNode(Node*& head,
				Node*& tail, int d)
{
	// First insertion in circular
	// linked list
	if (head == NULL) {
		Node* newNode = new Node(d);
		head = newNode;
		tail = newNode;
		newNode->next = newNode;
	}
	else {

		// Non-empty list
		Node* temp = new Node(d);
		temp->next = tail->next;
		tail->next = temp;
		tail = tail->next;
	}
}

// Function to print circular linked list
void print(Node* head)
{
	Node* curr = head;

	// If circular linked list is empty
	if (head == NULL) {
		cout << "List is Empty " << endl;
		return;
	}

	// Else iterate until node is NOT head
	do {
		cout << curr->data << " ";
		curr = curr->next;
	} while (curr != head);
	cout << endl;
}

// Function to return length of
// circular linked list
int length(Node* head)
{
	// If circular linked list is empty
	if (head == NULL) {
		return 0;
	}

	int size = 0;
	Node* curr = head;

	// Else iterate until node is NOT head
	do {
		curr = curr->next;
		size++;
	} while (curr != head);
	return size;
}

// Function to Check that two circular
// linked list are identical or not
int checkIdentical(Node*& head1,
					Node*& head2)
{
	// Get the length of first linked list
	int l1 = length(head1);

	// Get the length of first linked list
	int l2 = length(head2);

	// If l1!=l2 then linked list can not
	// be identical
	if (l1 != l2)
		return 0;

	// Initialize the variables
	int Count = 0;
	bool flag = 0;

	// Initialize temporary pointers
	Node* h1 = head1;
	Node* h2 = head2;

	// Traverse the list
	while (1) {

		// If element matches in two
		// circular linked list
		if (h1->data == h2->data) {
			h1 = h1->next;
			Count++;

			// If count equals to l1(or l2)
			// then linked list are identical
			return Count;
		}

		// If element does not matches
		// in two circular linked list
		/*else {
			h1 = head1;
			Count = 0;

			// If flag becomes 1 then one
			// rotation is complete and
			// if now data does not match then
			// linked lists are not identical
			return Count;
		}*/

		// Check if h2 complete one rotation
		if (h2->next == head2)
			flag = 1;

		// Move h2 to h2->next
		h2 = h2->next;
	}
}

// Driver Code
int main()
{

	Node* head1 = NULL;
	Node* tail1 = NULL;

	insertNode(head1, tail1, 1);
	insertNode(head1, tail1, 2);
	insertNode(head1, tail1, 3);
	insertNode(head1, tail1, 4);
	insertNode(head1, tail1, 5);
	insertNode(head1, tail1, 1);
	insertNode(head1, tail1, 2);
	insertNode(head1, tail1, 6);

	Node* head2 = NULL;
	Node* tail2 = NULL;

	insertNode(head2, tail2, 5);
	insertNode(head2, tail2, 1);
	insertNode(head2, tail2, 2);
	insertNode(head2, tail2, 6);
	insertNode(head2, tail2, 1);
	insertNode(head2, tail2, 2);
	insertNode(head2, tail2, 3);
	insertNode(head2, tail2, 4);

	int flag = checkIdentical(head1, head2);
	cout<<flag;
	return 0;
}
