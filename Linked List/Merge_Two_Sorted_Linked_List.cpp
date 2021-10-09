#include <iostream>
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

node *Merge(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    node *c = NULL;
    if (head1->data < head2->data)
    {
        c = head1;
        c->next = Merge(head1->next, head2);
    }
    else
    {
        c = head2;
        c->next = Merge(head1, head2->next);
    }
    return c;
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

void display(node *head)
{
    if (head == NULL)
    {
        cout << "The Linked List is empty !!";
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
    node *head1 = NULL;
    node *head2 = NULL;
    int n1, n2, data;
    cout << "Creating 1st Linked List: " << endl;
    cout << "Enter the number of nodes you want to enter: ";
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter the data: ";
        cin >> data;
        InsertAtTail(head1, data);
    }

    cout << "Creating 2nd Linked List: " << endl;
    cout << "Enter the number of nodes you want to enter: ";
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter the data: ";
        cin >> data;
        InsertAtTail(head2, data);
    }

    display(head1);
    display(head2);

    node *NewNode = NULL;
    NewNode = Merge(head1, head2);
    cout << "The sorted list is: " << endl;
    display(NewNode);
    return 0;
}