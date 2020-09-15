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

Node* construct(Node* root,int arr[],int i,int n) {
        if(i>n)
                return NULL;
        root=new Node(arr[i]);
        if(arr[2*i+1]!=-1 && 2*i+1<n)
                root->next[0]=construct(root->next[0],arr,2*i+1,n);
        if(arr[2*i+2]!=-1 && 2*i+2<n)
                root->next[1]=construct(root->next[1],arr,2*i+2,n);
        return root;
}

void inorder(Node *root,int arr[],int &index) {
        if(root==NULL)
                return ;
        inorder(root->next[0],arr,index);
        arr[index++]=root->data;
        inorder(root->next[1],arr,index);
}

void convert(Node* root,int arr[],int &in) {
        if(root==NULL)
                return ;
	root->data=arr[in++];
        convert(root->next[0],arr,in);
        convert(root->next[1],arr,in);
}

void postorder(Node* root) {
        if(root==NULL)
                return ;
        postorder(root->next[0]);
        postorder(root->next[1]);
        cout<<root->data<<" ";
}

int main(int argc,char* argv[]) {
        int arr[argc],k=0,arr1[argc],in=0,index=0;
        for(int i=1;i<argc;i++)
                arr[k++]=atoi(argv[i]);
        Node *root=construct(root,arr,0,k);
        inorder(root,arr1,in);
        convert(root,arr1,index);
        postorder(root);
        return 0;
}

