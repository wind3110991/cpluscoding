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

	int a[] = {1, 2, 3, 4, 5, 6, 7};

	for (int i=0 ; i<sizeof(a)/sizeof(int) ; i++)
	{	
		Node *node = new Node;
		node->value = a[i];

		p->next = node;
		p = p->next;
	}

	//p->next = NULL;

	return head;
}

/*create Link List by array*/
Node* createLinkWithLoop()
{
	Node *head = new Node;
	Node *p = head;
	Node *record = NULL; 

	// loop is 7->4->5->6->7
	int a[] = {1, 2, 3, 4, 5, 6, 7};

	for (int i=0 ; i < sizeof(a)/sizeof(int) ; i++)
	{	
		Node *node = new Node;
		node->value = a[i];

		if (i == 3)
			record = node;
			
		p->next = node;
		p = p->next;

		if ((i+1) >= sizeof(a)/sizeof(int))
			p->next = record;
	}

	return head;
}

/** is a loop exist in link **/
bool isLoopExist(Node* head)
{
	if (head == NULL || head->next == NULL)
		return false;

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

		if (slowPtr == fastPtr)
			return true;
	}

	return false;
}

Node* finLoopExit(Node* head)
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

		if (slowPtr == fastPtr)
			return slowPtr;
	}

	return NULL;
}

int main()
{
	Node *head2 = createLinkWithLoop();
	Node *exit = finLoopExit(head2);

	if (exit!=NULL){
		cout << "exit address: "<<exit<<endl;
		cout << "exit node: "<<exit->value<<endl;
	}
		
	return 0;
}
