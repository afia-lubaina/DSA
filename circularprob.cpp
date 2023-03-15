#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;

    node(){
        data = 0;
        next = NULL;
    }

    node(T data, node<T> *next = NULL){
        this->data = data;
        this->next = next;
    }
};

template <class T>
class linkedlist{
public:
    node<T> *head;
    node<T> *tail;

    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void insert_at_head(T data){
        head = new node<T>(data, head);
        if (!tail)
            tail = head;
        tail->next = head;
    }

    void insert_after_node(node<T> *x, T data){
        if(x == NULL) return;
        node<T> *temp = new node<T>(data, x->next);
        x->next = temp;
        if (tail == x)
            tail = temp;
		tail=temp;
    }

    void insert_at_tail(T val){
        if(!head)
            insert_at_head(val);
        else {
            insert_after_node(tail, val);
        }
    }

    void del_at_head(){
        if(!head) return;
        node<T> *ptr=head;
        head=ptr->next;
        delete(ptr);
        if(!head)
            tail=NULL;
        else
            tail->next = head;
    }

    void del_tail(){
        if(!head) return;
        node<T> *p=head;
        if(p->next == head) {
            head = NULL;
            tail = NULL;
            delete(p);
            return;
        }
        while(p->next->next!=head){
            p=p->next;
        }
        node<T> *q = p->next;
        p->next= head;
        tail = p;
        delete(q);
    }

    T first_data()
    {
        if (!head)
            return 0;
        return head->data;
    }

    T last_data() {
        if (!head)
            return 0;
        node<T> *p=head;
        if(p->next == head) {
            return head->data;
        }
        while(p->next != head){
            p=p->next;
        }
        return p->data;
    }

	void del_after_node(node<T> *n){  
        if(!n) return;
        if(n->next == head) return;
        node<T> *tmp = n->next;
        n->next = n->next->next;
        delete(tmp);
    }

		void sort() {
			node<T> *curr = head;
			node<T> *index = NULL;
			T temp;
		
			if (head == NULL) {
				return;
			}
		
			do {
				index = curr->next;
				while (index != head) {
					if (curr->data > index->data) {
						temp = curr->data; 
						curr->data = index->data;
						index->data = temp;
					}
					index = index->next;
				}
				curr = curr->next;
			} while (curr != head);

			node<T> *t = head;
			while (t->next != head && t->data <= t->next->data) {
				t = t->next;
			}

			if (t->next != head) {
				node<T> *p = t->next;
				while (p->next != head) {
					p = p->next;
				}
				p->next = t->next;
				t->next = p->next->next;
				p->next->next = head;
				head = p->next;
			}
		}

	

    void reverse_list() {
			if(!head) return; // empty list
			node<T> *prev = NULL, *curr = head, *next;
			do {
				next = curr->next; // store the next node
				curr->next = prev; // reverse the link
				prev = curr; // move prev to curr
				curr = next; // move curr to next
			} while(curr != head); // loop until we complete one full round
			tail = head; // update the tail to point to the last node in the reversed list
			head = prev; // set the new head to the last node
    }

    void print(){
        if(head){
            node<T> *ptr = head;
            do {
                cout << ptr->data << " ";
                ptr = ptr->next;
            } while (ptr != head);
            cout << "\n";
        }
    }

    void merge(node <T> *h1, node <T> *h2){

    node<T> *p1=h2; 
    node<T> *p2=h1; 
    node<T> *max_pos;
    node<T> *min_pos;

     //cout<<h1->data<<" "<<h2->data<<" ";
     
     T mx=INT_MIN; 
     T mn=INT_MAX;

     do{

        mx=max(mx,p1->data);

       // cout<<p1->data<<" ";
       
        if(p1->data==mx)
             max_pos=p1;
        
        p1=p1->next;
        
     }while(p1!=h2);
  
    //   cout<<max_pos->data<<"\n";
    do{

         mn=min(mn,p2->data);

        if(p2->data==mn)
            min_pos=p2;
        p2=p2->next;
     } while(p2!=h1);

    // cout<<min_pos->data<<"\n";

     node<T> *max_next=max_pos->next;
    // cout<<max_next->data<<"\n";
    node<T> *min_prev;
    node<T> *p3=h1;

    do{
        p3= p3->next;
    }while(p3->next!=min_pos);

    min_prev=p3;

    cout<<min_pos->data<<"\n"; 
     cout<<min_prev->data<<"\n"; 
      cout<<max_pos->data<<"\n"; 
       cout<<max_next->data<<"\n"; 

    max_pos->next=min_pos; 
    min_prev->next=max_next;




    }


    
};





int main(){
    linkedlist<int> a; 
    linkedlist<int>b; 


    a.insert_at_tail(6); 
    a.insert_at_tail(5);
    a.insert_at_tail(4);
    a.insert_at_tail(3);
    a.insert_at_tail(2);
    a.insert_at_tail(8);

    b.insert_at_tail(7); 
    b.insert_at_tail(10);
    b.insert_at_tail(9); 
    b.insert_at_tail(11); 
    b.insert_at_tail(12);

    a.merge(a.head, b.head);
    a.print();


    return 0;
}
