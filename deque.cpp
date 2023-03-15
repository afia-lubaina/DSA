#include <iostream>
using namespace std;

template <class T>
class node {
public:
    T data;
    node<T>* next;

    node() : next(nullptr) {}
    node(T data) : data(data), next(nullptr) {}
    node(T data, node<T>* next) : data(data), next(next) {}
};

template<class T>
class myqueue {
public:
    node<T>* head;
    node<T>* tail;

    myqueue() : head(nullptr), tail(nullptr) {}

    void insert_at_rear(T data) {
        node<T>* temp = new node<T>(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insert_at_front(T data) {
        node<T>* temp = new node<T>(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next=head;
            head=temp;
        }
    }

    void pop_at_front() {
        if (head == nullptr)
            return;
        else {
            node<T>* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr)
                tail = nullptr;
        }
    }

    void pop_at_rear(){
    if (tail == nullptr)
        return;
    else if(head == tail){
        node<T>* temp = head;
        head = nullptr; 
        tail = nullptr; 
        delete(temp);
    }
    else {
        node<T>* temp = head;
        while (temp->next != tail) {
            temp = temp->next; 
        }
        tail = temp; 
        node<T>* ptr = temp->next;
        tail->next = nullptr;
        delete(ptr);
    }
}


    void display() {
        node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    myqueue<int> myq;
    myq.insert_at_rear(10);
    myq.insert_at_front(20);
    myq.insert_at_front(30);
    myq.insert_at_rear(40);
    // myq.display();

    myq.pop_at_rear();
    myq.pop_at_front();
     myq.display();
     
    return 0;
}
