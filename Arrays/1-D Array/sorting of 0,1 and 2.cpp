#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int low=0;
    int high=n-1;
    int mid=0;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else
        {
            if(a[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}