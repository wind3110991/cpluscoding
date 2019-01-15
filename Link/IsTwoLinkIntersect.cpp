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

/** is two links intersect**/
bool isTwoLinkIntersect(Node* head1, Node *head2)
{
	if (head1 == NULL || head2 == NULL)
		return NULL;

	Node *p1 = head1;
	Node *p2 = head2;

	while(p1->next)
	{
		p1 = p1->next;
	}

	while(p2->next)
	{
		p2 = p2->next;
	}

	if (p1 == p2)
		return true;
		
	return false;
}

int main()
{
	Node *head1 = createLink();
	Node *head2 = createLink();

	if (isTwoLinkIntersect(head1, head2))
		cout <<"Intersect"<<endl;
	else
		cout <<"Not Intersect"<<endl;
		
	Node *p1 = head1->next->next;
	Node *p2 = head2->next->next;

	p2->next = p1->next;
	if (isTwoLinkIntersect(head1, head2))
		cout <<"Intersect"<<endl;
	else
		cout <<"Not Intersect"<<endl;

	return 0;
}
