// Task 2: Hospital Emergency Management System (Max Heap) - pointer based binary tree
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int id;
    int priority;   // higher number = more critical
    Patient *left, *right, *parent;
    Patient(string n, int i, int p)
        : name(n), id(i), priority(p), left(NULL), right(NULL), parent(NULL) {}
};

class EmergencyHeap {
    Patient* root;
    int count;

    Patient* getNode(int n) {
        int bits = 0;
        for (int t = n; t > 1; t >>= 1) bits++;
        Patient* cur = root;
        for (int i = bits - 1; i >= 0; i--)
            cur = ((n >> i) & 1) ? cur->right : cur->left;
        return cur;
    }

    void swapData(Patient* a, Patient* b) {
        swap(a->name, b->name);
        swap(a->id, b->id);
        swap(a->priority, b->priority);
    }

    void heapifyUp(Patient* node) {
        while (node->parent && node->priority > node->parent->priority) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }

    void heapifyDown(Patient* node) {
        while (node) {
            Patient* largest = node;
            if (node->left && node->left->priority > largest->priority) largest = node->left;
            if (node->right && node->right->priority > largest->priority) largest = node->right;
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }

public:
    EmergencyHeap() : root(NULL), count(0) {}

    void insert(string name, int id, int priority) {
        Patient* node = new Patient(name, id, priority);
        count++;
        if (count == 1) {
            root = node;
        } else {
            Patient* p = getNode(count / 2);
            node->parent = p;
            if (count % 2 == 0) p->left = node;
            else p->right = node;
            heapifyUp(node);
        }
    }

    void showHighestPriority() {
        if (!root) { cout << "No patients waiting.\n"; return; }
        cout << "Highest priority patient: " << root->name << " (ID " << root->id
             << ", Priority " << root->priority << ")\n";
    }

    void treatPatient() {
        if (!root) { cout << "No patients to treat.\n"; return; }
        cout << "\nTreating and removing patient: " << root->name << " (ID " << root->id
             << ", Priority " << root->priority << ")\n";
        if (count == 1) {
            delete root;
            root = NULL;
        } else {
            Patient* last = getNode(count);
            swapData(root, last);
            if (last->parent->right == last) last->parent->right = NULL;
            else last->parent->left = NULL;
            delete last;
            heapifyDown(root);
        }
        count--;
    }

    void levelOrder() {
        if (!root) { cout << "No patients waiting.\n"; return; }
        queue<Patient*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            while (sz--) {
                Patient* cur = q.front(); q.pop();
                cout << "[" << cur->name << ", ID " << cur->id << ", Priority " << cur->priority << "]  ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << "\n";
        }
    }
};

int main() {
    EmergencyHeap heap;
    heap.insert("Bilal", 1, 4);
    heap.insert("Zainab", 2, 9);
    heap.insert("Imran", 3, 6);
    heap.insert("Hina", 4, 10);
    heap.insert("Kamran", 5, 3);
    heap.insert("Noor", 6, 8);
    heap.insert("Tariq", 7, 5);

    cout << "=== All Patients (Level Order Traversal) ===\n";
    heap.levelOrder();

    cout << "\n";
    heap.showHighestPriority();

    heap.treatPatient();

    cout << "\n=== Heap after Heapify Down (Level Order) ===\n";
    heap.levelOrder();

    cout << "\nNext patient who needs treatment:\n";
    heap.showHighestPriority();
    return 0;
}
