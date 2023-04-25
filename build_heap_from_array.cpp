#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr << (#x) << ' ' << x << endl;

class Node{
    public:
    Node *left;
    Node *right;
    int val;
    Node(int x):val(x),left(NULL),right(NULL) {};
};

class tree{
    public:
    Node *root;
    tree():root(NULL){};

    
    Node *buildTreehelper(int arr[], int sz, int index){

            if(index>=sz || arr[index]=='N')
                return NULL;
            Node *node = new Node(arr[index]);
            node->left=buildTreehelper(arr,sz,  2 * index+1);
            node->right=buildTreehelper(arr,sz, 2 * index+2);
            return node;
    }



    void buildTree(int arr[], int sz){
        if(sz==0)
            return;
  
        root = buildTreehelper(arr, sz,0);
        
    }



};

int main(){

    int arr[]={8,7,6,5,4,3,2,1};
    tree a;
    a.buildTree(arr,8);
  //  a.inorderprint(a.root);

 //   cout<<a.is_maxheap(a.root)<<"\n";
   
    


}
