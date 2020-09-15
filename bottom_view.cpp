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

void horizontal_distance(Node* root,int hd,map<int,vector<int>>&m) {
        if(root==NULL)
                return;
        m[hd].push_back(root->data);
        horizontal_distance(root->next[0],hd-1,m);
        horizontal_distance(root->next[1],hd+1,m);
}

void bottomView(Node* root) {
       map <int, vector<int>> m;
       horizontal_distance(root,0,m);
       map <int, vector<int>> :: iterator it;
       for(it=m.begin();it!=m.end();it++) {
               cout<<it->second[it->second.size()-1]<<" ";
       }
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
        bottomView(root);
        return 0;
}

