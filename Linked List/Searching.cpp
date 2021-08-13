// To search an element in a linked list

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

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool SearchRecursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }
    else
    {
        return SearchRecursive(head->next, key);
    }
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

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;

    /*if (search(head, key))
    {
        cout << key << " is present !!" << endl;
    }
    else
    {
        cout << key << " is not present !!" << endl;
    }*/

    if (SearchRecursive(head, key))
    {
        cout << key << " is present !!" << endl;
    }
    else
    {
        cout << key << " is not present !!" << endl;
    }

    return 0;
}
