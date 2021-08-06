// Next Permutation - https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int size = nums.size();

    if (size == 1)
    {
        return;
    }

    int i = 1;
    int lastInclude = -1;

    // Finding the peak index
    while (i < size)
    {
        if (nums[i] > nums[i - 1])
        {
            lastInclude = i;
        }
        i++;
    }

    // if the array is in descending order return the array in ascending order
    if (lastInclude == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }

    // Special Case
    // Find element in the range (nums[lastInclude - 1] to nums[lastInclude]) to the right
    int index = lastInclude;

    for (int i = lastInclude; i < size; i++)
    {
        if (nums[i] > nums[lastInclude - 1] and nums[i] < nums[index])
        {
            index = i;
        }
    }

    swap(nums[lastInclude - 1], nums[index]);
    sort(nums.begin() + lastInclude, nums.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    nextPermutation(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}