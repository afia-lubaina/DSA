#include<bits/stdc++.h>
using namespace std;

#define MAX 100
 
template <class T> class Deque {
    T arr[MAX];
    int front;
    int rear;
    int size;
    public:
    Deque(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
    }
    bool isFull(){
        return ((front == 0 && rear == size - 1)
            || front == rear + 1);
    }   
    bool isEmpty() { 
        return (front == -1); 
    }

    void insertfront(T key){
        if (isFull()) {
            cout << "Overflow\n" << endl;
            return;
        }
    
        if (front == -1) {
            front = 0;
            rear = 0;
        }
    
        else if (front == 0)
            front = size - 1;
    
        else
            front = front - 1;
    
        arr[front] = key;
    }

    void insertrear(T key){
        if (isFull()) {
            cout << " Overflow\n " << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
            rear = 0;

        else
            rear = rear + 1;
    
        arr[rear] = key;
    }

    void deletefront(){
        if (isEmpty()) {
            cout << "Queue Underflow\n" << endl;
            return;
        }
    
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
    
        else
            front = front + 1;
    }
    void deleterear(){
        if (isEmpty()) {
            cout << " Underflow\n" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }
    T getFront(){
        if (isEmpty()) {
            cout << " Underflow\n" << endl;
            return -1;
        }
        return arr[front];
    }
    T getRear()
    {
        if (isEmpty() || rear < 0) {
            cout << " Underflow\n" << endl;
            return -1;
        }
        return arr[rear];
    }
    void display(){
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<endl;
            i=(i+1)%size;
        }
        cout<<arr[i]<<endl;
    }

};

int main(){
    Deque<char> d(6);
    d.insertfront('c');
    d.insertrear('s');
    d.display();
    
    return 0;
}
