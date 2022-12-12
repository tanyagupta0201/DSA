// This problem is asked in DE SHAW India

// Problem Link
// https://www.codingninjas.com/codestudio/problems/rabbit-jumping_1262311?leftPanelTab=0

/*
   n = number of carrots
   k = number of rabbits
   arr = contains jumping factor of rabbits
*/

#include <bits/stdc++.h> 
int remainingCarrots(int n, int k, vector<int> &arr) 
{
    int ans = n; // intially all the carrorts are uneaten
    vector<bool> vis(n + 1, false);
    
    for(int i = 0; i < k; i++) // we have to check for each rabbit
    {
        if(vis[arr[i]] == true) // avoid unnecessary checking if its already marked
            continue;
        // if not marked check for it and its multiple
        for(int j = arr[i]; j < n + 1; j += arr[i])
        {
            if(vis[j] == true)
                continue;
            
            vis[j] = true;
            ans--;
        }
    }
    return ans;
}
