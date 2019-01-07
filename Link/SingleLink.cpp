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

	int a[] = {1, 2, 3,7, 4, 5, 6, 7};

	for (int i=0 ; i<8 ; i++)
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

/*insert a node at the index of Link List*/
void insertNode(Node *head, int value, int index)
{
	Node * node = new Node(value);
	
	if (head == NULL)
		head = node;
	else{
		Node *p = head;
		
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
Node* deleteNode(Node *head, int value)
{
	if (head == NULL)
		return NULL;

	Node *p = head;
	while (p->next != NULL)
	{
		// 如果为头
		if (head->value == value)
		{
			Node * tmp = head;
			head= head->next;

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

	cout<<"head address:"<<head<<endl;
	cout<<"head value:"<<head->value<<endl;

	return head;
}

/*delet duply node by value*/
Node* deleteDuplyNode(Node *head)
{
	map<int, int> m;
	if (head == NULL)
		return NULL;

	Node *p = head;
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

	return head;
}

int main()
{
	Node *head = createLink();
	printLink(head);
	
	// insertNode(head, 12, 2);
	// printLink(head);

	//deleteNode(head, 12);
	head = deleteDuplyNode(head);
	printLink(head);

	//deleteNode(head, 7);
	// cout<<"after delete"<<endl;
	cout<<"out head address:"<<head<<endl;
	printLink(head);
}
