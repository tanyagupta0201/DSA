/* 
    Iterator lower_bound (Iterator first, Iterator last, const val) 
    Iterator upper_bound (Iterator first, Iterator last, const val) 

    lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
    upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 2, 6, 8, 12, 12, 12, 12, 12, 16, 18, 21, 27};
    int n = sizeof(arr) / sizeof(int);

    // Lower Bound Function
    auto l = lower_bound(arr, arr + n, 3); // If a number is not present then the index of the number greater than it will come
    cout << "Lower bound of the array: " << (l - arr) << endl;

    auto lb = lower_bound(arr, arr + n, 12); // Will return the address of first occurence of 12 in the array
    cout << "Lower bound of the array: " << (lb - arr) << endl;

    // Upper Bound Function
    auto up = upper_bound(arr, arr + n, 12);
    cout << "Upper bound of the array: " << (up - arr) << endl;

    auto u = upper_bound(arr, arr + n, 20); // If a number is not present then the index of the number greater than it will come
    cout << "Upper bound of the array: " << (u - arr) << endl;

    // frequency of 12
    cout << "Frequency of 12 in the array is: " << up - lb << endl;
    return 0;
}