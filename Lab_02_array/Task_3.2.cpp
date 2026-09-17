#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int *marks = new int[n];
    int total = 0;

    cout << "Enter " << n << " marks:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
        total = total + marks[i];
    }

    int highest = marks[0];
    int lowest = marks[0];
    for (int i = 1; i < n; i++)
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

    float average = total / (float)n;

    cout << "\nTotal Marks = " << total << endl;
    cout << "Average Marks = " << average << endl;
    cout << "Highest Marks = " << highest << endl;
    cout << "Lowest Marks = " << lowest << endl;

    delete[] marks;
    return 0;
}
