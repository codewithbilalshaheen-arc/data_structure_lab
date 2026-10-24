#include <iostream>
#include <conio.h>
using namespace std;

struct link
{
	int data;
	link *next;
};

class list
{
private:
	int length;
	link *start, *temp1, *temp2, *element, *end;

public:
	list(void)
	{
		start = NULL;
		length = 0;
	}
	void add(int d, int index)
	{
		// cout<<endl<<"Hello "<<length;
		if (length == 0)
		{
			cout << d << " Beginning" << endl;
			start = new link;
			start->data = d;
			start->next = NULL;
			length++;
		}
		else //(start!=NULL)
		{
			element = new link;
			element->data = d;
			if (index == 0)
			{
				cout << d << " Start" << endl;
				element->next = start;
				start = element;
				length++;
			}
			else if (index == length)
			{
				int i = 0;
				temp1 = start;
				// cout<<endl;
				while (i != index - 1)
				{
					temp1 = temp1->next;
					i++;
					// cout<<temp1->data<<",";
				}
				temp1->next = element;
				cout << d << " End" << endl;
				length++;
			}
			else if (index > 0 && index < length)
			{
				cout << d << " Between at index " << index << endl;
				int i = 0;
				temp1 = start;
				while (i != index - 1)
				{
					temp1 = temp1->next;
					i++;
					// cout<<temp1->data<<"chawal,";
				}
				temp2 = temp1->next;
				temp1->next = element;
				element->next = temp2;
				length++;
			}
		}
	}

	void show(void)
	{
		link *temp;
		temp = start;
		cout << endl;
		int i = 0;
		while (i < length)
		{
			cout << temp->data << ",";
			temp = temp->next;
			i++;
		}
	}
	void search(int N)
	{
		link *temp, *ptr;
		temp = start;
		int i = 0;
		cout << endl;
		while (i < length)
		{
			if (temp->data == N)
				break;
			// cout<<temp->data<<",";
			ptr = temp;
			temp = temp->next;
			i++;
		}
		// cout<<endl<<i<<","<<length<<endl;
		if (i == length)
			cout << "Given element not found" << endl;
		else
			cout << "Given element is at index: " << i + 1 << " and address: " << ptr->next;
	}
};
int main()
{
	// int *j=NULL;
	// cout<<&j;
	list *L;
	L = new list;
	L->add(10, 0);
	L->add(20, 0);
	L->add(5, 0);
	L->add(15, 0);
	L->add(30, 0);
	L->add(36, 0);
	L->add(255, 4);
	L->add(205, 7);
	L->show();
	L->search(255);
	L->search(300);
	getch();
}