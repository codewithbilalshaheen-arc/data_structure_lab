#include <iostream>
#include <string>
using namespace std;

class BrowserHistory
{
private:
    string pages[10];   // Array to store visited pages
    int top;            // Keeps track of TOP
    int size;           // Maximum capacity of the stack

public:
    // Constructor: stack is initially empty
    BrowserHistory()
    {
        top = -1;
        size = 10;
    }

    // PUSH: Visit a new page
    void push(string page)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow! History is full." << endl;
        }
        else
        {
            top++;
            pages[top] = page;
            cout << page << " visited (pushed into history)." << endl;
        }
    }

    // POP: Back button, removes the most recently visited page
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! No page to go back." << endl;
        }
        else
        {
            cout << "Back button pressed: " << pages[top] << " removed from history." << endl;
            top--;
        }
    }

    // PEEK: Display the current page (TOP)
    void peek()
    {
        if (top == -1)
        {
            cout << "History is Empty!" << endl;
        }
        else
        {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }

    // DISPLAY: Show all pages from TOP to bottom
    void display()
    {
        if (top == -1)
        {
            cout << "History is Empty!" << endl;
        }
        else
        {
            cout << "Browsing history (TOP to bottom):" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << "  " << pages[i] << endl;
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
    BrowserHistory history;

    // 1. Push visited pages
    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    // 2. Display all pages from TOP to bottom
    cout << endl;
    history.display();

    // 3. Perform one POP to simulate the Back button
    cout << endl;
    history.pop();

    // 4. Display the current TOP page
    cout << endl;
    history.peek();

    // 5. Display the remaining browsing history
    cout << endl;
    history.display();

    return 0;
}
