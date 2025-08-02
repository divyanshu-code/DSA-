// given an array of position of stalls
// n the size of array
// k the no. aggresive cows

// we have to assign a stalls to k cows such that the distance between any of two cows become minimum distance is the maximum possible.

// like : n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]
// now our task is to assign  k cow to nums[i] stalls
// 1 cow go to nums[0] ,  2 cow to nums[1]  then difference is 3
// 3 cow to nums[2] , 4 cow to nums[3]  then difference is 1

// now see we have  assign all cows to stalls and we have minimum distance also i.e. 1
// in this way find all minimum distance  then return its maximum posiible answer .

// Bruteforce solution : normal two loops with linear search
// T.C :- O(nlogn) + O(limit * n)          nlogn for sorting and limit*n for find possible answer and iterating through the array
// S.C :- O(1)

class Solution
{
public:
    bool canWePlace(vector<int> &nums, int dist, int cows)
    {

        // Size of array
        int n = nums.size();

        // Number of cows placed
        int cntCows = 1;

        // Position of last placed cow
        int last = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - last >= dist)
            {

                // Place next cow
                cntCows++;

                // Update the last location
                last = nums[i];
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k)
    {

        int n = nums.size();
        // Sort the nums
        sort(nums.begin(), nums.end());

        int limit = nums[n - 1] - nums[0];
        for (int i = 1; i <= limit; i++)
        {
            if (canWePlace(nums, i, k) == false)
            {
                return (i - 1);
            }
        }
        // Retrun the answer
        return limit;
    }
};

// Optimised solution  :- binary search --- important thing to find a range for binary search
// T.C :-  O(nlogn) + O(N log(m))
// S.C :- O(1)

class Solution
{
public:
    bool canWePlace(vector<int> &nums, int dist, int cows)
    {

        // Size of array
        int n = nums.size();

        // Number of cows placed
        int cntCows = 1;

        // Position of last placed cow
        int last = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - last >= dist)
            {

                // Place next cow
                cntCows++;

                // Update the last location
                last = nums[i];
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k)
    {

        int n = nums.size();
        // Sort the nums
        sort(nums.begin(), nums.end());

        int low = 1, high = nums[n - 1] - nums[0];

        while (low <= high)
        {

            int mid = (low + high) / 2;

            if (canWePlace(nums, mid, k))
            {

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};