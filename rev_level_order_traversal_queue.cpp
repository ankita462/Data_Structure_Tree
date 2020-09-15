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

void print_level(Node *root) {
        if(root==NULL)
                return;
        queue <Node*> q;
        q.push(root);
        while(q.empty()==false) {
                Node *node=q.front();
                cout<<node->data<<" ";
                q.pop();
                if(node->next[1]!=NULL)
                        q.push(node->next[1]);
                if(node->next[0]!=NULL)
                        q.push(node->next[0]);
        }
}



Node* printTree(Node* root,int arr[],int i,int n) {
        if(i>n)
                return NULL;
                root=new Node(arr[i]);
        if(2*i+1<n && arr[2*i+1]!=-1)
                root->next[0]=printTree(root->next[0],arr,2*i+1,n);
        if(2*i+2<n && arr[2*i+2]!=-1)
                root->next[1]=printTree(root->next[1],arr,2*i+2,n);
        return root;
}



int main(int argc,char* argv[]) {
        int arr[argc],k=0;
        for(int i=1;i<argc;i++) {
                arr[k]=atoi(argv[i]);
                k++;
        }
        Node *root=printTree(root,arr,0,k);
        print_level(root);
        return 0;
}

