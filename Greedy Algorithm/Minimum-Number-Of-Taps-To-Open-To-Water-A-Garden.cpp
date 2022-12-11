// https://youtu.be/Pk128gC_sdw

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        int taps = 0;
        int maxi = 0, mini = 0; // initially both are zero
        int lastTap = 0;

        while(maxi < n)
        {
            for(int i = lastTap; i <= n; i++)
            {
                if(i - ranges[i] <= mini && i + ranges[i] > maxi)
                {
                    lastTap = i;
                    maxi = i + ranges[i];
                }
            }
            // if garden cannot be watered
            if(maxi == mini)
                return -1;

            taps++;
            mini = maxi;
        }
        return taps;
    }
};


/*
  index =    0     1      2      3      4      5
  range =    3     4      1      1      0      0
         -------------------------                  (-3, 3)
         ---------------------------------------    (-3, 5)
                   ---------------                   (1, 3)
                          ---------------            (2, 4)
                                        -            (4, 4)
                                               -     (5, 5)

   
   Now I want min number of taps 
   so, mai left side se dekhungi ki 0 se start ho and right mein max tak cover kare
   jahan par tap over hoga wo mera new min bann jayega aur phir wahan se dekhungi jo tap max rightmost cover kare 
   and so on...
   As soon as, mai last index ko cover karlungi, I need to come out of my loop
*/
