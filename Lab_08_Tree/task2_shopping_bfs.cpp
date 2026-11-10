// Task 2: Online Shopping Categories - BFS (Level Order) Traversal
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string c) {
        category = c;
        left = right = nullptr;
    }
};

// Breadth-First Traversal using a queue (visits level by level)
void bfs(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSize = q.size();   // number of nodes at current level
        cout << "Level " << level << " : ";

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->category << "  ";

            if (current->left)  q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << "\n";
        level++;
    }
}

int main() {
    /*
                      Products
                   /            \
             Electronics       Clothing
              /      \          /     \
          Mobiles  Laptops    Men    Women
                                         \
                                      Accessories
    */
    Node* root = new Node("Products");

    root->left  = new Node("Electronics");
    root->right = new Node("Clothing");

    root->left->left   = new Node("Mobiles");
    root->left->right  = new Node("Laptops");
    root->right->left  = new Node("Men");
    root->right->right = new Node("Women");

    root->right->right->right = new Node("Accessories");

    cout << "===== Product Categories (BFS Order) =====\n\n";
    bfs(root);

    cout << "\nBFS Order: ";
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* c = q.front(); q.pop();
        cout << c->category;
        if (c->left)  q.push(c->left);
        if (c->right) q.push(c->right);
        if (!q.empty()) cout << " -> ";
    }
    cout << "\n";

    return 0;
}
