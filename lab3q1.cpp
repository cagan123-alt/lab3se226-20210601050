#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        int count;
        Node* front;
        Node* back;
        

    public:
        Queue() {
            front = back = nullptr;
            count = 0;
        }

        ~Queue() {
            Node* current = front;
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }


        bool isEmpty() {
            return front == nullptr;
        }


        void enqueue(int val) {
            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = nullptr;

            if (back == nullptr) {
                front = back = newNode;
            }
            else {
                back->next = newNode;
                back = newNode;
            }

            count++;
        }


        int dequeue() {
            if (isEmpty()) {
                cout << "There is no elements in queue" << endl;
                return -1;
            }

            int val = front->data;
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                back = nullptr;
            }

            delete temp;
            count--;
            return val;
        }

       int size() {
            return count;
        }

        int top() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }

            return front->data;
        }


         void display() {
            if (isEmpty()) {
                cout << "There is no items in queue " << endl;
                return;
            }

            Node* current = front;
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(200);
    q.enqueue(47);
    q.enqueue(52);
    q.enqueue(320);

    cout << "Your top element is " << q.top() << endl;
    cout << "Your queue size is " << q.size() << endl;

    q.display();

    cout << "Dequeued one is " << q.dequeue() << endl;

    cout << "Top element , " << q.top() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.display(); }