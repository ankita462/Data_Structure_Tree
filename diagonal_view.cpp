#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
    public:
    string data;
    Node* next[2];
    Node(string data) {
        this->data=data;
        next[0]=next[1]=NULL;
    }
};

Node* construct(Node* root,string arr[],int i,int n) {
    if(i>n)
        return NULL;
    root=new Node(arr[i]);
    if(2*i+1<n && arr[2*i+1]!="_") 
        root->next[0]=construct(root->next[0],arr,2*i+1,n);
    if(2*i+2<n && arr[2*i+2]!="_")
        root->next[1]=construct(root->next[1],arr,2*i+2,n);
    return root;
}

void diagonal(Node* root,int hd,map<int,vector<string>>&m) {
    if(!root)
        return ;
    m[hd].push_back(root->data);
    diagonal(root->next[0],hd+1,m);
    diagonal(root->next[1],hd,m);
}

void diagonalPrint(Node* root) {
    map<int,vector<string>>m;
    diagonal(root,0,m);
    for(auto it=m.begin();it!=m.end();it++) {
        for(auto itr=it->second.begin();itr!=it->second.end();itr++) {
            cout<<*itr<<" ";
        }
    }
}

int main(int argc,char* argv[]) {
    string arr[argc];
    int k=0;
    for(int i=1;i<argc;i++) 
        arr[k++]=argv[i];
    Node* root=construct(root,arr,0,k);
    diagonalPrint(root);
    return 0;
}
