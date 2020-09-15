#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next[2];
	Node(int data) {
		this->data=data;
		next[0]=next[1]=NULL;
	}
};

void preorder(Node *root) {
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->next[0]);
	preorder(root->next[1]);
}

int main(void) {
	Node *root=new Node(1);
	Node *node1=new Node(2);
	Node *node2=new Node(3);
	Node *node3=new Node(4);
	Node *node4=new Node(5);
	root->next[0]=node1;
	root->next[1]=node2;
	node1->next[0]=node3;
	node1->next[1]=node4;
	preorder(root);
	return 0;
}
