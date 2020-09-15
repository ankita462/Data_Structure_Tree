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

void inorder(Node* root) {
	if(root==NULL)
		return ;
	inorder(root->next[0]);
	if(root->data!=0) 
	cout<<root->data<<" ";
	inorder(root->next[1]);
}

Node* construct(Node* root,int arr[],int i,int n) {
	if(i>n)
		return NULL;
	root=new Node(arr[i]);
	if(i*2+1<n && arr[2*i+1]!=-1)
		root->next[0]=construct(root->next[0],arr,2*i+1,n);
	if(2*i+2<n && arr[2*i+2]!=-1)
		root->next[1]=construct(root->next[1],arr,2*i+2,n);
	return root;
}

void deletedeep(Node* root,Node* node) {
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node *temp=q.front();
		q.pop();
		if(temp==node) {
			temp==NULL;
			delete(node);
			return ;
		}
		if(temp->next[0]) {
			if(temp->next[0]==node) {
				temp->next[0]==NULL;
				delete(node);
				return ;
			}
			else
				q.push(temp->next[0]);
		}
		if(temp->next[1]) {
			if(temp->next[1]==node) {
				temp->next[1]==NULL;
				delete(node);
				return ;
			}
			else
				q.push(temp->next[1]);
		}
	}
}

Node* deletenode(Node* root,int val) {
	if(root==NULL)
		return NULL;
	if(root->next[0]==NULL && root->next[1]==NULL) {
		if(root->data==val)
			return NULL;
		else
			return root;
	}
	queue <Node*> q;
	q.push(root);
	Node* temp;
	Node* node=NULL;
	while(!q.empty()) {
		temp=q.front();
		q.pop();
		if(temp->data==val) 
			node=temp;
		if(temp->next[0])
			q.push(temp->next[0]);
		if(temp->next[1])
			q.push(temp->next[1]);
	}
	if(node!=NULL) {
		int x=temp->data;
		deletedeep(root,temp);
		node->data=x;
	}
	return root;
}

int main(int argc,char* argv[]) {
	int val=atoi(argv[1]);
	int arr[argc],k=0;
	for(int i=2;i<argc;i++) 
		arr[k++]=atoi(argv[i]);
	Node* root=construct(root,arr,0,k);
	root=deletenode(root,val);
	inorder(root);
	return 0;
}
