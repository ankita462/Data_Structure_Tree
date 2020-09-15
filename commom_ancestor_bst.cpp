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

int common_ancestor(Node* head,int n1,int n2) {
	 if(head==NULL)
		return 0;
	 if(head->data<n1 && head->data < n2)
		 return common_ancestor(head->next[1],n1,n2);
	 if(head->data>n1 && head->data>n2)
		return common_ancestor(head->next[0],n1,n2);
	 return head->data;
}

Node* insert(Node *head,int val) {
        if(head==NULL)
                return new Node(val);
        else if(head->data<val)
                head->next[1]=insert(head->next[1],val);
        else if(head->data>val)
                head->next[0]=insert(head->next[0],val);
        return head;
}


int main(int argc,char* argv[]) {
        Node *head=NULL;
        head=insert(head,atoi(argv[1]));
        for(int i=2;i<argc-3;i++) {
                insert(head,atoi(argv[i]));
        }
	int n=atoi(argv[argc-2]);
	int n1=atoi(argv[argc-1]);
	cout<<common_ancestor(head,n,n1);
        return 0;
}
