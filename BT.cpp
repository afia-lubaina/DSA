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

    T search(T in[],T val, int start, int end){
         
        for (int i = start; i <= end; i++)
        {
           if(in[i]==val)
           return i; 
        }

        return -1;
        
    }

    node<T> *Build_in_n_pre(T in[], T pre[], int start,int end ){
        static int ix=0;
        if(start>end)
          return NULL; 
        
        T rootval= pre[ix++];
        node <T>*newnode= new node<T> (NULL, rootval,NULL);
        if(start==end)
            return newnode; 
        
        T pos=search(in,rootval,start, end); 
        newnode->left=Build_in_n_pre( in,  pre, start, pos-1); 
        newnode->right=Build_in_n_pre(in, pre, pos+1, end);

        return newnode;

    }

     node<T> *Build_in_n_post(T in[], T post[], int start, int end){
    static int ix = end;
    if(start > end){
        return nullptr;
    }

    T rootval = post[ix--];
    node <T>*newnode = new node<T> (NULL, rootval, NULL);

    int pos = search(in, rootval, start, end); 
    newnode->right = Build_in_n_post(in, post, pos+1, end); 
    newnode->left = Build_in_n_post(in, post, start, pos-1);

    return newnode;
}


     void inorderprint(node<T> *root)
    {
        if (root == NULL)
            return;
        inorderprint(root->left);
        cout << root->data << ' ';
        inorderprint(root->right);
    }
    void preorderprint(node<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ' ';
        preorderprint(root->left);
        preorderprint(root->right);
    }
    void postorderprint(node<T> *root)
    {
        if (root == NULL)
            return;
        postorderprint(root->left);
        postorderprint(root->right);
        cout << root->data << ' ';
    }


};


int main(){

    int pre[5] = {1, 2, 4, 3, 5};
    int in[5] = {4, 2, 1, 5, 3};
    tree <int> t,tr;
    t.root = t.Build_in_n_pre(in, pre,0, 4);
    t.inorderprint(t.root);
    cout << endl;
    t.preorderprint(t.root);
    cout << endl;
    t.postorderprint(t.root);
    cout<<endl;
    int post[5] = {4, 2, 5, 3, 1};
    tr.root = tr.Build_in_n_post(in, post,0, 4);
    tr.inorderprint(tr.root);

    return 0;

}
