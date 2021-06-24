/* There are n white and n black dots, equally placed in a line.
    You want to connect each white dot with some one black dots, with minimum total length of wire.
    Find the total length of wire needed.

    Inputs: 

    White Dots Position = [ ]
    Black Dots Position = [ ]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int white_dots[] = {3, 1, 4};
    int black_dots[] = {5, 6, 2};
    int wire_length = 0;

    int n = sizeof(white_dots) / sizeof(int);

    // Sort the positions of the dots
    sort(white_dots, white_dots + n);
    sort(black_dots, black_dots + n);

    for (int i = 0; i < n; i++)
    {
        wire_length += abs(white_dots[i] - black_dots[i]);
    }

    cout << wire_length << endl;

    return 0;
}