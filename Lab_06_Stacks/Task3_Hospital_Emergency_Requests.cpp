#include <iostream>
#include <string>
using namespace std;

// Node class represents one patient request
class Node
{
public:
    string requestID;   // Stores the patient request ID
    Node* next;         // Stores address of the next node

    // Constructor
    Node(string id)
    {
        requestID = id;
        next = NULL;
    }
};

// Stack class using singly linked list
class RequestStack
{
private:
    Node* top;          // Points to the TOP node

public:
    // Constructor: stack is initially empty
    RequestStack()
    {
        top = NULL;
    }

    // Destructor: free all remaining nodes
    ~RequestStack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // PUSH: Insert a new request at TOP
    void push(string id)
    {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
        cout << id << " received (pushed into stack)." << endl;
    }

    // POP: Handle the latest request
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow! No request to handle." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << temp->requestID << " handled (popped from stack)." << endl;
        delete temp;
    }

    // PEEK: Display the TOP request
    void peek()
    {
        if (top == NULL)
        {
            cout << "No requests left!" << endl;
        }
        else
        {
            cout << "Current TOP request: " << top->requestID << endl;
        }
    }

    // DISPLAY: Show all requests from TOP to bottom
    void display()
    {
        if (top == NULL)
        {
            cout << "No requests left!" << endl;
            return;
        }

        Node* current = top;
        cout << "Requests (TOP to bottom):" << endl;
        while (current != NULL)
        {
            cout << "  " << current->requestID << endl;
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
    RequestStack hospital;

    // 1. Push patient request IDs
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    // 2. Display all requests from TOP to bottom
    cout << endl;
    hospital.display();

    // 3. Perform one POP to handle the latest request
    cout << endl;
    hospital.pop();

    // 4. Display the new TOP request
    cout << endl;
    hospital.peek();

    // 5. Display the remaining requests
    cout << endl;
    hospital.display();

    return 0;
}
