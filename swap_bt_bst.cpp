#include <iostream>
#include <stack>
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

Node* construct_tree(Node* root,int arr[],int i,int n) {
	 if(i>n)
                return NULL;
                root=new Node(arr[i]);
        if(2*i+1<n && arr[2*i+1]!=-1)
                root->next[0]=construct_tree(root->next[0],arr,2*i+1,n);
        if(2*i+2<n && arr[2*i+2]!=-1)
                root->next[1]=construct_tree(root->next[1],arr,2*i+2,n);
        return root;
}

int* inorder(Node* root) {
	int *arr=new int[100];
	int i=0;
	stack <Node*> s;
	Node* curr=root;
	while(!s.empty() || curr!=NULL) {
		while(curr!=NULL) {
			s.push(curr);
			curr=curr->next[0];
		}
		curr=s.top();
		arr[i++]=curr->data;
		s.pop();
		curr=curr->next[1];
	}
	return arr;
}


int main(int argc,char* argv[]) {
	int arr[argc],k=0;
	for(int i=1;i<argc;i++) {
		arr[k++]=atoi(argv[i]);
	}
	Node* root=construct_tree(root,arr,0,k);
	int *arr1=inorder(root);
	for(int i=0;i<k;i++) {
	cout<<arr1[i]<<" ";
	}	
	return 0;
}
