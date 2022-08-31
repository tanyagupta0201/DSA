#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }

    void displayData()
    {
        cout << a << " " << b << endl;
    }

    // binary operator overloading
    Complex operator+(Complex c2)
    {
        Complex temp;
        temp.a = a + c2.a;
        temp.b = b + c2.b;
        return temp;
    }

    // Unary operator overloading
    Complex operator-()
    {
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
};

int main()
{
    Complex c1, c2, c3, c4, c5;

    c1.setData(2, 8);
    c2.setData(12, 8);

    // c3 = c1 + c2; -> first way
    c3 = c1.operator+(c2); // ->second way
    c3.displayData();

    c3 = -c1; // first way
    // c3 = c1.operator-(); -> second way
    c3.displayData();

    c5.setData(8, 9);
    c4 = c5.operator-();
    c4.displayData();
    return 0;
}
