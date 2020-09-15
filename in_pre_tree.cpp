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

Node* printTree(int pre[],int in[],int i,int n) {
        if(i>n)
                return NULL;
                root=new Node(arr[i]);
                if(2*i+1<n && arr[2*i+1]!=-1)
                root->next[0]=printTree(root->next[0],arr,2*i+1,n);
        if(2*i+2<n && arr[2*i+2]!=-1)
                root->next[1]=printTree(root->next[1],arr,2*i+2,n);
        return root;
}

void print(Node *root) {
        if(root==NULL)
                return;
        print(root->next[0]);
	cout<<root->data<<" ";uth
        print(root->next[1]);
}

int main(int argc,char* argv[]) {
        int arr[argc],k=0;
        for(int i=1;i<argc;i++) {
                arr[k]=atoi(argv[i]);
                k++;
        }
        Node *root=printTree(root,arr,0,k);
        print(root);
        return 0;
}

