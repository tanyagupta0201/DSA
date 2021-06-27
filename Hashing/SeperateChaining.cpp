#include <iostream>
#include <cstring>
#include "hashtable.h"
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;

    node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }

    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
    node<T> **table; // Pointer to an array of pointers
    int curr_size;
    int table_size;

    int HashFun(string key)
    {
        int index = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            index = index + (key[j] * p) % table_size;
            index = index % table_size;
            p = (p * 37) % table_size;
        }
        return index;
    }

public:
    Hashtable(int ts = 7)
    {
        table_size = ts;
        table = new node<T> *[table_size];
        curr_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void ReHash()
    {
        node<T> **oldTable = table;
        int old_tableSize = table_size;
        table_size = 2 * table_size; // approxiamation to find the next prime number
        table = new node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        curr_size = 0;

        // Shift the elements from oldTable to the new Table
        for (int i = 0; i < old_tableSize; i++)
        {
            node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

    void insert(string key, T value)
    {
        int index = HashFun(key);

        node<T> *n = new node<T>(key, value);
        // Insert at the head of the linked list with id = index
        n->next = table[index];
        table[index] = n;
        curr_size++;

        // Rehash
        float load_factor = curr_size / (1.0 * table_size);

        if (load_factor > 0.7)
        {
            ReHash();
        }
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << " --> ";
            node<T> *temp = table[i];

            while (temp != NULL)
            {
                cout << temp->key << " --> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T *search(string key)
    {
        int index = HashFun(key);
        node<T> *temp = table[index];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL; // T*
    }

    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Pizza", 120);
    price_menu.insert("Noodles", 20);
    price_menu.insert("Burger", 150);
    price_menu.insert("Pasta", 25);
    price_menu.insert("Coca Cola", 40);

    price_menu.print();

    int *price = price_menu.search("Pasta");
    if (price == NULL)
    {
        cout << "Not Found !!" << endl;
    }
    else
    {
        cout << "The price is: " << *price << endl;
    }

    // Insert
    price_menu["Sandwich"] = 50;
    // Update
    price_menu["Sandwich"] += 25;
    // Search
    cout << "The price of Sandwich is " << price_menu["Sandwich"] << endl;

    return 0;
}