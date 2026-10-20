#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Patient {
    string id;
    int priority;   // 1 = highest urgency
    int arrival;    // tie-breaker: earlier arrival is treated first
};

class EmergencyQueue {
private:
    Patient patients[SIZE];
    int count;
    int arrivalCounter;

    // Returns true if a should be treated before b:
    // lower priority number wins; if equal, earlier arrival wins.
    bool comesBefore(const Patient& a, const Patient& b) {
        if (a.priority != b.priority) return a.priority < b.priority;
        return a.arrival < b.arrival;
    }

public:
    EmergencyQueue() : count(0), arrivalCounter(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insertPatient(const string& id, int priority) {
        if (isFull()) {
            cout << "Queue is full! Cannot add patient " << id << ".\n";
            return;
        }
        Patient p = {id, priority, arrivalCounter++};

        // Insert in sorted position (highest urgency at index 0)
        int i = count - 1;
        while (i >= 0 && comesBefore(p, patients[i])) {
            patients[i + 1] = patients[i];
            i--;
        }
        patients[i + 1] = p;
        count++;
        cout << "Patient " << id << " added with priority " << priority << ".\n";
    }

    void treatPatient() {
        if (isEmpty()) {
            cout << "No patients waiting. Queue is empty.\n";
            return;
        }
        cout << "Treating patient " << patients[0].id
             << " (priority " << patients[0].priority << ")\n";
        for (int i = 1; i < count; i++) patients[i - 1] = patients[i];
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Waiting patients (next to treat first):\n";
        for (int i = 0; i < count; i++)
            cout << "  " << patients[i].id << "  - Priority " << patients[i].priority << "\n";
    }
};

int main() {
    EmergencyQueue q;
    int choice, priority;
    string id;

    cout << "Priority 1 = highest urgency.\n";

    do {
        cout << "\n--- Hospital Emergency Department ---\n"
             << "1. Add patient\n"
             << "2. Treat next patient\n"
             << "3. Display waiting patients\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID (e.g. P101): ";
                cin >> id;
                cout << "Enter priority (1 = highest): ";
                cin >> priority;
                q.insertPatient(id, priority);
                break;
            case 2: q.treatPatient(); break;
            case 3: q.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}