#include <iostream>
using namespace std;

int main()
{
    int marks[8];
    int total = 0;
    float average;

    cout << "Enter marks of 8 students:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
        total = total + marks[i];
    }

    average = total / 8.0;

    int highest = marks[0];
    int lowest = marks[0];
    for (int i = 1; i < 8; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    cout << "\nStudent Marks:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "Student " << i + 1 << " = " << marks[i] << endl;
    }

    cout << "\nTotal Marks = " << total << endl;
    cout << "Average Marks = " << average << endl;
    cout << "Highest Marks = " << highest << endl;
    cout << "Lowest Marks = " << lowest << endl;

    return 0;
}
