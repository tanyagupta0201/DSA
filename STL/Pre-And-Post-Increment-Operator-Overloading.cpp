#include <bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int x;

public:
    void setData(int a)
    {
        x = a;
    }

    void showData()
    {
        cout << "x = " << x << endl;
    }

    Integer operator++() // pre increment
    {
        Integer i;
        i.x = ++x;
        return i;
    }

    // int is only written here to avoid any confusion to the compiler
    Integer operator++(int) // post increment
    {
        Integer i;
        i.x = x++;
        return i;
    }
};

int main()
{
    Integer i, i1;
    i1.setData(2);
    i1.showData();
    // Pre-increment operator
    // i = ++i1;
    i = i1.operator++();
    i.showData();

    // Post-increment operator
    i = i1++;
    i.showData();

    i1.showData();
    return 0;
}
