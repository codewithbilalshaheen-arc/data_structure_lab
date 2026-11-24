// Task 1: University Student Merit Ranking (Max Heap) - pointer based binary tree
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;
    Student *left, *right, *parent;
    Student(string n, int r, float m)
        : name(n), rollNo(r), marks(m), left(NULL), right(NULL), parent(NULL) {}
};

class MaxHeap {
    Student* root;
    int count;

    // Locate the n-th node (1-indexed, level order) using the binary path of n
    Student* getNode(int n) {
        int bits = 0;
        for (int t = n; t > 1; t >>= 1) bits++;
        Student* cur = root;
        for (int i = bits - 1; i >= 0; i--)
            cur = ((n >> i) & 1) ? cur->right : cur->left;
        return cur;
    }

    void swapData(Student* a, Student* b) {
        swap(a->name, b->name);
        swap(a->rollNo, b->rollNo);
        swap(a->marks, b->marks);
    }

    void heapifyUp(Student* node) {
        while (node->parent && node->marks > node->parent->marks) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }

    void heapifyDown(Student* node) {
        while (node) {
            Student* largest = node;
            if (node->left && node->left->marks > largest->marks) largest = node->left;
            if (node->right && node->right->marks > largest->marks) largest = node->right;
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }

public:
    MaxHeap() : root(NULL), count(0) {}

    void insert(string name, int roll, float marks) {
        Student* node = new Student(name, roll, marks);
        count++;
        if (count == 1) {
            root = node;
        } else {
            Student* p = getNode(count / 2);
            node->parent = p;
            if (count % 2 == 0) p->left = node;
            else p->right = node;
            heapifyUp(node);
        }
        cout << "Inserted: " << name << " (Roll " << roll << ", Marks " << marks << ")\n";
    }

    bool deleteMax() {
        if (!root) { cout << "Heap is empty!\n"; return false; }
        cout << "\nDeleting student with highest marks: " << root->name
             << " (Roll " << root->rollNo << ", Marks " << root->marks << ")\n";
        if (count == 1) {
            delete root;
            root = NULL;
        } else {
            Student* last = getNode(count);
            swapData(root, last);
            if (last->parent->right == last) last->parent->right = NULL;
            else last->parent->left = NULL;
            delete last;
            heapifyDown(root);
        }
        count--;
        return true;
    }

    void levelOrder() {
        if (!root) { cout << "Heap is empty!\n"; return; }
        queue<Student*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            while (sz--) {
                Student* cur = q.front(); q.pop();
                cout << "[" << cur->name << ", Roll " << cur->rollNo << ", " << cur->marks << "]  ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << "\n";
        }
    }
};

int main() {
    MaxHeap heap;
    cout << "=== Inserting Students (Heapify Up after each insertion) ===\n";
    heap.insert("Ali", 101, 78.5);
    heap.insert("Sara", 102, 92.0);
    heap.insert("Ahmed", 103, 85.0);
    heap.insert("Fatima", 104, 67.5);
    heap.insert("Usman", 105, 95.5);
    heap.insert("Ayesha", 106, 88.0);
    heap.insert("Hamza", 107, 73.0);

    cout << "\n=== Merit Heap (Level Order Traversal) ===\n";
    heap.levelOrder();

    heap.deleteMax();
    cout << "\n=== Updated Heap after Heapify Down (Level Order) ===\n";
    heap.levelOrder();
    return 0;
}
