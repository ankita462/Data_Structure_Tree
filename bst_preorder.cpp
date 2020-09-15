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

Node* construct(int arr[],int *preindex,int low,int high,int size) {
	if(*preindex>=size || low>high) 
		return NULL;
	Node *root=new Node(arr[*preindex]);
	*preindex=*preindex+1;
	if(low==high)
		return root;
	int i;
	for(i=low;i<=high;i++) 
		if(arr[i]>root->data) 
			break;
	root->next[0]=construct(arr,preindex,*preindex,i-1,size);
	root->next[1]=construct(arr,preindex,i,high,size);
	return root;
}

Node* construct_bst(int arr[],int size) {
	int preindex=0;
	return construct(arr,&preindex,0,size-1,size);
}

void preorder(Node* root) {
	if(root==NULL) 
		return ;
		cout<<root->data<<" ";
		preorder(root->next[0]);
		preorder(root->next[1]);
}

int main(int argc,char* argv[]) {
	int arr[argc],k=0;
	for(int i=1;i<argc;i++) {
		arr[k++]=atoi(argv[i]);
	}
	Node* root=construct_bst(arr,k);

	preorder(root);
	return 0;
}
