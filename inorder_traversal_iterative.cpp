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

void inorder(Node* root) {
        if(root==NULL)
                return ;
	Node* curr=root;
	stack <Node*> s;
	while(!s.empty() || curr!=NULL) {
		while(curr!=NULL) {
			s.push(curr);
			curr=curr->next[0];
		}
		curr=s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr=curr->next[1];
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
        inorder(root);
        return 0;
}

