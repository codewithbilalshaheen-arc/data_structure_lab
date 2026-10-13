#include <iostream>
#include <string>
using namespace std;

// Node class represents one order
class Node
{
public:
    string orderID;     // Stores the order ID
    Node* next;         // Stores address of the next node

    // Constructor
    Node(string id)
    {
        orderID = id;
        next = NULL;
    }
};

// Stack class using singly linked list
class OrderStack
{
private:
    Node* top;          // Points to the TOP node

public:
    // Constructor: stack is initially empty
    OrderStack()
    {
        top = NULL;
    }

    // Destructor: free all remaining nodes
    ~OrderStack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // PUSH: Insert a new order at TOP
    void push(string id)
    {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
        cout << id << " received (pushed into stack)." << endl;
    }

    // POP: Process the latest order
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow! No order to process." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << temp->orderID << " processed (popped from stack)." << endl;
        delete temp;
    }

    // PEEK: Display the TOP order
    void peek()
    {
        if (top == NULL)
        {
            cout << "No orders left!" << endl;
        }
        else
        {
            cout << "Current TOP order: " << top->orderID << endl;
        }
    }

    // DISPLAY: Show all orders from TOP to bottom
    void display()
    {
        if (top == NULL)
        {
            cout << "No orders left!" << endl;
            return;
        }

        Node* current = top;
        cout << "Orders (TOP to bottom):" << endl;
        while (current != NULL)
        {
            cout << "  " << current->orderID << endl;
            current = current->next;
        }
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{
    OrderStack restaurant;

    // 1. Push order IDs
    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    // 2. Display all orders from TOP to bottom
    cout << endl;
    restaurant.display();

    // 3. Perform two POP operations to process two orders
    cout << endl;
    restaurant.pop();
    restaurant.pop();

    // 4. Display the current TOP order
    cout << endl;
    restaurant.peek();

    // 5. Display the remaining orders
    cout << endl;
    restaurant.display();

    // 6. Check whether the stack is empty
    cout << endl;
    if (restaurant.isEmpty())
        cout << "The stack is empty." << endl;
    else
        cout << "The stack is NOT empty." << endl;

    return 0;
}
