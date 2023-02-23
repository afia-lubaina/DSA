# DSA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define dbg(x) cerr << _LINE_ << ": " << #x << " = " << x << endl
 
template <class T>
class node
{
    public:
        T data; 
        node <T> *next; 
 
        node(){
            data=0;
            next=NULL;
        }

        node(T data) : data(data), next(NULL) {}
 
        node(T _data, node<T> *_next){
            data=_data;
            next=_next;
        }
};
 
template <class T>
class linkedlist{
 
public:  
 
    node<T> *head;
    linkedlist(){
        head=NULL;
    }
 
 
    void insert_at_head( T data){ 
        head = new node<T>(data, head); 
    }
 
 
    void insert_after_node(node<T> *x, T data){
        if(x == NULL) return;
        x->next = new node<T>(data, x->next);  
    }
 
 
    void insert_at_tail(T val){
        if(!head)
            insert_at_head(val);
        else {
            node<T> *p=head; 
            while(p->next!=NULL){
                p=p->next;
            }
            insert_after_node(p,val);
        }
    }
 
 
    void del_at_head(){
        if(!head) return;
        node<T> *ptr=head;
        head=ptr->next; 
        delete(ptr);
    }
    
    // head -> (p) n2 -> n3
    void del_tail(){
        if(!head) return;
        node<T> *p=head; 
        if(head->next == NULL) {
            head = NULL;
            delete(p);
            return;
        }
        while(p->next->next!=NULL){
            p=p->next;
        }
        node<T> *q = p -> next;
        p->next= NULL;
        delete(q);
    }

    T first_data()
    {
        return head->data;
    }
 
    T last_data() {
        node<T> *p=head;
        if(head->next == NULL) {
            return head->data;
        } 
        while(p->next != NULL){
            p=p->next;
        }
        return p->data;
    }
 
    void del_after_node(node<T> *n){  // delete after a xth pos
        if(!n) return;
        if(n->next == NULL) return;
        node<T> *tmp = n->next;
        n->next = n->next->next;
        delete(tmp);
    }
 
 
    void sort()
    {
        node<T> *curr = head;
        node<T> *index = NULL;
        T temp;
 
        if (head == NULL)
        {
            return;
        }
 
        for (; curr!=NULL ; curr=curr->next)
        {
            for (index=curr->next; index!=NULL; index=index->next )
            {
                if(curr->data>index->data){
                    temp=curr->data; 
                    curr->data=index->data;
                    index->data= temp;
 
                }
            }
        }
    }
 
    void reverse()
    {
        node<T> *current = head;
        node<T> *prev = NULL, *next = NULL;
 
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
 
 
 
 
 
    void print(){
        if(head){
            node<T> *ptr=head; 
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<"\n";
        }
    }
 
    int count() {
        int c=0; 
    
        if(head==NULL){
            return 0;
        }
    
    
        node<T> *p = head;
        while(p!=NULL){
            c++; 
            p=p->next;
        }
    
        return c;
   }
 
 
    int size(){
        int c=0;
        for(node<T> *cur=head; cur!=NULL; cur=cur->next){
            c++;
        }
        return c;
    }
};
 
template <class T>
class mystack{
 
public: 
    linkedlist<T> a;
 
    int size(){
        return a.size();
    }
 
    void push(T val){
        a.insert_at_head(val);
    }
 
    void pop(){
        if(a.size()==0) return;
            // cout<<"empty list"<<"\n";
        a.del_at_head();
    }
 
    T top(){
        return a.first_data();
    }

    void Print(){
        a.print();
    }
};

float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}

int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;    //character is an operator
   return -1;   //not an operator
}

int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;    //character is an operand
   return -1;   //not an operand
}

float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a);    //find b^a
   else
      return INT_MIN;    //return negative infinity
}

float postfixEval(string postfix) {
   int a, b;
   mystack<float> stk;
   string::iterator it;

   for(it=postfix.begin(); it!=postfix.end(); it++) {
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isOperand(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

main() {
   string post = "53+62/*35*+";
   cout << "The result is: "<<postfixEval(post);
}
