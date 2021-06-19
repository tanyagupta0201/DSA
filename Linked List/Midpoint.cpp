// Find midpoint of a Linked List (Runner Technique)

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

node *Midpoint(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void Insert_At_Tail(node *&head, int data)
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

void print(node *head)
{
    if (head == NULL)
    {
        cout << "The linked List is empty !!" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    int n, data;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        Insert_At_Tail(head, data);
    }
    print(head);
    cout << "Midpoint is: ";
    node *mid = Midpoint(head);
    cout << mid->data << endl;
    return 0;
}
