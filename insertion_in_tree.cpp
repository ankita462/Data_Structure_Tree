#include <iostream>
#include <queue>
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
	preorder(root->next[0]);
	cout<<root->data<<" ";
	preorder(root->next[1]);
}

void insert_in_tree(Node *root,int val) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* node=q.front();
		q.pop();
		if(!node->next[0]) {
			node->next[0]=new Node(val);
			break;
		}
		else
			q.push(node->next[0]);
		if(!node->next[1]) {
			node->next[1]=new Node(val);
			break;
		}
		else 
			q.push(node->next[1]);
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
	insert_in_tree(root,50);
	cout<<endl;
	preorder(root);
	return 0;
}
