#include <iostream>
using namespace std;

const int SIZE = 5;

class PacketQueue {
private:
    int packets[SIZE];
    int front, rear, count;

public:
    PacketQueue() : front(0), rear(-1), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insertPacket(int id) {
        if (isFull()) {
            cout << "Queue is FULL! Packet " << id << " dropped.\n";
            return;
        }
        rear = (rear + 1) % SIZE;   // circular movement
        packets[rear] = id;
        count++;
        cout << "Packet " << id << " stored at index " << rear << ".\n";
    }

    void transmitPacket() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No packet to transmit.\n";
            return;
        }
        cout << "Transmitting packet " << packets[front]
             << " (freed index " << front << ").\n";
        front = (front + 1) % SIZE; // freed slot can be reused later
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets waiting.\n";
            return;
        }
        cout << "Packets waiting (oldest first): ";
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % SIZE;
            cout << packets[idx] << "[" << idx << "] ";
        }
        cout << "\n";
    }
};

int main() {
    PacketQueue q;
    int choice, id;

    do {
        cout << "\n--- Network Packet Management (Circular Queue) ---\n"
             << "1. Insert packet\n"
             << "2. Transmit oldest packet\n"
             << "3. Display waiting packets\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> id;
                q.insertPacket(id);
                break;
            case 2: q.transmitPacket(); break;
            case 3: q.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}