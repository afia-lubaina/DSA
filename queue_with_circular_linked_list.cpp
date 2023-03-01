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

    void insert(T data) {
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

    void pop() {
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
    myq.insert(10);
    myq.insert(20);
    myq.display();
    myq.pop();
    myq.display();
    myq.pop();
    myq.display();
    myq.insert(30);
    myq.insert(40);
    myq.display();
    return 0;
}
