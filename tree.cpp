#include <iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
class Node{
        public:
        int data;
        Node* next[2];
         Node(int data)
        {
                this->data = data;

                next[0] = next[1] = NULL;
        }
};
int tree_height(Node* root)
{
        if(root==NULL)
                return 0;
        else{
                int r=tree_height(root->next[0]);
                int l=tree_height(root->next[1]);
                if(l>r)
                        return (l+1);
                else return(r+1);
        }
}
void printlevel(Node* root, int level)
{
        int h1=tree_height(root);
        if(root==NULL)
                return;
        if(level==1){
                for(int j=h1;j>0;j--)
                        cout<<"  ";
                cout<<root->data<<" ";
                  if(root->next[0]!=NULL && root->next[1]!=NULL)
                        cout<<"/ \\";

        }
        else{
                printlevel(root->next[0],level-1);
                printlevel(root->next[1],level-1);
        }
}
void printorder(Node * root)
{
        int h=tree_height(root);
        for (int i=1;i<=h;i++){
                printlevel(root,i);
                        cout<<endl;

        }}
int main(int argc,const  char *argv[])
{
        Node *root = new Node(1);
        root->next[0]= new Node(2);
        root->next[1] = new Node(3);
        root->next[0]->next[0] = new Node(4);
        root->next[0]->next[1]= new Node(5);
        printorder(root);
        return 0;
}

