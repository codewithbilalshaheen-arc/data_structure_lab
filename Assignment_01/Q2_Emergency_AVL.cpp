#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// ---------------- Node ----------------
class Node {
public:
    int emergencyId;
    string location;
    int severity;       // severity level (e.g. 1 = low ... 5 = critical)
    int height;
    Node* left;
    Node* right;

    Node(int id, string loc, int sev) {
        emergencyId = id;
        location = loc;
        severity = sev;
        height = 1;
        left = right = nullptr;
    }
};

// ---------------- AVL Tree ----------------
class AVLTree {
private:
    Node* root;

    int height(Node* n) { return n ? n->height : 0; }
    int balanceFactor(Node* n) { return n ? height(n->left) - height(n->right) : 0; }
    void updateHeight(Node* n) { n->height = 1 + max(height(n->left), height(n->right)); }

    // Right Rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    // Left Rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    // Rebalance a node; handles LL, RR, LR, RL (used by insert and delete)
    Node* rebalance(Node* node) {
        updateHeight(node);
        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->left) >= 0) {
                cout << "  [Node " << node->emergencyId << " unbalanced] LL case -> Right Rotation\n";
                return rotateRight(node);
            } else {
                cout << "  [Node " << node->emergencyId << " unbalanced] LR case -> Left Rotation on "
                     << node->left->emergencyId << ", then Right Rotation on " << node->emergencyId << "\n";
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (bf < -1) {
            if (balanceFactor(node->right) <= 0) {
                cout << "  [Node " << node->emergencyId << " unbalanced] RR case -> Left Rotation\n";
                return rotateLeft(node);
            } else {
                cout << "  [Node " << node->emergencyId << " unbalanced] RL case -> Right Rotation on "
                     << node->right->emergencyId << ", then Left Rotation on " << node->emergencyId << "\n";
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }

    Node* insert(Node* node, int id, string loc, int sev) {
        if (node == nullptr) return new Node(id, loc, sev);
        if (id < node->emergencyId)      node->left  = insert(node->left, id, loc, sev);
        else if (id > node->emergencyId) node->right = insert(node->right, id, loc, sev);
        else { cout << "Emergency ID " << id << " already exists. Ignored.\n"; return node; }
        return rebalance(node);
    }

    Node* minNode(Node* n) {
        while (n && n->left) n = n->left;
        return n;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == nullptr) {
            cout << "Emergency ID " << id << " not found. Nothing deleted.\n";
            return nullptr;
        }
        if (id < node->emergencyId)      node->left  = deleteNode(node->left, id);
        else if (id > node->emergencyId) node->right = deleteNode(node->right, id);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* child = node->left ? node->left : node->right;
                delete node;
                return child;          // leaf (nullptr) or one child
            }
            // two children: copy in-order successor
            Node* succ = minNode(node->right);
            node->emergencyId = succ->emergencyId;
            node->location = succ->location;
            node->severity = succ->severity;
            node->right = deleteNode(node->right, succ->emergencyId);
        }
        return rebalance(node);
    }

    Node* search(Node* node, int id) {
        if (node == nullptr || node->emergencyId == id) return node;
        if (id < node->emergencyId) return search(node->left, id);
        return search(node->right, id);
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << "ID: " << n->emergencyId << " | " << n->location
             << " | Severity: " << n->severity << "\n";
        inorder(n->right);
    }

    void details(Node* n) {
        if (!n) return;
        details(n->left);
        cout << "ID " << n->emergencyId << "\t| Height = " << n->height
             << "\t| Balance Factor = " << balanceFactor(n) << "\n";
        details(n->right);
    }

    void printTree(Node* n, int space) {
        if (!n) return;
        space += 8;
        printTree(n->right, space);
        cout << "\n";
        for (int i = 8; i < space; i++) cout << " ";
        cout << n->emergencyId << " (" << n->location << ", S" << n->severity << ")";
        printTree(n->left, space);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int id, string loc, int sev) {
        cout << "Inserting " << id << " (" << loc << ")\n";
        root = insert(root, id, loc, sev);
    }

    void deleteRecord(int id) {
        cout << "Deleting " << id << "\n";
        root = deleteNode(root, id);
    }

    void searchRecord(int id) {
        Node* r = search(root, id);
        if (r)
            cout << "FOUND -> ID: " << r->emergencyId << " | " << r->location
                 << " | Severity: " << r->severity << "\n";
        else
            cout << "Emergency ID " << id << " NOT found.\n";
    }

    void showInorder() {
        cout << "\n--- In-order Traversal (records sorted by Emergency ID) ---\n";
        inorder(root);
    }

    void showLevelOrder() {
        cout << "\n--- Level-order (BFS) Traversal ---\n";
        if (!root) { cout << "Tree is empty.\n"; return; }
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            while (sz--) {
                Node* n = q.front(); q.pop();
                cout << n->emergencyId << "(" << n->location << ") ";
                if (n->left)  q.push(n->left);
                if (n->right) q.push(n->right);
            }
            cout << "\n";
        }
    }

    void showDetails() {
        cout << "\n--- Height & Balance Factor of each node ---\n";
        details(root);
    }

    void showStructure() {
        cout << "\n--- AVL Tree Structure (rotated 90 degrees, root at left) ---";
        printTree(root, 0);
        cout << "\n";
    }
};

// ---------------- Main ----------------
int main() {
    AVLTree avl;

    cout << "========== INSERTING EMERGENCY RECORDS ==========\n";
    avl.insert(50, "Islamabad",   4);
    avl.insert(40, "Rawalpindi",  3);
    avl.insert(30, "Murree",      5);   // LL
    avl.insert(60, "Lahore",      2);
    avl.insert(70, "Karachi",     5);   // RR
    avl.insert(55, "Peshawar",    3);   // RL
    avl.insert(20, "Quetta",      4);   // LL
    avl.insert(10, "Gilgit",      5);
    avl.insert(15, "Swat",        3);   // LR
    avl.insert(35, "Mansehra",    2);
    avl.insert(80, "Multan",      1);
    avl.insert(65, "Faisalabad",  2);
    avl.insert(25, "Abbottabad",  4);

    avl.showInorder();
    avl.showLevelOrder();
    avl.showDetails();
    avl.showStructure();

    cout << "\n========== SEARCH ==========\n";
    avl.searchRecord(35);
    avl.searchRecord(99);

    cout << "\n========== DELETION (with auto-balancing) ==========\n";
    avl.deleteRecord(80);
    avl.deleteRecord(70);
    avl.deleteRecord(10);
    avl.deleteRecord(99);

    cout << "\n========== FINAL TREE ==========\n";
    avl.showInorder();
    avl.showLevelOrder();
    avl.showDetails();
    avl.showStructure();

    return 0;
}
