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

// First Method
node *Kth_node_from_end(node *head, int k)
{
    node *curr = head;
    int n = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        n++;
    }

    if (n >= k)
    {
        curr = head;
        for (int i = 0; i < n - k; i++)
        {
            curr = curr->next;
        }
    }
    else
    {
        cout << "Invalid Choice !!" << endl;
    }
    return curr;
}

// Second Method
void Kth_Node_From_End(node *head, int k)
{
    if (head == NULL)
    {
        return;
    }

    node *slow = head;
    node *fast = head;

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->data << endl;
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

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "The Kth node from end is(by 1st method): ";
    node *K_node = Kth_node_from_end(head, k);
    cout << K_node->data << endl;
    cout << "The Kth node from end is(by 1st method): ";
    Kth_Node_From_End(head, k);
    return 0;
}