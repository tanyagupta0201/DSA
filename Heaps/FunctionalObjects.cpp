#include <iostream>
#include <cstring>
using namespace std;

class Fun
{
public:
    void operator()()
    {
        cout << "Having Fun in operator() !!\n";
    }
};

class Funny
{
public:
    void operator()(string s)
    {
        cout << s << " is a funny language !! \n";
    }
};

int main()
{
    Fun f; // Constructor
    f();   // Overloaded () Operator = Functional Call where f is an object

    Funny k;
    k("C++");
    return 0;
}