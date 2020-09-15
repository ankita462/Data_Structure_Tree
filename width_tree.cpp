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

int width(Node *root,int l) {
        if(root==NULL)
                return 0;
        if(l==1)
                return 1;
        if(l>1) {
               return (width(root->next[0],l-1)+width(root->next[1],l-1));
        }
}

int max_width(Node *root) {
	int h=height(root);
	int max=0;
	for(int i=1;i<=h;i++) {
		int w=width(root,i);
		if(w>max)
			max=w;
	}
	return max;
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
        int w=max_width(root);
	cout<<w;
        return 0;
}

