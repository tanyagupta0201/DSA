#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.pop_back();
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    cout << "Capacity: " << v.capacity() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}