/*   
FIBONACCI PATTERN
Print the following pattern for N = 4, each number should be seperated by a tab.

                    0
                    1  1
                    1  3  5
                    8  13 21  34 

*/

#include <iostream>
using namespace std;
int main()
{
    int N, row, col, n1 = 0, n2 = 1, sum = 0;
    cin >> N;
    for (row = 1; row <= N; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << n1 << "  ";
            sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }
        cout << endl;
    }
    return 0;
}