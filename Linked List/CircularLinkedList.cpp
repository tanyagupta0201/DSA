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

void print(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
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
        Insert_At_Head(head, data);
    }
    print(head);
    return 0;
}