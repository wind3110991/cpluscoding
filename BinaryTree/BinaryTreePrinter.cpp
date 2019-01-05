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

	 queue<TreeNode *> q;
	 cout<<rootNode->value<<endl;
	q.push(rootNode);
	
	while(!q.empty()) {
		TreeNode * node = q.front();
		q.pop();

		if (node->leftNode != NULL){
			cout<<node->leftNode->value<<endl;
			q.push(node->leftNode);
		}

		if (node->rightNode != NULL){
			cout<<node->rightNode->value<<endl;
			q.push(node->rightNode);
		}
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

	//建立
    CreateBinaryTree(node1, node2, node3);
    CreateBinaryTree(node1, node2, node3);
    CreateBinaryTree(node2, node4, node5);
    CreateBinaryTree(node3, node6, node7);

    printTreeByLevel(node1);
	//printLeft(node1);
	//printRight(node1);

    return 0;
}