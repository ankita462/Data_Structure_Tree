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
int index=0;

void level(Node* root,int l) {
	if(root==NULL)
		return ;
	if(l==1 && index==1) {
		index=0;
		cout<<root->data<<" ";
	}
	if(l>1)
		level(root->next[0],l-1);
		level(root->next[1],l-1);
}


int height(Node* root) {
	if(root==NULL)
		return 0;
	int l=height(root->next[0]);
	int r=height(root->next[1]);
	 return l>r?l+1:r+1;
}


void leftView(Node* root) {
	int h=height(root);
	for(int i=1;i<=h;i++) {
		index=1;
		level(root,i);
	}
}

Node* construct(Node* root,int arr[],int i,int n) {
	if(i>n) 
		return NULL;
	root=new Node(arr[i]);
	if(2*i+1<n && arr[2*i+1]!=-1) 
		root->next[0]=construct(root->next[0],arr,2*i+1,n);
	if(2*i+2<n && arr[2*i+2]!=-1)
		root->next[1]=construct(root->next[1],arr,2*i+2,n);
	return root;
}

int main(int argc,char* argv[]) {
	int arr[argc],k=0;
	for(int i=1;i<argc;i++) {
		arr[k++]=atoi(argv[i]);
	}
	Node *root=construct(root,arr,0,k);
	leftView(root);
	return 0;
}
