#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, capacity;
public:
    Queue(int size = 10) {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        cout << "Enqueued " << x << endl;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        cout << "Dequeued " << temp << endl;
        return temp;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}
