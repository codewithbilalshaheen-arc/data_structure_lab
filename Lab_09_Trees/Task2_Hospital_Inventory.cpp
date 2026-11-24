#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int id; Node *left{}, *right{};
    Node(int v) : id(v) {}
};

class BST {
    Node* root{};

    Node* insert(Node* n, int id, bool& add) {
        if (!n) return add = true, new Node(id);
        if (id < n->id) n->left = insert(n->left, id, add);
        else if (id > n->id) n->right = insert(n->right, id, add);
        return n;
    }

    Node* remove(Node* n, int id, bool& rem) {
        if (!n) return nullptr;
        if (id < n->id) n->left = remove(n->left, id, rem);
        else if (id > n->id) n->right = remove(n->right, id, rem);
        else {
            rem = true;
            if (!n->left || !n->right) {
                Node* t = n->left ? n->left : n->right;
                delete n; return t;
            }
            Node* s = n->right;
            while (s->left) s = s->left;
            n->id = s->id;
            bool dummy; n->right = remove(n->right, s->id, dummy);
        }
        return n;
    }

    void inOrder(Node* n) { if (n) { inOrder(n->left); cout << n->id << " "; inOrder(n->right); } }
    void preOrder(Node* n) { if (n) { cout << n->id << " "; preOrder(n->left); preOrder(n->right); } }
    void postOrder(Node* n) { if (n) { postOrder(n->left); postOrder(n->right); cout << n->id << " "; } }
    int count(Node* n) { return n ? 1 + count(n->left) + count(n->right) : 0; }
    int height(Node* n) { return n ? 1 + max(height(n->left), height(n->right)) : 0; }
    void destroy(Node* n) { if (n) { destroy(n->left); destroy(n->right); delete n; } }

public:
    ~BST() { destroy(root); }
    bool insert(int id) { bool a = false; root = insert(root, id, a); return a; }
    bool remove(int id) { bool r = false; root = remove(root, id, r); return r; }
    bool isEmpty() { return !root; }
    int count() { return count(root); }
    int height() { return height(root); }
    void inOrder() { inOrder(root); cout << "\n"; }
    void preOrder() { preOrder(root); cout << "\n"; }
    void postOrder() { postOrder(root); cout << "\n"; }

    bool search(int id) {
        for (auto c = root; c; c = (id < c->id) ? c->left : c->right)
            if (id == c->id) return true;
        return false;
    }
};

void predictionTest() {
    BST tree;
    for (int id : {55, 35, 75, 25, 45, 65, 85, 40, 50}) tree.insert(id);

    cout << "--- Prediction Test ---\nOperations: insert 60, 30, 90 then delete 55, 25, 40\n"
         << "Predicted in-order: 30 35 45 50 60 65 75 85 90\nPredicted height: 4\n";

    for (int id : {60, 30, 90}) tree.insert(id);
    for (int id : {55, 25, 40}) tree.remove(id);

    cout << "Actual in-order: "; tree.inOrder();
    cout << "Actual height: " << tree.height() << "\nDeleting 65 twice:\n"
         << "First time: " << (tree.remove(65) ? "deleted" : "not found") << "\n"
         << "Second time: " << (tree.remove(65) ? "deleted" : "not found, tree unchanged") << "\n"
         << "Two-child deletion: the node is replaced by the smallest value of its right subtree.\n"
         << "That value is larger than everything on the left and smaller than the rest on the right,\n"
         << "so the BST property is preserved.\n\n";
}

int main() {
    predictionTest();
    BST tree;
    for (int id : {55, 35, 75, 25, 45, 65, 85, 40, 50}) tree.insert(id);

    int choice = 0, id;
    while (choice != 9) {
        cout << "\n1. Insert an ID\n2. Search for an ID\n3. Delete an ID\n"
             << "4. Display in-order\n5. Display pre-order\n6. Display post-order\n"
             << "7. Count nodes\n8. Height of BST\n9. Exit\nEnter choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number from 1 to 9.\n";
            choice = 0; continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cout << id << (tree.insert(id) ? " inserted.\n" : " already exists. Duplicate rejected.\n");
                break;
            case 2:
                if (tree.isEmpty()) cout << "Tree is empty.\n";
                else { cout << "Enter ID: "; cin >> id; cout << id << (tree.search(id) ? " found.\n" : " not found.\n"); }
                break;
            case 3:
                if (tree.isEmpty()) cout << "Tree is empty.\n";
                else {
                    cout << "Enter ID: "; cin >> id;
                    if (tree.remove(id)) { cout << id << " deleted. Updated IDs: "; tree.inOrder(); }
                    else cout << id << " does not exist.\n";
                }
                break;
            case 4: cout << "In-order: "; tree.inOrder(); break;
            case 5: cout << "Pre-order: "; tree.preOrder(); break;
            case 6: cout << "Post-order: "; tree.postOrder(); break;
            case 7: cout << "Total nodes: " << tree.count() << "\n"; break;
            case 8: cout << "Height: " << tree.height() << "\n"; break;
            case 9: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice. Enter a number from 1 to 9.\n";
        }
    }
}