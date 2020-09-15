#include <iostream>
using namespace std;

int search(int in[],int item,int n) {
	for(int i=0;i<n;i++) {
		if(item==in[i]) 
			return i;
	}
		return -1;
}

void postOrder(int in[],int pre[],int n) {
	int root=search(in,pre[0],n);
	if(root!=0)
		postOrder(in,pre+1,root);
	if(root!=n-1)
		postOrder(in+root+1,pre+root+1,n-root-1);
	cout<<pre[0]<<" ";
}


int main(int argc,char* argv[]) {
	int n=atoi(argv[1]);
	int arr1[n],arr[n],k=0,k1=0;
        for(int i=2;i<n+2;i++) {
                arr[k]=atoi(argv[i]);
                k++;
        }
        for(int i=n+2;i<argc;i++) {
		arr1[k1++]=atoi(argv[i]);
	}
        postOrder(arr,arr1,k);
        return 0;
}


