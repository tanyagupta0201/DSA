// Overloading left and right operators

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

void InsertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
}

int main()
{
    node *head = NULL;
    int data;
    cout << "Enter the data you want to insert: ";
    cin >> data;

    while (data != -1)
    {
        InsertAtTail(head, data);
        cout << "Enter the next data (Press -1 for exit): ";
        cin >> data;
    }

    print(head);
    return 0;
}