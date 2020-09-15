#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next[2];
};

struct Node* newNode(int data) {
	struct Node*  node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next[0]=NULL;
	node->next[1]=NULL;
	return node;
}

struct Node* print(struct Node* root,int arr[],int i,int n) {
	if(i>n)
		return NULL;
	root=newNode(arr[i]);
	if(2*i+1<n && arr[2*i+1]!=-1) 
		root->next[0]=print(root->next[0],arr,2*i+1,n);
	if(2*i+2<n && arr[2*i+2]!=-1) 
		root->next[1]=print(root->next[1],arr,2*i+2,n);
	return root;
}

void preorder(struct Node* root) {
	if(root==NULL)
		return ;
	printf("%d ",root->data);
	preorder(root->next[0]);
	preorder(root->next[1]);
}

int main(int argc,char* argv[]) {
	int arr[argc],k=0;
	for(int i=1;i<argc;i++) {
		arr[k++]=atoi(argv[i]);
	}
	struct Node* root=print(root,arr,0,k);
	preorder(root);
	return 0;
}
