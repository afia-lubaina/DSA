#include <bits/stdc++.h>
using namespace std;


class node {
public:
    int data;
    node* left;
    node* right;

    node() {
        left = NULL;
        right = NULL;
    }

    node(node* left, int data, node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


class tree {
public:
    node* root;

    tree() {
        root = NULL;
    }

    void insertNode(node*& current, int val) {
        if (current == NULL) {
            current = new node(NULL, val, NULL);
        } else if (val < current->data) {
            insertNode(current->left, val);
        } else {
            insertNode(current->right, val);
        }
    }

    void preorder(node* root) {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void search(node* curr, int key) {
    if (curr == NULL) {
        cout << "Not found\n";
        return;
    }
    if (curr->data == key) {
        cout << "Found: " << curr->data << "\n";
        return;
    }
    if (curr->data > key) {
        search(curr->left, key);
    } else {
        search(curr->right, key);
    }
}   

    int height(node *root){
        if(root==NULL)
            return 0; 
        
        int lh=height(root->left);
        int rh=height(root->right);

        return max(rh,lh)+1;

    }

    bool isBalanced(node* root)
    {
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left)
        && isBalanced(root->right))
        return 1;
 
    return 0;
    }


};

int main() {
    tree a;
    a.insertNode(a.root, 4);
    a.insertNode(a.root, 5);
    a.insertNode(a.root, 7); 
   // a.insertNode(a.root, 9);
   // a.insertNode(a.root, 9);
    //a.insertNode(a.root, 3);
   // a.preorder(a.root);
    a.search(a.root,9);
    cout<<a.isBalanced(a.root)<<"\n";
    return 0;
}
