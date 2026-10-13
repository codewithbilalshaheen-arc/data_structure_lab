#include <iostream>
#include <string>
using namespace std;

class UndoStack
{
private:
    string actions[10];   // Array to store user actions
    int top;              // Keeps track of TOP
    int size;             // Maximum capacity of the stack

public:
    // Constructor: stack is initially empty
    UndoStack()
    {
        top = -1;
        size = 10;
    }

    // PUSH: Record a new action
    void push(string action)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow! Cannot store more actions." << endl;
        }
        else
        {
            top++;
            actions[top] = action;
            cout << action << " (action recorded)." << endl;
        }
    }

    // POP: Undo the most recent action
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! Nothing to undo." << endl;
        }
        else
        {
            cout << "Undo: " << actions[top] << " reversed." << endl;
            top--;
        }
    }

    // PEEK: Display the current TOP action
    void peek()
    {
        if (top == -1)
        {
            cout << "No actions left!" << endl;
        }
        else
        {
            cout << "Current TOP action: " << actions[top] << endl;
        }
    }

    // DISPLAY: Show all actions from TOP to bottom
    void display()
    {
        if (top == -1)
        {
            cout << "No actions left!" << endl;
        }
        else
        {
            cout << "Actions (TOP to bottom):" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << "  " << actions[i] << endl;
            }
        }
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    UndoStack editor;

    // 1. Push actions
    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    // 2. Display all actions from TOP to bottom
    cout << endl;
    editor.display();

    // 3. Perform two POP operations to simulate Undo
    cout << endl;
    editor.pop();
    editor.pop();

    // 4. Display the current TOP action
    cout << endl;
    editor.peek();

    // 5. Display the remaining actions
    cout << endl;
    editor.display();

    return 0;
}
