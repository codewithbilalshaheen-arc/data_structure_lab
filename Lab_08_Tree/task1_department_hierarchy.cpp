// Task 1: University Department Hierarchy - Binary Tree Creation
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;   // department member's name
    string role;   // HOD / Coordinator / Faculty
    Node* left;
    Node* right;

    Node(string n, string r) {
        name = n;
        role = r;
        left = right = nullptr;
    }
};

// Display each member with their left and right children (pre-order walk)
void displayHierarchy(Node* root) {
    if (root == nullptr) return;

    cout << root->name << " (" << root->role << ")\n";
    cout << "   Left Child  : "
         << (root->left  ? root->left->name  : "None") << "\n";
    cout << "   Right Child : "
         << (root->right ? root->right->name : "None") << "\n\n";

    displayHierarchy(root->left);
    displayHierarchy(root->right);
}

int main() {
    // Level 0: HOD
    Node* hod = new Node("Dr. Ahmed Khan", "HOD");

    // Level 1: Coordinators
    hod->left  = new Node("Dr. Sara Ali", "Coordinator (BS Programs)");
    hod->right = new Node("Dr. Usman Tariq", "Coordinator (MS Programs)");

    // Level 2: Faculty
    hod->left->left   = new Node("Mr. Sharif Hussain", "Faculty");
    hod->left->right  = new Node("Ms. Ayesha Noor", "Faculty");
    hod->right->left  = new Node("Mr. Hamza Raza", "Faculty");
    hod->right->right = new Node("Ms. Fatima Zahra", "Faculty");

    cout << "===== University Department Hierarchy =====\n\n";
    displayHierarchy(hod);

    return 0;
}
