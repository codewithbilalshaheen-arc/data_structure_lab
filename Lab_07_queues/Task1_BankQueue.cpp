#include <iostream>
using namespace std;

const int SIZE = 5;

class BankQueue {
private:
    int tokens[SIZE];
    int front, rear;

public:
    BankQueue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull()  { return rear == SIZE - 1; }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Overflow! Queue is full. Token " << token << " cannot be added.\n";
            return;
        }
        if (front == -1) front = 0;
        tokens[++rear] = token;
        cout << "Customer with token " << token << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow! No customers are waiting.\n";
            return;
        }
        cout << "Serving customer with token " << tokens[front] << "\n";
        front++;
        if (front > rear) front = rear = -1;  // queue became empty, reset
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }
        cout << "Waiting customers (front -> rear): ";
        for (int i = front; i <= rear; i++) cout << tokens[i] << " ";
        cout << "\n";
    }

    int count() { return isEmpty() ? 0 : rear - front + 1; }
};

int main() {
    BankQueue q;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service System ---\n"
             << "1. Add customer (enqueue)\n"
             << "2. Serve customer (dequeue)\n"
             << "3. Display waiting customers\n"
             << "4. Number of waiting customers\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> token;
                q.enqueue(token);
                break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: cout << "Waiting customers: " << q.count() << "\n"; break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}