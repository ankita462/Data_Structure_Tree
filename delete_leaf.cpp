#include <iostream>
#include <bits/stdc++.h>
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

Node* delete_leaf(Node* head,int val) {
	if(head==NULL)
		return NULL;
	if(head->data>val)
	head->next[0]=delete_leaf(head->next[0],val);
	if(head->data<val)
	head->next[1]=delete_leaf(head->next[1],val);
	if(head->data==val && head->next[0]==NULL && head->next[1]==NULL) {
		delete(head);
		return NULL;
	}
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
	delete_leaf(head,50);
        inorder(head);
        return 0;
}

