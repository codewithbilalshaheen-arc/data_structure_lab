#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ---------------- Node ----------------
class Node {
public:
    int flightNo;
    string destination;
    string departureTime;
    Node* left;
    Node* right;

    Node(int f, string d, string t) {
        flightNo = f;
        destination = d;
        departureTime = t;
        left = right = nullptr;
    }
};

// ---------------- BST ----------------
class FlightBST {
private:
    Node* root;

    Node* insert(Node* node, int f, string d, string t) {
        if (node == nullptr) return new Node(f, d, t);
        if (f < node->flightNo)      node->left  = insert(node->left, f, d, t);
        else if (f > node->flightNo) node->right = insert(node->right, f, d, t);
        else cout << "Flight " << f << " already exists. Duplicate ignored.\n";
        return node;
    }

    Node* search(Node* node, int f) {
        if (node == nullptr || node->flightNo == f) return node;
        if (f < node->flightNo) return search(node->left, f);
        return search(node->right, f);
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    Node* deleteNode(Node* node, int f, bool verbose = true) {
        if (node == nullptr) {
            if (verbose) cout << "Flight " << f << " not found. Nothing deleted.\n";
            return nullptr;
        }
        if (f < node->flightNo)      node->left  = deleteNode(node->left, f, verbose);
        else if (f > node->flightNo) node->right = deleteNode(node->right, f, verbose);
        else {
            // Case 1: leaf node
            if (node->left == nullptr && node->right == nullptr) {
                if (verbose) cout << "Deleting flight " << f << " (Case 1: leaf node)\n";
                delete node;
                return nullptr;
            }
            // Case 2: one child
            if (node->left == nullptr) {
                if (verbose) cout << "Deleting flight " << f << " (Case 2: one child - right)\n";
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                if (verbose) cout << "Deleting flight " << f << " (Case 2: one child - left)\n";
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: two children -> replace with in-order successor
            if (verbose) cout << "Deleting flight " << f << " (Case 3: two children, replaced by in-order successor)\n";
            Node* succ = findMin(node->right);
            node->flightNo = succ->flightNo;
            node->destination = succ->destination;
            node->departureTime = succ->departureTime;
            node->right = deleteNode(node->right, succ->flightNo, false);
        }
        return node;
    }

    void print(Node* n) {
        cout << "Flight " << n->flightNo << " | " << n->destination
             << " | " << n->departureTime << "\n";
    }

    void inorder(Node* n)   { if (!n) return; inorder(n->left);   print(n); inorder(n->right); }
    void preorder(Node* n)  { if (!n) return; print(n); preorder(n->left); preorder(n->right); }
    void postorder(Node* n) { if (!n) return; postorder(n->left); postorder(n->right); print(n); }

    int count(Node* n) { return n ? 1 + count(n->left) + count(n->right) : 0; }

    // height in nodes (empty = 0, single node = 1)
    int height(Node* n) { return n ? 1 + max(height(n->left), height(n->right)) : 0; }

    // Sideways tree view (root at left, right subtree on top)
    void printTree(Node* n, int space) {
        if (!n) return;
        space += 8;
        printTree(n->right, space);
        cout << "\n";
        for (int i = 8; i < space; i++) cout << " ";
        cout << n->flightNo << " (" << n->destination << ")";
        printTree(n->left, space);
    }

public:
    FlightBST() { root = nullptr; }

    void insert(int f, string d, string t) { root = insert(root, f, d, t); }

    void searchFlight(int f) {
        Node* r = search(root, f);
        if (r)
            cout << "FOUND -> Flight " << r->flightNo << " | " << r->destination
                 << " | " << r->departureTime << "\n";
        else
            cout << "Flight " << f << " NOT found.\n";
    }

    void deleteFlight(int f) { root = deleteNode(root, f); }

    void showInorder()   { cout << "\n--- In-order Traversal ---\n";   inorder(root); }
    void showPreorder()  { cout << "\n--- Pre-order Traversal ---\n";  preorder(root); }
    void showPostorder() { cout << "\n--- Post-order Traversal ---\n"; postorder(root); }

    void showMinMax() {
        Node* mn = findMin(root);
        Node* mx = findMax(root);
        if (!mn) { cout << "Tree is empty.\n"; return; }
        cout << "Minimum flight number: " << mn->flightNo << " (" << mn->destination << ")\n";
        cout << "Maximum flight number: " << mx->flightNo << " (" << mx->destination << ")\n";
    }

    void showCount()  { cout << "Total number of flights: " << count(root) << "\n"; }
    void showHeight() { cout << "Height of the tree: " << height(root) << "\n"; }

    void showStructure() {
        cout << "\n--- BST Structure (rotated 90 degrees, root at left) ---";
        printTree(root, 0);
        cout << "\n";
    }
};

// ---------------- Main ----------------
int main() {
    FlightBST bst;

    cout << "========== INSERTING FLIGHT RECORDS ==========\n";
    bst.insert(500, "Dubai",      "08:00 AM");
    bst.insert(300, "London",     "09:30 AM");
    bst.insert(700, "Istanbul",   "11:15 AM");
    bst.insert(200, "Doha",       "12:00 PM");
    bst.insert(400, "Jeddah",     "01:45 PM");
    bst.insert(600, "Toronto",    "03:30 PM");
    bst.insert(800, "New York",   "05:00 PM");
    bst.insert(100, "Karachi",    "06:15 PM");
    bst.insert(250, "Lahore",     "07:00 PM");
    bst.insert(350, "Riyadh",     "08:30 PM");
    bst.insert(650, "Kuala Lumpur","09:45 PM");
    bst.insert(900, "Tokyo",      "11:00 PM");
    bst.insert(450, "Muscat",     "11:50 PM");
    cout << "13 flight records inserted.\n";

    bst.showInorder();
    bst.showPreorder();
    bst.showPostorder();

    cout << "\n========== SEARCH ==========\n";
    bst.searchFlight(650);
    bst.searchFlight(999);

    cout << "\n========== MIN / MAX / COUNT / HEIGHT ==========\n";
    bst.showMinMax();
    bst.showCount();
    bst.showHeight();

    cout << "\n========== BST BEFORE DELETION ==========";
    bst.showStructure();

    cout << "\n========== DELETION ==========\n";
    bst.deleteFlight(100);   // Case 1: leaf node
    bst.deleteFlight(600);   // Case 2: node with one child (650)
    bst.deleteFlight(300);   // Case 3: node with two children
    bst.deleteFlight(999);   // flight that does not exist

    cout << "\n========== AFTER DELETION ==========\n";
    bst.showInorder();
    bst.showMinMax();
    bst.showCount();
    bst.showHeight();
    bst.showStructure();

    return 0;
}
