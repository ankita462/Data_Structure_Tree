#include <iostream>
#include <map>
#include <vector>
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

void mirrorTree(Node* root) {
	if(root==NULL)
		return ;
	if(root->next[0]!=NULL && root->next[1]!=NULL) {
        mirrorTree(root->next[0]);
	mirrorTree(root->next[1]);
	}
        Node* temp=NULL;
	temp=root->next[0];
	root->next[0]=root->next[1];
	root->next[1]=temp;	
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
        Node *root=construct(root,arr,0,k);
        mirrorTree(root);
	preorder(root);
        return 0;
}

