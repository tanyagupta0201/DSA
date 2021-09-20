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

void Insert_At_Head(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;
    n->next = head;

    if (head != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n; // if there is a single node
    }
    head = n;
}

void Insert_At_Tail(node *&head, int data)
{
    if (head == NULL)
    {
        Insert_At_Head(head, data);
        return;
    }

    node *n = new node(data);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void Delete_At_Head(node *&head)
{
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

void Deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        Delete_At_Head(head);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void print(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;

    return;
}

int main()
{
    node *head = NULL;
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        Insert_At_Tail(head, data);
    }

    print(head);

    Insert_At_Head(head, 10);
    print(head);

    Insert_At_Tail(head, 23);
    print(head);

    Delete_At_Head(head);
    print(head);

    Deletion(head, 2);
    print(head);

    return 0;
}
