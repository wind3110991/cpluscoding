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

	int a[] = {1, 2, 3, 4, 5, 6};

	for (int i=0 ; i<6 ; i++)
	{	
		Node *node = new Node;
		node->value = a[i];

		p->next = node;
		p = p->next;
	}

	//p->next = NULL;

	return head;
}

/** find the last k node of link **/
Node* findKNodeDesc(Node* head, int k)
{
	if (head == NULL || k < 0)
		return NULL;

	Node *p1 = head->next;
	Node *p2 = p1;
	int count = 0;

	while (p2){
		if (count == k)
		{
			p1 = p1->next;
		}
		else
		{
			count++;
		}

		p2 = p2->next;
	}

	cout<<"count:"<<count<<endl;
	if (count <= k - 1)
		return NULL;

	return p1;
}

int main()
{
	Node *head = createLink();
	Node * newhead = findKNodeDesc(head, 1);
	cout<<newhead->value;
	
	return 0;
}
