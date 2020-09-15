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

void hori_dist(Node* root,int hd,map<int,vector<int>>&m) {
	if(root==NULL)
		return ;
	m[hd].push_back(root->data);
	hori_dist(root->next[0],hd-1,m);
	hori_dist(root->next[1],hd+1,m);
}

void verticalOrder(Node* root) {
	if(root==NULL) 
		return ;
	map <int,vector<int>> m;
	hori_dist(root,0,m);
	map <int,vector <int>> :: iterator it;
	for(it=m.begin();it!=m.end();it++) {
		for(int i=0;i<it->second.size();i++) {
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

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

int main(int argc,char* argv[]) {
	int arr[argc],k=0;
	for(int i=1;i<argc;i++) {
		arr[k++]=atoi(argv[i]);
	}
	Node* root=construct(root,arr,0,k);
	verticalOrder(root);
	return 0;
}
