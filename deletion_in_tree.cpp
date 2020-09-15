#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stdlib.h>
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

void preorder(Node* root) {
        if(root==NULL)
                return ;
        cout<<root->data<<" ";
        preorder(root->next[0]);
        preorder(root->next[1]);
}

Node* last_node(Node *root) {
	if(root==NULL)
		return NULL;
	while(root->next[0]!=NULL) 
		root=root->next[0];
	while(root->next[1]!=NULL) 
		root=root->next[1];
	//	cout<<root->data;
	return root;
}

void delete_tree(Node *root,int val) {
	if(root==NULL)
		return ;
	Node* node=last_node(root);
	queue <Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *node1=q.front();
		q.pop();
		if(node1->data==val) {
			int temp=node1->data;
			node1->data=node->data;
			node->data=temp;
		}
		if(node1->next[0]) 
			q.push(node1->next[0]);
		if(node1->next[1])
			q.push(node1->next[1]);
	}
}


Node* construct_tree(Node* root,int arr[],int i,int n) {
        if(i>n)
                return NULL;
                root=new Node(arr[i]);
        if(2*i+1<n && arr[2*i+1]!=-1)
                root->next[0]=construct_tree(root->next[0],arr,i*2+1,n);
        if(2*i+2<n && arr[2*i+2]!=-1)
                root->next[1]=construct_tree(root->next[1],arr,2*i+2,n);
        return root;
}

int main(int argc,char* argv[]) {
        int arr[argc],k=0;
        for(int i=1;i<argc;i++) {
                arr[k]=atoi(argv[i]);
                k++;
        }
        Node *root=construct_tree(root,arr,0,k);
        preorder(root);
        delete_tree(root,2);
	Node *node=last_node(root);
	delete(node);
        cout<<endl;
        preorder(root);
        return 0;
}

