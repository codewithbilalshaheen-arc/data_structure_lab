#include <iostream>
#include <string>
using namespace std;

struct StaffNode {
    string name; StaffNode *left{}, *right{};
    StaffNode(string n) : name(n) {}
};

void showStaff(StaffNode* n) {
    if (!n) return;
    cout << n->name << " -> Left: " << (n->left ? n->left->name : "NULL")
         << ", Right: " << (n->right ? n->right->name : "NULL") << "\n";
    showStaff(n->left); showStaff(n->right);
}

void showStaffInOrder(StaffNode* n) {
    if (!n) return;
    showStaffInOrder(n->left); cout << n->name << " | "; showStaffInOrder(n->right);
}

void deleteStaff(StaffNode* n) {
    if (!n) return;
    deleteStaff(n->left); deleteStaff(n->right); delete n;
}

struct BSTNode {
    int id; BSTNode *left{}, *right{};
    BSTNode(int v) : id(v) {}
};

class BST {
    BSTNode* root{};

    BSTNode* insert(BSTNode* n, int id, bool& add) {
        if (!n) return add = true, new BSTNode(id);
        if (id < n->id) n->left = insert(n->left, id, add);
        else if (id > n->id) n->right = insert(n->right, id, add);
        return n;
    }

    BSTNode* remove(BSTNode* n, int id, bool& rem) {
        if (!n) return nullptr;
        if (id < n->id) n->left = remove(n->left, id, rem);
        else if (id > n->id) n->right = remove(n->right, id, rem);
        else {
            rem = true;
            if (!n->left || !n->right) {
                BSTNode* t = n->left ? n->left : n->right;
                delete n; return t;
            }
            BSTNode* s = n->right;
            while (s->left) s = s->left;
            n->id = s->id;
            bool dummy; n->right = remove(n->right, s->id, dummy);
        }
        return n;
    }

    void display(BSTNode* n) {
        if (!n) return;
        display(n->left); cout << n->id << " "; display(n->right);
    }

    void destroy(BSTNode* n) {
        if (!n) return;
        destroy(n->left); destroy(n->right); delete n;
    }

public:
    ~BST() { destroy(root); }
    bool insert(int id) { bool a = false; root = insert(root, id, a); return a; }
    bool remove(int id) { bool r = false; root = remove(root, id, r); return r; }
    
    bool search(int id, int& v) {
        v = 0;
        for (auto c = root; c; v++) {
            if (id == c->id) return true;
            c = (id < c->id) ? c->left : c->right;
        }
        return false;
    }

    void display() { display(root); cout << "\n"; }
};

void fillOriginal(BST& t) { for (int id : {48, 28, 68, 18, 38, 58, 78}) t.insert(id); }

void searchAndShow(BST& t, int id) {
    int v; bool f = t.search(id, v);
    cout << "Search " << id << ": " << (f ? "Found" : "Not found") << ", node visits = " << v << "\n";
}

void testDeletion(string title, int fr, int target) {
    BST t; fillOriginal(t);
    if (fr != -1) t.remove(fr);
    cout << title << "\nBefore: "; t.display();
    t.remove(target);
    cout << "After deleting " << target << ": "; t.display(); cout << "\n";
}

int main() {
    cout << "--- General Binary Tree ---\n";
    StaffNode* root = new StaffNode("Vice Chancellor");
    root->left = new StaffNode("Dean"); root->right = new StaffNode("Registrar");
    root->left->left = new StaffNode("HOD Computer Science"); root->left->right = new StaffNode("HOD Mathematics");
    root->right->left = new StaffNode("Accountant"); root->right->right = new StaffNode("Librarian");

    showStaff(root);
    cout << "In-order of general tree: "; showStaffInOrder(root); cout << "\n\n";

    cout << "--- BST of Staff IDs ---\n";
    BST tree; fillOriginal(tree);
    cout << "Initial IDs: "; tree.display();

    for (int count = 0, id; count < 3; ) {
        cout << "Enter a staff ID to insert: "; cin >> id;
        if (tree.insert(id)) { cout << id << " inserted.\n"; count++; }
        else cout << id << " already exists. Duplicate rejected.\n";
    }
    cout << "IDs now: "; tree.display(); cout << "\n";

    cout << "--- Search Tests ---\n";
    searchAndShow(tree, 58); searchAndShow(tree, 60); searchAndShow(tree, 5); cout << "\n";

    cout << "--- Deletion Tests (fresh BST each time) ---\n";
    testDeletion("Leaf node (18):", -1, 18);
    testDeletion("Node with one child (28 after removing 18):", 18, 28);
    testDeletion("Node with two children (48):", -1, 48);

    int id; cout << "Enter a staff ID to delete: "; cin >> id;
    if (tree.remove(id)) cout << id << " deleted.\n";
    else cout << id << " not found.\n";
    cout << "Remaining IDs in ascending order: "; tree.display(); cout << "\n";

    cout << "--- Why In-order Differs ---\n"
         << "In a general binary tree, nodes are linked in any order, so in-order traversal\n"
         << "follows the tree shape and the output is not necessarily sorted.\n"
         << "In a BST, every left value is smaller and every right value is larger,\n"
         << "so in-order (left, node, right) always gives ascending order.\n";

    deleteStaff(root);
}