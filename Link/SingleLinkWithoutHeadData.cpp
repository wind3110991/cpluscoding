#include<iostream>
#include<map>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

void printLink(Node *head)
{
	if (head == NULL)
		return;

	Node *p = head->next;

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
	Node *head = new Node;
	Node *p = head;

	int a[] = {1, 2, 3,7, 4, 5, 6, 7};

	for (int i=0 ; i<8 ; i++)
	{	
		Node *node = new Node;
		node->value = a[i];

		p->next = node;
		p = p->next;
	}

	//p->next = NULL;

	return head;
}

/*insert a node at the index of Link List*/
void insertNode(Node *head, int value, int index)
{
	Node * node = new Node;
	node->value = value;
	
	if (head == NULL)
		return;
	else{
		Node *p = head->next;
		
		for (int i = 0; i <= index; i++)
		{
			if (p == NULL){
				break;
			}
				
			if (index == i){
				node->next = p->next;
				p->next = node;
				break;
			}

			p = p->next; 
		}
	}
}

/*delet a node by value*/
void deleteNode(Node *head, int value)
{
	Node *p = head->next;
	if (head == NULL || p == NULL)
		return;

	while (p->next != NULL)
	{
		// 如果为头
		if (p->value == value)
		{
			Node * tmp = p;
			p = p->next;
			head ->next = p;

			delete tmp;
			tmp = NULL;
		}

		else{
			if (p->next->value == value){
				Node *tmp = p->next;
				p->next = p->next->next;

				delete tmp;
				tmp = NULL;
			}

		if (p->next != NULL)
			p = p->next;	
		}
	}
}

/*delet duply node by value*/
void deleteDuplyNode(Node *head)
{
	map<int, int> m;
	if (head == NULL)
		return;

	Node *p = head->next;
	if (p == NULL)
		return;

	while (p->next != NULL)
	{
		if (m.find(p->next->value) != m.end()){
			Node *tmp = p->next;
			p->next = p->next->next;

			delete tmp;
			tmp = NULL;
		}else{
			m[p->next->value] = 1;
		}

		if (p->next != NULL)
			p = p->next;	
	}

	cout<<"head address:"<<head<<endl;
	cout<<"head value:"<<head->value<<endl;

}

int main()
{
	Node *head = createLink();
	printLink(head);

	insertNode(head, 100, 3);
	printLink(head);

	deleteDuplyNode(head);
	printLink(head);

	deleteNode(head, 7);
	printLink(head);

	deleteNode(head, 1);
	printLink(head);
}
