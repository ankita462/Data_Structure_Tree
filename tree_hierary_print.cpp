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

int height(Node *root) {
        if(root==NULL)
                return 0;
        int l=height(root->next[0]);
        int r=height(root->next[1]);
        if(l>r)
                return l+1;
        else
                return r+1;
}

void printLevel(Node *root,int l) {
        if(root==NULL)
                return;
        if(l==1)
                cout<<root->data<<" ";
        if(l>1) {
                printLevel(root->next[0],l-1);
                printLevel(root->next[1],l-1);
        }
}


void printNode(Node* root) {
        int h=height(root);
        for(int i=1;i<=h;i++) {
                printLevel(root,i);
        }
}

int main(int argc,char* argv[]) {
         Node *root=new Node(1);
        Node *node1=new Node(2);
        Node *node2=new Node(3);
        Node *node3=new Node(4);
        Node *node4=new Node(5);
        Node *node5=new Node(6);
        Node *node6=new Node(7);
        root->next[0]=node1;
        root->next[1]=node2;
        node1->next[0]=node3;
        node1->next[1]=node4;
        node2->next[0]=node5;
        node2->next[1]=node6;
        printNode(root);
        return 0;
}
