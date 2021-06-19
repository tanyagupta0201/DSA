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

node *MergeSort(node *head)
{
    // Base Case
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    // Rec Case
    // 1. Break
    node *mid = Midpoint(head);
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;

    // 2. Rec sort the two parts
    a = MergeSort(a);
    b = MergeSort(b);

    // 3. Merge Them
    node *c = Merge(a, b);
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

void print(node *head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty !!" << endl;
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
    int data, n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        InsertAtTail(head, data);
    }
    cout << "Linked List: " << endl;
    print(head);
    node *newNode = NULL;
    newNode = MergeSort(head);
    cout << "Sorted Linked List: " << endl;
    print(newNode);
    return 0;
}