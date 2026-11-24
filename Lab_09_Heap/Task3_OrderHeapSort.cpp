// Task 3: Online Shopping Order Sorting (Heap Sort using Max Heap) - pointer based binary tree
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Order {
public:
    int orderId;
    string customer;
    double amount;
    Order *left, *right, *parent;
    Order(int id, string c, double a)
        : orderId(id), customer(c), amount(a), left(NULL), right(NULL), parent(NULL) {}
};

class OrderHeap {
    Order* root;
    int count;

    Order* getNode(int n) {
        int bits = 0;
        for (int t = n; t > 1; t >>= 1) bits++;
        Order* cur = root;
        for (int i = bits - 1; i >= 0; i--)
            cur = ((n >> i) & 1) ? cur->right : cur->left;
        return cur;
    }

    void swapData(Order* a, Order* b) {
        swap(a->orderId, b->orderId);
        swap(a->customer, b->customer);
        swap(a->amount, b->amount);
    }

    void heapifyUp(Order* node) {
        while (node->parent && node->amount > node->parent->amount) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }

    void heapifyDown(Order* node) {
        while (node) {
            Order* largest = node;
            if (node->left && node->left->amount > largest->amount) largest = node->left;
            if (node->right && node->right->amount > largest->amount) largest = node->right;
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }

public:
    OrderHeap() : root(NULL), count(0) {}
    int size() { return count; }

    void insert(int id, string customer, double amount) {
        Order* node = new Order(id, customer, amount);
        count++;
        if (count == 1) {
            root = node;
        } else {
            Order* p = getNode(count / 2);
            node->parent = p;
            if (count % 2 == 0) p->left = node;
            else p->right = node;
            heapifyUp(node);
        }
    }

    // Removes the root (largest amount) and returns its amount
    double deleteRoot() {
        double val = root->amount;
        if (count == 1) {
            delete root;
            root = NULL;
        } else {
            Order* last = getNode(count);
            swapData(root, last);
            if (last->parent->right == last) last->parent->right = NULL;
            else last->parent->left = NULL;
            delete last;
            heapifyDown(root);
        }
        count--;
        return val;
    }

    void levelOrder() {
        if (!root) { cout << "Heap is empty!\n"; return; }
        queue<Order*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            while (sz--) {
                Order* cur = q.front(); q.pop();
                cout << "[Order " << cur->orderId << ", " << cur->customer << ", Rs." << cur->amount << "]  ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << "\n";
        }
    }
};

int main() {
    OrderHeap heap;
    heap.insert(5001, "Ali", 2500);
    heap.insert(5002, "Sara", 12000);
    heap.insert(5003, "Ahmed", 800);
    heap.insert(5004, "Fatima", 6400);
    heap.insert(5005, "Usman", 15500);
    heap.insert(5006, "Ayesha", 3200);
    heap.insert(5007, "Hamza", 9100);

    cout << "=== Max Heap of Orders (Level Order) ===\n";
    heap.levelOrder();

    // Heap Sort: repeated root deletion gives amounts in descending order
    int n = heap.size();
    double* sorted = new double[n];
    int idx = 0;
    while (heap.size() > 0)
        sorted[idx++] = heap.deleteRoot();

    cout << "\nDeleted order amounts (descending, order of removal):\n";
    for (int i = 0; i < n; i++) cout << sorted[i] << " ";

    cout << "\n\n=== Order Amounts in Ascending Order (Smallest to Largest) ===\n";
    for (int i = n - 1; i >= 0; i--) cout << sorted[i] << " ";
    cout << "\n";

    delete[] sorted;
    return 0;
}
