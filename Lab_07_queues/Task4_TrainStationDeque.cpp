#include <iostream>
using namespace std;

const int SIZE = 6;

// Circular array-based deque
class Deque {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    Deque() : front(0), rear(SIZE - 1), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque is FULL! Cannot insert " << id << " at front.\n";
            return;
        }
        front = (front - 1 + SIZE) % SIZE;
        arr[front] = id;
        count++;
        cout << "Request " << id << " inserted at front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque is FULL! Cannot insert " << id << " at rear.\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = id;
        count++;
        cout << "Request " << id << " inserted at rear.\n";
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Deque is EMPTY! Nothing to remove from front.\n";
            return;
        }
        cout << "Removed request " << arr[front] << " from front.\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Deque is EMPTY! Nothing to remove from rear.\n";
            return;
        }
        cout << "Removed request " << arr[rear] << " from rear.\n";
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No passenger requests.\n";
            return;
        }
        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE];
            if (i < count - 1) cout << ", ";
        }
        cout << " <- Rear\n";
    }
};

int main() {
    Deque d;
    int choice, id;

    do {
        cout << "\n--- Train Station Passenger Management (Deque) ---\n"
             << "1. Insert at front\n"
             << "2. Insert at rear\n"
             << "3. Remove from front\n"
             << "4. Remove from rear\n"
             << "5. Display (front to rear)\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter request ID: ";
                cin >> id;
                d.insertFront(id);
                break;
            case 2:
                cout << "Enter request ID: ";
                cin >> id;
                d.insertRear(id);
                break;
            case 3: d.removeFront(); break;
            case 4: d.removeRear(); break;
            case 5: d.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}