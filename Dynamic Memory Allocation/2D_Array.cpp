#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    // Create an array of row head
    int **arr;
    arr = new int *[r];

    // Now create columns from rows
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }

    // Take input and print the element
    int val = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = val;
            cout << arr[i][j] << " ";
            val++;
        }
        cout << endl;
    }
}