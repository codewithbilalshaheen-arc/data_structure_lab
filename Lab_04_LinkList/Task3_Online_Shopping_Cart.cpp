// Lab 04 - Linked Lists
// Task 3: Online Shopping Cart (Singly Linked List)

#include <iostream>
#include <string>
using namespace std;

// A node stores one product's ID and a pointer to the next node
struct Node {
    string productId;
    Node* next;

    Node(const string& id) {
        productId = id;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() { head = nullptr; }

    ~ShoppingCart() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add a product to the end of the cart
    void addProduct(const string& id) {
        Node* newNode = new Node(id);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }

    // Display all products in the cart
    void display() const {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->productId;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }

    // Remove a product using its Product ID
    bool removeProduct(const string& id) {
        if (head == nullptr)
            return false;

        // Case 1: the product is the first node
        if (head->productId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Case 2: the product is somewhere after the first node
        Node* current = head;
        while (current->next != nullptr && current->next->productId != id)
            current = current->next;

        if (current->next == nullptr)
            return false;               // not found

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string id;

    do {
        cout << "\n===== Online Shopping Cart =====\n";
        cout << "1. Add a product\n";
        cout << "2. Display cart\n";
        cout << "3. Remove a product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;
            cart.addProduct(id);
            cout << "Product " << id << " added to the cart.\n";
            break;
        case 2:
            cout << "Shopping Cart:\n";
            cart.display();
            break;
        case 3:
            cout << "Remove Product: ";
            cin >> id;
            if (cart.removeProduct(id)) {
                cout << "Product " << id << " removed.\n";
                cout << "Updated Cart:\n";
                cart.display();
            } else {
                cout << "Product " << id << " not found in the cart.\n";
            }
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
