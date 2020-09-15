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
int max1=INT8_MIN;

void print_path(Node* root,int arr[],int index) {
	int sum=0;
	if(root==NULL)
		return ;
	arr[index++]=root->data;
	if(root->next[0]==NULL && root->next[1]==NULL) {
		for(int i=0;i<index;i++) {
			cout<<arr[i]<<" ";
			sum=sum+arr[i];
		}
		cout<<endl;
		if(sum>=max1) {
			max1=sum;
		}

	}
	print_path(root->next[0],arr,index);
	print_path(root->next[1],arr,index);
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
        int arr[argc],k=0,arr1[100];
        for(int i=1;i<argc;i++) {
                arr[k++]=atoi(argv[i]);
        }
        Node *root=construct(root,arr,0,k);
	print_path(root,arr1,0);
	cout<<max1;
        return 0;
}
