#include <iostream>
#include <string>
#include <limits>
using namespace std;
class AmbulanceNode {

    public:
    int id;
    string patientName;
    int priority;
    AmbulanceNode* next;

    AmbulanceNode(int i, string name, int p) {
        id = i;
        patientName = name;
        priority = p;
        next = nullptr;
    }
};
class AmbulanceQueue {
private:
    AmbulanceNode* head;

public:
    AmbulanceQueue() { head = nullptr; }

    ~AmbulanceQueue() {
        while (head) {
            AmbulanceNode* t = head;
            head = head->next;
            delete t;
        }
    }

    bool isEmpty() { return head == nullptr; }

    bool idExists(int id) {
        for (AmbulanceNode* c = head; c; c = c->next)
            if (c->id == id) return true;
        return false;
    }
    void insertRequest(int id, string name, int priority) {
        if (priority < 1 || priority > 5) {
            cout << "Invalid priority! Must be between 1 and 5.\n";
            return;
        }
        if (idExists(id)) {
            cout << "Ambulance ID " << id << " already exists!\n";
            return;
        }
        AmbulanceNode* n = new AmbulanceNode(id, name, priority);

        if (head == nullptr || priority < head->priority) {
            n->next = head;
            head = n;
        } else {
            AmbulanceNode* cur = head;
            while (cur->next != nullptr && cur->next->priority <= priority)
                cur = cur->next;
            n->next = cur->next;
            cur->next = n;
        }
        cout << "Request added: ID " << id << ", Patient " << name
            << ", Priority " << priority << "\n";
    }
    void processRequest() {
        if (isEmpty()) {
            cout << "No pending ambulance requests (list is empty).\n";
            return;
        }
        AmbulanceNode* t = head;
        head = head->next;
        cout << "Processing -> ID: " << t->id << ", Patient: " << t->patientName
            << ", Priority: " << t->priority << "\n";
        delete t;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending ambulance requests (list is empty).\n";
            return;
        }
        cout << "\n--- Pending Ambulance Requests ---\n";
        cout << "ID\tPatient\t\tPriority\n";
        for (AmbulanceNode* c = head; c; c = c->next)
            cout << c->id << "\t" << c->patientName << "\t\t" << c->priority << "\n";
        cout << "----------------------------------\n";
    }

    void search(int id) {
        if (isEmpty()) {
            cout << "List is empty. Nothing to search.\n";
            return;
        }
        int pos = 1;
        for (AmbulanceNode* c = head; c; c = c->next, pos++) {
            if (c->id == id) {
                cout << "Found! ID: " << c->id << ", Patient: " << c->patientName
                    << ", Priority: " << c->priority << ", Position in queue: " << pos << "\n";
                return;
            }
        }
        cout << "Ambulance ID " << id << " not found.\n";
    }
};

int main() {
    AmbulanceQueue q;
    int choice;

    do {
        cout << "\n===== Emergency Ambulance Management System =====\n"
            << "1. Add ambulance request\n"
            << "2. Process highest-priority request\n"
            << "3. Display pending requests\n"
            << "4. Search ambulance by ID\n"
            << "5. Exit\n"
            << "Enter choice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
        case 1: {
            int id, p;
            string name;
            cout << "Ambulance ID: ";   cin >> id;
            cout << "Patient Name: ";   cin >> name;
            cout << "Priority (1-5): "; cin >> p;
            q.insertRequest(id, name, p);
            break;
        }
        case 2: q.processRequest(); break;
        case 3: q.display(); break;
        case 4: {
            int id;
            cout << "Enter Ambulance ID to search: ";
            cin >> id;
            q.search(id);
            break;
        }
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}