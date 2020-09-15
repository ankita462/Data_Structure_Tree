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

Node* construct(Node *root,int arr[],int i,int n) {
    if(i>n)
        return NULL;
    root=new Node(arr[i]);
    if(arr[2*i+1]!=-1 && 2*i+1<n)
        root->next[0]=construct(root->next[0],arr,2*i+1,n);
    if(arr[2*i+2]!=-1 && 2*i+2<n)
        root->next[1]=construct(root->next[1],arr,2*i+2,n);
    return root;
}

void find_parent(Node* root,int parent,int val) {
   if(root==NULL)
	return ;	   
   if(root->data==parent)
    	cout<<val;
   else {
   find_parent(root->next[0],parent,root->data);
   find_parent(root->next[1],parent,root->data);  
   }
}

int main(int argc,char* argv[]) {
    int arr[argc],k=0;
    int parent=atoi(argv[1]);
    for(int i=2;i<argc;i++)
        arr[k++]=atoi(argv[i]);
        Node* root=construct(root,arr,0,k);
    find_parent(root,parent,-1);
    return 0;
}
