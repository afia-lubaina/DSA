#include<bits/stdc++.h>
using namespace std;

template<class T> class DNode{
    public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;
    DNode(){
        next=NULL;
        prev=NULL;
    }
};

template<class T> class Deque{
    DNode<T>* front,*rear,*newNode;
    int Size;
    public:
    Deque(){
        front=rear=NULL;
        Size=0;
    }
    bool isEmpty(){ 
        return (front == NULL); 
    }
    int size(){
         return Size; 
    }
    void insertFront(T data){
        newNode = new DNode<T>;
        newNode->data=data;

        if (newNode == NULL)
            cout << "OverFlow\n";
        else {
            if (front == NULL)
                rear = front = newNode;
    
            else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            Size++;
        }
    }
    void insertRear(T data){
        newNode = new DNode<T>();
        newNode->data=data;
        if (newNode == NULL)
            cout << "OverFlow\n";
        else {
            if (rear == NULL)
                front = rear = newNode;
    
            else {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
    
            Size++;
        }
    }
    void deleteFront(){
        if (isEmpty())
            cout << "UnderFlow\n";
    
        else {
            DNode<T>* temp = front;
            front = front->next;

            if (front == NULL)
                rear = NULL;
            else
                front->prev = NULL;
            delete(temp);
            Size--;
        }
    }
    void deleteRear(){
        if (isEmpty())
            cout << "UnderFlow\n";
    
        else {
            DNode<T>* temp = rear;
            rear = rear->prev;
    
            if (rear == NULL)
                front = NULL;
            else
                rear->next = NULL;
            delete(temp);
            Size--;
        }
    }
    T getFront(){
        return front->data;
    }

    T getRear(){
        return rear->data;
    }
    
    void erase()
    {
        rear = NULL;
        while (front != NULL) {
            DNode<T>* temp = front;
            front = front->next;
            delete(temp);
        }
        Size = 0;
    }

    void print(){
        DNode<T>* tempo=front;
        while(tempo->next!=NULL){
            cout<<tempo->data<<' ';
            tempo=tempo->next;
        }
        cout<<tempo->data<<endl;
        rear=tempo;
        while(tempo!=NULL){
            cout<<tempo->data<<' ';
            tempo=tempo->prev;
        }
        cout<<endl;
    }
};

int main(){
    Deque<char> d;
    d.insertFront('s');
    d.insertRear('q');
    d.print();
    d.getFront();


    return 0;
}
