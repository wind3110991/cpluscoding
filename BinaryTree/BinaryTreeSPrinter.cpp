#include<stdio.h>
#include<stack>
#include<queue>
#include<malloc.h>
#include<iostream>

using namespace std;

struct TreeNode{
	int value;

	TreeNode * leftNode;
	TreeNode * rightNode;
	
	TreeNode(int v){
		this->value = v;
	}
};

void printLeft(TreeNode * rootNode){
	if (rootNode->leftNode == NULL)
		return;

	cout<<rootNode->leftNode->value<<endl;
}

void printRight(TreeNode * rootNode){
	if (rootNode->rightNode == NULL)
		return;

	cout<<rootNode->rightNode->value<<endl;
}

void printTreeByLevel(TreeNode * rootNode){
	if (rootNode == NULL)
		return;

	 queue<TreeNode *> q1;
	 queue<TreeNode *> q2;

	q1.push(rootNode);

	stack<TreeNode *> s;

	int count = 0;
	
	while (1) {
		while (!q1.empty()) {
			TreeNode * node = q1.front();
			q1.pop();

			if (node->rightNode != NULL){
				q2.push(node->rightNode);
			}

			if (node->leftNode != NULL){
				q2.push(node->leftNode);
			}

			cout<<node->value<<endl;
		}

		while (!q2.empty()){
			TreeNode * node = q2.front();
			q2.pop();

			if (node->rightNode != NULL){
				q1.push(node->rightNode);
			}

			if (node->leftNode != NULL){
				q1.push(node->leftNode);
			}

			s.push(node);
		}

		while (!s.empty()){
			TreeNode * node = s.top();
			s.pop();
			cout<<node->value<<endl;
		}

		if (q1.empty() && q2.empty())
			break;
		
	}
}

TreeNode *CreateBinaryTree(TreeNode*root, TreeNode*left, TreeNode*right)//只需要一个函数
{

    if(root==NULL)
        return NULL;

	root->leftNode = left;
	root->rightNode = right;

    return root;//返回根节点
}

int main()
{
    TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node10 = new TreeNode(10);
	TreeNode* node11 = new TreeNode(11);
	TreeNode* node12 = new TreeNode(12);
	TreeNode* node13 = new TreeNode(13);
	TreeNode* node14 = new TreeNode(14);
	TreeNode* node15 = new TreeNode(15);
	
	//建立
    CreateBinaryTree(node1, node2, node3);
    CreateBinaryTree(node2, node4, node5);
    CreateBinaryTree(node3, node6, node7);
	CreateBinaryTree(node4, node8, node9);
	CreateBinaryTree(node5, node10, node11);
	CreateBinaryTree(node6, node12, node13);
	CreateBinaryTree(node7, node14, node15);


    printTreeByLevel(node1);
	//printLeft(node1);
	//printRight(node1);

    return 0;
}