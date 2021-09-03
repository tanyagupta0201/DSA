// Delete a node from a Linked List

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void display(node *head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty!!";
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << " NULL " << endl;
}

void InsertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);
    return;
}

// When we have to delete the first node
void DeleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int data)
{
    // When there is no node
    if (head == NULL)
    {
        return;
    }

    // If there is only one node in the linked list or when we have to delete the first node
    if (head->next == NULL or head->data == data)
    {
        DeleteAtHead(head);
        return;
    }

    node *temp = head;
    // We need to reach to the node before the actual node to be deleted and join it with the node after the node which is to be deleted
    while (temp->next->data != data)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    // Joining it with the node after the node which is to be deleted
    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    node *head = NULL;
    int n, data;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data: ";
        cin >> data;
        InsertAtTail(head, data);
    }
    display(head);

    int val;
    cout << "Enter the data to be deleted: ";
    cin >> val;

    deletion(head, val);
    display(head);
    return 0;
}