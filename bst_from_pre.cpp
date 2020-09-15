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

Node* insert(Node *head,int val) {
	if(head==NULL) 
		return new Node(val);
	else if(head->data<val)
		head->next[1]=insert(head->next[1],val);
	else if(head->data>val) 
		head->next[0]=insert(head->next[0],val);
	return head;
}

void inorder(Node* head) {
	if(head==NULL)
		return ;
	inorder(head->next[0]);
	cout<<head->data<<" ";
	inorder(head->next[1]);
}

int main(int argc,char* argv[]) {
	Node *head=NULL;
	head=insert(head,atoi(argv[1]));
	for(int i=2;i<argc;i++) {
		insert(head,atoi(argv[i]));
	}
	insert(head,90);
	inorder(head);
	return 0;
}

