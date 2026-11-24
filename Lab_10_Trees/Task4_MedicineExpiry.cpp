// Task 4: Hospital Medicine Expiry Management (Min Heap) - pointer based binary tree
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Medicine {
public:
    string name;
    int id;
    int expiry;   // YYYYMMDD
    Medicine *left, *right, *parent;
    Medicine(string n, int i, int e)
        : name(n), id(i), expiry(e), left(NULL), right(NULL), parent(NULL) {}
};

class MinHeap {
    Medicine* root;
    int count;

    Medicine* getNode(int n) {
        int bits = 0;
        for (int t = n; t > 1; t >>= 1) bits++;
        Medicine* cur = root;
        for (int i = bits - 1; i >= 0; i--)
            cur = ((n >> i) & 1) ? cur->right : cur->left;
        return cur;
    }

    void swapData(Medicine* a, Medicine* b) {
        swap(a->name, b->name);
        swap(a->id, b->id);
        swap(a->expiry, b->expiry);
    }

    void heapifyUp(Medicine* node) {
        while (node->parent && node->expiry < node->parent->expiry) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }

    void heapifyDown(Medicine* node) {
        while (node) {
            Medicine* smallest = node;
            if (node->left && node->left->expiry < smallest->expiry) smallest = node->left;
            if (node->right && node->right->expiry < smallest->expiry) smallest = node->right;
            if (smallest == node) break;
            swapData(node, smallest);
            node = smallest;
        }
    }

public:
    MinHeap() : root(NULL), count(0) {}

    void insert(string name, int id, int expiry) {
        Medicine* node = new Medicine(name, id, expiry);
        count++;
        if (count == 1) {
            root = node;
        } else {
            Medicine* p = getNode(count / 2);
            node->parent = p;
            if (count % 2 == 0) p->left = node;
            else p->right = node;
            heapifyUp(node);
        }
        cout << "Inserted: " << name << " (ID " << id << ", Expiry " << expiry << ")\n";
    }

    void showNearestExpiry() {
        if (!root) { cout << "No medicines in store.\n"; return; }
        cout << "Nearest expiry: " << root->name << " (ID " << root->id
             << ", Expiry " << root->expiry << ")\n";
    }

    void deleteNearestExpiry() {
        if (!root) { cout << "No medicines in store.\n"; return; }
        cout << "\nDeleting medicine with nearest expiry: " << root->name
             << " (ID " << root->id << ", Expiry " << root->expiry << ")\n";
        if (count == 1) {
            delete root;
            root = NULL;
        } else {
            Medicine* last = getNode(count);
            swapData(root, last);
            if (last->parent->right == last) last->parent->right = NULL;
            else last->parent->left = NULL;
            delete last;
            heapifyDown(root);
        }
        count--;
    }

    void levelOrder() {
        if (!root) { cout << "Heap is empty!\n"; return; }
        queue<Medicine*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            while (sz--) {
                Medicine* cur = q.front(); q.pop();
                cout << "[" << cur->name << ", ID " << cur->id << ", " << cur->expiry << "]  ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << "\n";
        }
    }
};

int main() {
    MinHeap heap;
    cout << "=== Inserting Medicines (Heapify Up after each insertion) ===\n";
    heap.insert("Paracetamol", 201, 20271215);
    heap.insert("Amoxicillin", 202, 20270310);
    heap.insert("Ibuprofen", 203, 20281120);
    heap.insert("Cough Syrup", 204, 20261230);
    heap.insert("Insulin", 205, 20270605);
    heap.insert("Aspirin", 206, 20270820);
    heap.insert("Vitamin C", 207, 20260915);

    cout << "\n=== Min Heap (Level Order Traversal) ===\n";
    heap.levelOrder();

    cout << "\n";
    heap.showNearestExpiry();
    heap.deleteNearestExpiry();

    cout << "\n=== Updated Heap after Heapify Down (Level Order) ===\n";
    heap.levelOrder();
    return 0;
}
