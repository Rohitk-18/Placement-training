#include <iostream>
using namespace std;

//1. Design Queue using Arrays
#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int rearIn;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        rearIn = -1;
    }

    void enqueue(int value) {
        if (rearIn == capacity - 1) {
            cout<<"Queue overflow"<<endl;
            return;
        }
        rearIn++;
        arr[rearIn] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue underflow"<<endl;
            return;
        }

        //left shift kro by one place
        for (int i=0;i<rearIn;i++) {
            arr[i] = arr[i+1];
        }
        rearIn--;
    }

    int front() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() {
        return rearIn == -1;
    }

    int size() {
        return rearIn + 1;
    }

};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout<<"Front: "<<q.front()<<endl; 
    q.dequeue();
    cout<<"Front after dequeue: "<<q.front()<<endl; 
    cout<<q.isEmpty()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    return 0;
}

