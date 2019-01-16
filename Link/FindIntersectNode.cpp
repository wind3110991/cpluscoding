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

	return head;
}

int calLinkLength(Node *head)
{
	int len = 0;

	Node *p = head;
	
	while(p)
	{
		p = p->next;
		len++;
	}

	return len;
}


/** calculate the diff of 2 links and move the long pointer first **/
Node *findIntersectNodeOfTwoLinks(Node *head1, Node* head2)
{
	if (head1 == NULL || head2 == NULL)
		return NULL;

	Node *longPtr = NULL;
	Node *shortPtr = NULL;

	int len1 = calLinkLength(head1);
	int len2 = calLinkLength(head2);

	int diff = 0;

	if (len1 < len2){
		diff = len2 - len1;
		longPtr = head2->next;
		shortPtr = head1->next;
	}
	else{
		diff = len1 - len2;
		longPtr = head1->next;
		shortPtr = head2->next;
	}

	for (int i =diff; i>0; i--){
		if (!longPtr)
			break;

		longPtr = longPtr->next;
	}

	while(longPtr && shortPtr)
	{
		longPtr = longPtr->next;
		shortPtr = shortPtr->next;

		if (longPtr == shortPtr)
			return longPtr;
	}

	return NULL;
}


int main()
{
	Node *head1 = createLink();
	Node *head2 = createLink();
		
	Node *p1 = head1->next->next;
	Node *p2 = head2->next->next;

	p2->next = p1;
	Node * intersecNode = findIntersectNodeOfTwoLinks(head1, head2);

	if (intersecNode != NULL)
		cout <<"intersecNode:" <<intersecNode->value <<endl;
	else
		cout <<"Not Intersect"<<endl;

	return 0;
}
