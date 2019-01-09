#include<iostream>
#include<map>
using namespace std;

struct Node
{
	int value;
	Node *next;

	Node(int v){
		this->value = v;
	}
};

void printLink(Node *head)
{
	if (head == NULL)
		return;

	Node *p = head;

	while(p)
	{
		cout<<p->value<<endl;
		p = p->next;
	}

	cout<<"--------------"<<endl;
}

/*create Link List by array*/
Node* createLink()
{
	Node *head = NULL;
	Node *p;

	int a[] = {1,  3, 5,  7};

	for (int i=0 ; i<4 ; i++)
	{	
		Node *node = new Node(a[i]);
		
		if (head == NULL)
		{
			head = node;
			p = head;		
		}
		else{
			p->next = node;
			p = p->next;
		}

		p->next = NULL;
	}

	return head;
}

Node* createLink2()
{
	Node *head = NULL;
	Node *p;

	int a[] = {0,  2,  6, 8};

	for (int i=0 ; i<4 ; i++)
	{	
		Node *node = new Node(a[i]);
		
		if (head == NULL)
		{
			head = node;
			p = head;		
		}
		else{
			p->next = node;
			p = p->next;
		}

		p->next = NULL;
	}

	return head;
}

Node *mergeSortedTwoLinks(Node *head1, Node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL && head2 != NULL)
		return head2;
	else if (head2 == NULL && head1 != NULL)
		return head1;

	Node * newHead=NULL;
	Node * p1 = head1->next;
	Node * p2 = head2->next;

	if (head1->next->value > head2->next->value)
		newHead = head2;
	else
		newHead = head1;

	Node * p3 = newHead;

	while (p1 && p2){
		if (p1->value > p2->value)
		{
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
		}

		else
		{
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
	}

	// if p1 is null , but p2 is not null
	if (p1 == NULL && p2 != NULL)
		p3->next = p2;
	if (p2 == NULL && p1 != NULL)
		p3->next = p1;

	return newHead;
}

int main()
{
	Node *head1 = createLink();
	printLink(head1);

	Node *head2 = createLink2();
	printLink(head2);

	Node *newNode = mergeSortedTwoLinks(head1, head2);
	printLink(newNode);

	return 0;
}
