#include <iostream>
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

void display(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty !!" << endl;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << " NULL " << endl;
}

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// head is taken by reference as we have to modify our linked list
void Insert_At_Head(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    n->next = head;
    head = n;
}

// head is taken by reference as we have to modify our linked list
void Insert_At_Tail(node *&head, int data)
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

// head is taken by reference as we have to modify our linked list
void Insert_At_Middle(node *&head, int data, int pos)
{
    if (head == NULL || pos == 0)
    {
        Insert_At_Head(head, data);
        return;
    }
    else if (pos > length(head))
    {
        Insert_At_Tail(head, data);
    }
    else
    {
        // Take pos - 1 jumps
        int jump = 1;
        node *temp = head;
        while (jump <= pos - 1)
        {
            jump++;
            temp = temp->next;
        }
        // Create a new node
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

// head is taken by reference as we have to modify our linked list
void Delete_Head(node *&head)
{
    if (head == NULL)
    {
        cout << "The list is empty !!" << endl;
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

/*int main()
{
    node *head = NULL;
    int n, data;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data: ";
        cin >> data;
        Insert_At_Head(head, data);
    }
    display(head);

    return 0;
} */

int main()
{
    node *head = NULL;
    int n, data, pos;
    int ch = 0;

    while (ch >= 0 and ch <= 5)
    {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 0: // Inserting a node at the beginning
            cout << "Enter the data: ";
            cin >> data;
            Insert_At_Head(head, data);
            break;

        case 1: // Inserting a node at the end
            cout << "Enter the data: ";
            cin >> data;
            Insert_At_Tail(head, data);
            break;

        case 2: // Inserting a node at the middle(at a given position)
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the position where you want to insert: ";
            cin >> pos;
            Insert_At_Middle(head, data, pos);
            break;

        case 3: // Find the length of linked list
            cout << "The length of the linked list: " << length(head) << endl;
            break;

        case 4: // Delete head
            Delete_Head(head);
            break;

        case 5: // Print the linked list
            display(head);
            break;

        default:
            cout << "Wrong choice entered !!" << endl;
            break;
        }
    }

    return 0;
}
