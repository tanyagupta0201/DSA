// Function which prints all triplets of numbers which sum to target.
// Example:  array = {5, 7, 9, 1, 2, 4, 6, 8, 3}  and target = 10
// Output:   1, 2 and 7      1, 3 and 6      1, 4 and 5      2, 3 and 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000], n, target;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << "Enter the target: ";
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int currSum = a[i] + a[right] + a[left];

            if (currSum > target)
            {
                right--;
            }
            else if (currSum < target)
            {
                left++;
            }
            else if (currSum == target)
            {
                cout << a[i] << ", " << a[left] << " and " << a[right] << endl;
                left++;
                right--;
            }
        }
    }
    return 0;
}