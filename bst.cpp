#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
public:
    T data;
    node<T>* left;
    node<T>* right;

    node() {
        left = NULL;
        right = NULL;
    }

    node(node<T>* left, T data, node<T>* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template<class T>
class tree {
public:
    node<T>* root;

    tree() {
        root = NULL;
    }

    void insertNode(node<T>*& current, T val) {
        if (current == NULL) {
            current = new node<T>(NULL, val, NULL);
        } else if (val < current->data) {
            insertNode(current->left, val);
        } else {
            insertNode(current->right, val);
        }
    }

    void preorder(node<T>* root) {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void search(node<T>* curr, T key) {
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


};

int main() {
    tree<int> a;
    a.insertNode(a.root, 4);
    a.insertNode(a.root, 5);
    a.insertNode(a.root, 2);
    a.insertNode(a.root, 9);
    a.insertNode(a.root, 1);
    a.insertNode(a.root, 3);
   // a.preorder(a.root);
    a.search(a.root,89);
    return 0;
}
