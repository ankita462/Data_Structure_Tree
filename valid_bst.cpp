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

int validBst(Node* root,int min,int max) {
	if(root==NULL)
		return 1;
	if(root->data<min || root->data>max)
		return 0;
	int l=validBst(root->next[0],min,root->data);
	int r=validBst(root->next[1],root->data,max);
	if(l && r)
		return 1;
	return 0;
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
	int val=validBst(root,INT8_MIN,INT8_MAX);
	if(val==1)
		cout<<"valid BST";
	else
		cout<<"invalid BST";
        return 0;
}
