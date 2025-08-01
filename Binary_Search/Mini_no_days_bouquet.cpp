// Minimum Number of Days to Make m Bouquets

// we have array of day in  that a flower has bloomed on the day.  find the minimum day in which it make bouquet under condition.

// Brute force solution  :- Normal two loops
// T.C :- O(M+N) + O(n)           where M is mini element and N is maxi element  and n is iterate through array .
// S.C :- O(1)

class Solution
{
public:
    bool possible(vector<int> &nums, int day, int m, int k)
    {
        int n = nums.size();

        int cnt = 0;

        int noOfB = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= day)
            {

                cnt++;
            }
            else
            {

                noOfB += (cnt / k);

                cnt = 0;
            }
        }

        noOfB += (cnt / k);

        return noOfB >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        if (bloomDay.size() < m * k)
            return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int i = mini;
        int b = -1;
        while (i <= maxi)
        {

            if (possible(bloomDay, i, m, k))
            {
                b = i;
                return b;
            }

            i++;
        }

        return b;
    }
};


// Optimised solution :- binary search 
// T.C :- O(M+N) + O(nlog(a))      where M is mini element and N is maxi element  and n is iterate through array .
// S.C :- O(1)


class Solution {
public:
     bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
      
        int cnt = 0; 

        int noOfB = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] <= day) {
        
                cnt++; 
            } else {
         
                noOfB += (cnt / k);
                
       
                cnt = 0; 
            }
        }
   
        noOfB += (cnt / k); 

        
        return noOfB >= m; 
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
         
          if( bloomDay.size() < m * 1ll *k * 1ll)  return -1 ;

          int mini = *min_element(bloomDay.begin() , bloomDay.end());
          int maxi = *max_element(bloomDay.begin() , bloomDay.end());

           int low = mini , high = maxi ;
           int ans = -1 ;

           while(low <= high){
               
                int mid = (low+high) / 2 ;

                if(possible(bloomDay , mid , m , k)){
                      ans = mid ;
                      high = mid -1 ;
                }else{
                      low = mid+1 ;
                }
           }

           return ans ;

    }
};