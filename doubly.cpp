#include<bits/stdc++.h>
using namespace std; 

template< class T> 

class node{
    public: 

    T data; 
    node <T> *next;
    node <T> *prev;

    node(){
        data=T();  // initialize data to default value
        prev=NULL;
        next=NULL;
    } 

    node(T data): data(data),prev(nullptr),next(nullptr){}
    node(node<T> *prev,T data, node<T> *next){
        this->data=data; 
        this->next=next;
        this->prev=prev;
    }
}; 

template <class T>
class linkedlist{

public:
    node <T> *head;
    linkedlist(){
        head=NULL;
    }

    void insert_at_head(T val){
        head=new node<T>(nullptr,val,head);
        if (head->next != nullptr) { // update the prev pointer of the new head
            head->next->prev = head;
        }
    }

    void insert_at_tail(T val){
        if(head==NULL){
            insert_at_head(val);
        }
        else{
            node<T> *ptr=new node<T>(nullptr,val,NULL);
            node <T> *t=head; 
            while(t->next!=NULL){
                t=t->next;
            }
            ptr->prev=t;
            ptr->next=NULL;
            t->next=ptr;
        }
    }

    void delete_at_head(){
        if(head==NULL) {
            return ; 
        }
        node<T> *ptr=head; 
        head=head->next; 
        if (head != nullptr) { // update the prev pointer of the new head
            head->prev = nullptr;
        }
        delete(ptr);
    }

    void delete_at_tail(){
        if(!head) {
            return;
        }
        node<T> *p=head; 
        if(head->next == NULL) {
            head = NULL;
            delete(p);
            return;
        }
        while(p->next!=NULL){
            p=p->next;
        }
        node<T> *q = p->prev;
        q->next = NULL; // update the next pointer of the new tail
        delete(p);
    }

    void sort(){
        node <T> *p=head; 
        node <T> *ix=NULL;
        for ( ; p!=NULL;p=p->next){
            for (ix=p->next ; ix!=NULL;ix=ix->next){
                if(ix->data<p->data){
                    T temp=ix->data; 
                    ix->data= p->data;
                    p->data=temp; 
                }
            }
        }
    }

    void reverse(){
        node <T>*prev=NULL; 
        node<T> *next=NULL; 
        node<T>*curr=head; 
        while(curr!=NULL){
            next=curr->next; 
            curr->next=prev; 
            curr->prev=next; // update the prev pointer to the next node
            prev=curr;
            curr=next; 
        }
        head=prev;
    }
    
    void backwardDisplay() {
        node<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != nullptr) { // traverse in reverse order
            cout << temp->data << ' ';
            temp = temp->prev;
        }
        cout << "\n";
    }

  

    void print(){

        node <T> *t=head;
        while(t!=NULL){ // Traverse the entire linked list
            cout<<t->data<<" ";
            t=t->next;

        }

        cout<<"\n"; // Print a newline character after the last node
    }

    

    
};

int main(){

    linkedlist <int> a ; 
    a.insert_at_head(8); 
    a.insert_at_tail(7);
    a.insert_at_tail(80); 
    a.insert_at_head(23); 

   // a.delete_at_tail();
  //  a.sort();
  //  a.reverse();
    a.print();
    a.backwardDisplay();


}
