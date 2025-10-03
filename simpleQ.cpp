#include <iostream>
using namespace std;

#define SIZE 100  // Maximum size of the queue

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Add element to the queue
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full (overflow)\n";
            return;
        }

        if (front == -1) front = 0;  // first element

        rear++;
        arr[rear] = value;
        cout << value << " enqueued to queue\n";
    }

    // Remove element from the queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty (underflow)\n";
            return;
        }

        cout << arr[front] << " dequeued from queue\n";
        front++;
    }

    // Show the element at front
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    // Display all elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.peek();

    return 0;
}
