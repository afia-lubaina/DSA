#include <iostream> 
using namespace std; 
#define debug(x) cerr << (#x) << ' ' << x << endl;
  
//Our binary tree node
struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
//Create a node
Node* create(int data) 
{ 
    Node* node = new Node ;
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// Insert the nodes in the tree
Node* insert(int arr[], Node* root, int i, int n) 
{ 
    if (i < n) 
    { 
        Node* temp = create(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insert(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insert(arr, root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
 
 
//Print the tree by inorder traversal
void inorder(Node* root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->data <<" "; 
        inorder(root->right); 
    } 
}

int num(Node *root){

    if(root == NULL)
    return 0;

    return 1+num(root->left)+num(root->right);
}


bool iscomplete(Node *root, int index, int number){

    if(root ==NULL)
       return true;
    else if(index >= number)
       return false;
    return iscomplete(root->left,2*index+1,number) && iscomplete(root->right,2*index+2,number);
}

bool is_maxheap(Node *root){

    Node *p1=root;
    Node *p2=root;

    bool f=1;
    while(p1!=NULL){

        
        if (p1->left == NULL && p1->right == NULL)
        {
            break;
        }
        else if(p1->left!=NULL && p1->right==NULL && p1->left->data>p1->data)
           {
            f=0; break;
           }
        else if(p1->left!=NULL && p1->right==NULL && p1->left->data<p1->data)
           {
             break;
           }
        else if(p1->left->data > p1->data   ||   p1->right->data > p1->data)
           {
            f=0; break;
           }
        debug(p1->data);
        debug(p1->left->data);
        debug(p1->right->data);
        
        p1=p1->left;
    }

    while(p2!=NULL){

        
        if (p2->left == NULL && p2->right == NULL)
        {
            break;
        }
        else if(p2->left!=NULL && p2->right==NULL && p2->left->data>p2->data)
           {
            f=0; break;
           }
        else if(p2->left!=NULL && p2->right==NULL && p2->left->data<p2->data)
           {
             break;
           }
        else if(p2->left->data > p2->data   ||   p2->right->data > p2->data)
           {
            f=0; break;
           }
        debug(p2->data);
        debug(p2->left->data);
        debug(p2->right->data);
        
        p2=p2->right;
    }
    return f;
}

bool is_minheap(Node *root){

    Node *h1=root;
    Node *h2=root;

    bool f=1;
    while(h1!=NULL){

        
        if (h1->left == NULL && h1->right == NULL)
        {
            break;
        }
        else if(h1->left!=NULL && h1->right==NULL && h1->left->data<h1->data)
           {
            f=0; break;
           }
        else if(h1->left!=NULL && h1->right==NULL && h1->left->data>h1->data)
           {
             break;
           }
        else if(h1->left->data < h1->data   ||   h1->right->data < h1->data)
           {
            f=0; break;
           }
        // debug(h1->data);
        // debug(h1->left->data);
        // debug(h1->right->data);
        
        h1=h1->left;
    }

    while(h2!=NULL){

        
        if (h2->left == NULL && h2->right == NULL)
        {
            break;
        }
        else if(h2->left!=NULL && h2->right==NULL && h2->left->data<h2->data)
           {
            f=0; break;
           }
        else if(h2->left!=NULL && h2->right==NULL && h2->left->data>h2->data)
           {
             break;
           }
        else if(h2->left->data < h2->data   ||   h2->right->data < h2->data)
           {
            f=0; break;
           }
        // debug(h2->data);
        // debug(h2->left->data);
        // debug(h2->right->data);
        
        h2=h2->right;
    }
    return f;
}



bool isHeap(Node *root){

    int number = num(root);
  //  debug(number);
    int i=iscomplete(root,0,number);
  //  debug(i);
  //  int k=is_minheap(root);
   // debug(k);



    if(iscomplete(root,0,number) && (is_maxheap(root) || is_minheap(root)))
      return true;

    return false;



}
  
//Main function
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insert(arr, root, 0, n); 
    inorder(root);
    if(isHeap(root))
        cout<<"yes"<<endl; 
    else 
        cout<<"no"<<endl;
    return 0;
} 
