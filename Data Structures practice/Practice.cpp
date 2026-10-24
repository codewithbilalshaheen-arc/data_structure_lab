#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    ~Stack()
    { // free all nodes when stack dies
        while (top != NULL)
        {
            Node *t = top;
            top = top->next;
            delete t;
        }
    }
    bool isEmpty() { return top == NULL; }
    void push(int x)
    {
        Node *n = new Node;
        n->data = x;
        n->next = top; // 1. link to old top
        top = n;       // 2. move top
        cout << x << " pushed" << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow: nothing to pop" << endl;
            return;
        }
        Node *t = top;   // 1. save
        top = top->next; // 2. relink
        cout << t->data << " popped" << endl;
        delete t; // 3. free
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom):" << endl;
        for (Node *t = top; t != NULL; t = t->next)
            cout << t->data << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top = " << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop(); // underflow
    return 0;
}