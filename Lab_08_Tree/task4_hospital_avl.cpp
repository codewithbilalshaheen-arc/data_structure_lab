// Task 4: Hospital Appointment System - AVL Tree
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int t) {
        token = t;
        left = right = nullptr;
        height = 1;   // a new node is a leaf
    }
};

// ---------- Height & Balance Factor ----------
int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

// ---------- Rotations ----------
// Right Rotation (used for LL case)
Node* rightRotate(Node* y) {
    Node* x  = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left  = T2;

    updateHeight(y);
    updateHeight(x);
    return x;   // new root
}

// Left Rotation (used for RR case)
Node* leftRotate(Node* x) {
    Node* y  = x->right;
    Node* T2 = y->left;

    y->left  = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;   // new root
}

// ---------- Insertion (BST rules + balancing) ----------
Node* insert(Node* root, int token) {
    // 1. Normal BST insertion
    if (root == nullptr) return new Node(token);

    if (token < root->token)
        root->left = insert(root->left, token);
    else if (token > root->token)
        root->right = insert(root->right, token);
    else
        return root;   // duplicate tokens not allowed

    // 2. Update height
    updateHeight(root);

    // 3. Check balance factor
    int balance = getBalance(root);

    // LL Case -> Right Rotation
    if (balance > 1 && token < root->left->token) {
        cout << "   [LL case at " << root->token << "] -> Right Rotation\n";
        return rightRotate(root);
    }

    // RR Case -> Left Rotation
    if (balance < -1 && token > root->right->token) {
        cout << "   [RR case at " << root->token << "] -> Left Rotation\n";
        return leftRotate(root);
    }

    // LR Case -> Left Rotation on left child, then Right Rotation
    if (balance > 1 && token > root->left->token) {
        cout << "   [LR case at " << root->token << "] -> Left + Right Rotation\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case -> Right Rotation on right child, then Left Rotation
    if (balance < -1 && token < root->right->token) {
        cout << "   [RL case at " << root->token << "] -> Right + Left Rotation\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// ---------- Display ----------
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->token << "  ";
    inorder(root->right);
}

// Sideways tree (right child on top, left child at bottom)
void printTree(Node* root, int space = 0) {
    if (root == nullptr) return;
    space += 8;
    printTree(root->right, space);
    cout << "\n";
    for (int i = 8; i < space; i++) cout << " ";
    cout << root->token << " (h=" << root->height
         << ", bf=" << getBalance(root) << ")\n";
    printTree(root->left, space);
}

// Print height and balance factor of every node (in-order)
void printNodeInfo(Node* root) {
    if (root == nullptr) return;
    printNodeInfo(root->left);
    cout << "   Token " << root->token
         << "  | Height = " << root->height
         << "  | Balance Factor = " << getBalance(root) << "\n";
    printNodeInfo(root->right);
}

int main() {
    Node* root = nullptr;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "===== Hospital Appointment System (AVL Tree) =====\n\n";

    for (int t : tokens) {
        cout << "Inserting token " << t << "\n";
        root = insert(root, t);
    }

    cout << "\nIn-order Traversal (sorted tokens):\n   ";
    inorder(root);
    cout << "\n";

    cout << "\nHeight and Balance Factor of each node:\n";
    printNodeInfo(root);

    cout << "\nFinal Balanced Tree Structure (rotated 90 degrees, root at left):\n";
    printTree(root);

    // ---------- Extra demo: shows LL, LR and RL cases too ----------
    cout << "\n\n===== Extra Demo: All Rotation Cases =====\n";

    cout << "\nLL case (30, 20, 10):\n";
    Node* a = nullptr;
    for (int t : {30, 20, 10}) a = insert(a, t);
    cout << "   Root after balancing: " << a->token << "\n";

    cout << "\nLR case (30, 10, 20):\n";
    Node* b = nullptr;
    for (int t : {30, 10, 20}) b = insert(b, t);
    cout << "   Root after balancing: " << b->token << "\n";

    cout << "\nRL case (10, 30, 20):\n";
    Node* c = nullptr;
    for (int t : {10, 30, 20}) c = insert(c, t);
    cout << "   Root after balancing: " << c->token << "\n";

    cout << "\nRR case (10, 20, 30):\n";
    Node* d = nullptr;
    for (int t : {10, 20, 30}) d = insert(d, t);
    cout << "   Root after balancing: " << d->token << "\n";

    return 0;
}
