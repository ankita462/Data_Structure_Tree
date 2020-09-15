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

void postorder(Node *root) {
        if(root==NULL)
                return;
        postorder(root->next[0]);
        postorder(root->next[1]);
	cout<<root->data<<" ";
}

int main(void) {
        Node *root=new Node(1);
        Node *node1=new Node(2);
        Node *node2=new Node(3);
        Node *node3=new Node(4);
        Node *node4=new Node(5);
        root->next[0]=node1;
        root->next[1]=node2;
        node1->next[0]=node3;
        node1->next[1]=node4;
        postorder(root);
        return 0;
}

