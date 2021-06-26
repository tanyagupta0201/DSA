#include <bits/stdc++.h>
using namespace std;

/*   
    cout << flush; in C++ () (if using cin cout)

    fflush(stdout) in C++ () (if using printf scanf)

    System.out.flush() in Java 

    stdout.flush() in Python

*/

int main()
{
    // These lines are used so that that the data is stored in the buffer and after all tbe test cases are over then the output is displayed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << "n -> " << n << "\n";
        cout << flush;
    }

    // endl actually works as cout << "\n" << flush;

    return 0;
}