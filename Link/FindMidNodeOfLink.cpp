#include<iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

/*create Link List by array*/
Node* createLink()
{
	Node *head = new Node;
	Node *p = head;

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i=0 ; i<sizeof(a)/sizeof(int) ; i++)
	{	
		Node *node = new Node;
		node->value = a[i];

		p->next = node;
		p = p->next;
	}

	return head;
}

/** find the mid node of link **/
Node* findMidNode(Node* head)
{
	if (head == NULL || head->next == NULL)
		return NULL;

	Node * fastPtr = head->next;
	Node * slowPtr = fastPtr;

	// one step for slowPtr, and two steps for fastPtr
	int currentIndex = 1;

	while(fastPtr)
	{
		if (currentIndex % 2 ==0)
			slowPtr = slowPtr->next;

		fastPtr = fastPtr->next;
		currentIndex++;
	}

	return slowPtr;
}

int main()
{
	Node *head = createLink();
	Node * midNode = findMidNode(head);
	cout << midNode->value;
	
	return 0;
}
