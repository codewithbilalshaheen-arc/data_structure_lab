#include <iostream>
#include <algorithm>
using namespace std;

// ---------------- Node ----------------
class Node {
public:
    int regNo;
    int height;
    Node* left;
    Node* right;

    Node(int r) {
        regNo = r;
        height = 1;          // leaf node has height 1
        left = right = nullptr;
    }
};

// ---------------- AVL Tree ----------------
class AVLTree {
private:
    Node* root;

    int height(Node* n) { return n ? n->height : 0; }

    int balanceFactor(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    void updateHeight(Node* n) {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    // Right rotation (LL case)
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    // Left rotation (RR case)
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        // 1. Normal BST insertion
        if (node == nullptr) return new Node(key);
        if (key < node->regNo)       node->left  = insert(node->left, key);
        else if (key > node->regNo)  node->right = insert(node->right, key);
        else { cout << "Duplicate " << key << " ignored.\n"; return node; }

        // 2. Update height
        updateHeight(node);

        // 3. Check balance
        int bf = balanceFactor(node);

        // Left-Left
        if (bf > 1 && key < node->left->regNo) {
            cout << "  [Imbalance at " << node->regNo << "] Left-Left case -> Right Rotation\n";
            return rotateRight(node);
        }
        // Right-Right
        if (bf < -1 && key > node->right->regNo) {
            cout << "  [Imbalance at " << node->regNo << "] Right-Right case -> Left Rotation\n";
            return rotateLeft(node);
        }
        // Left-Right
        if (bf > 1 && key > node->left->regNo) {
            cout << "  [Imbalance at " << node->regNo << "] Left-Right case -> Left Rotation on "
                 << node->left->regNo << ", then Right Rotation on " << node->regNo << "\n";
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right-Left
        if (bf < -1 && key < node->right->regNo) {
            cout << "  [Imbalance at " << node->regNo << "] Right-Left case -> Right Rotation on "
                 << node->right->regNo << ", then Left Rotation on " << node->regNo << "\n";
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->regNo << " ";
        inorder(n->right);
    }

    // Prints height and balance factor of each node (in-order)
    void printDetails(Node* n) {
        if (!n) return;
        printDetails(n->left);
        cout << "Node " << n->regNo << "\t| Height = " << n->height
             << "\t| Balance Factor = " << balanceFactor(n) << "\n";
        printDetails(n->right);
    }

    // Sideways tree view (right child on top)
    void printTree(Node* n, int space) {
        if (!n) return;
        space += 6;
        printTree(n->right, space);
        cout << "\n";
        for (int i = 6; i < space; i++) cout << " ";
        cout << n->regNo;
        printTree(n->left, space);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int key) {
        cout << "Inserting " << key << "\n";
        root = insert(root, key);
    }

    void showDetails() {
        cout << "\nHeight & Balance Factor of each node:\n";
        printDetails(root);
    }

    void showTree() {
        cout << "\nFinal AVL Tree structure (rotated 90 degrees, root at left):\n";
        printTree(root, 0);
        cout << "\n";
    }

    void showInorder() {
        cout << "\nIn-order Traversal: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    AVLTree tree;
    int regNos[] = {50, 30, 70, 20, 40, 35};

    for (int r : regNos) tree.insert(r);

    tree.showDetails();
    tree.showTree();
    tree.showInorder();
    return 0;
}
