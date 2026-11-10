// Task 3: Computer File Explorer - DFS Traversals (In-order, Pre-order, Post-order)
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f) {
        folder = f;
        left = right = nullptr;
    }
};

// In-order : Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->folder << "  ";
    inorder(root->right);
}

// Pre-order : Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->folder << "  ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order : Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->folder << "  ";
}

int main() {
    /*
                         C:
                     /        \
               Documents      Programs
                /     \         /     \
            Images   Videos   Games   Music
    */
    Node* root = new Node("C:");

    root->left  = new Node("Documents");
    root->right = new Node("Programs");

    root->left->left   = new Node("Images");
    root->left->right  = new Node("Videos");
    root->right->left  = new Node("Games");
    root->right->right = new Node("Music");

    cout << "===== Computer File Explorer (DFS) =====\n\n";

    cout << "In-order   (Left -> Root -> Right) :\n   ";
    inorder(root);
    cout << "\n\n";

    cout << "Pre-order  (Root -> Left -> Right) :\n   ";
    preorder(root);
    cout << "\n\n";

    cout << "Post-order (Left -> Right -> Root) :\n   ";
    postorder(root);
    cout << "\n\n";

    cout << "----- Visiting Order Explanation -----\n";
    cout << "In-order   : Visit left subtree, then the folder itself, then right subtree.\n";
    cout << "Pre-order  : Visit the folder first, then go deep into left, then right.\n";
    cout << "Post-order : Visit both subtrees first, the folder itself is visited last.\n";

    return 0;
}
