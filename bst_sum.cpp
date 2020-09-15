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

int arr1[100],in=1,sum=0;
Node* insert(Node* root,int val) {
    if(root==NULL)
        return new Node(val);
    if(root->data<val) 
        root->next[1]=insert(root->next[1],val);
    if(root->data>val)
        root->next[0]=insert(root->next[0],val);
        return root;
}

void inorder(Node* root,int arr[],int &index) {
    if(root==NULL)
    return ;
    inorder(root->next[0],arr,index);
    if(root->data!=-1)
    arr[index++]=root->data;
    inorder(root->next[1],arr,index);
}

void inorder1(Node* root) {
    if(root==NULL)
    return ;
    inorder1(root->next[0]);
     cout<<root->data<<" ";
    inorder1(root->next[1]);
}

int sum2(Node* root,int arr1[],int n) {
    if(root==NULL)
     return -1;
    for(int i=1;i<=n;i++) {
           sum+=arr1[i];
       }
        return sum;
}

int main(int argc,char* argv[]) {
    Node* root=NULL;
    int sum=0;
    int n=atoi(argv[1]);
    root=insert(root,atoi(argv[2]));
    for(int i=3;i<argc;i++)
       root=insert(root,atoi(argv[i]));
       inorder1(root);
    cout<<endl;
       inorder(root,arr1,in);
     int sum1=sum2(root,arr1,n);  
       cout<<sum1;
    return 0;
}
