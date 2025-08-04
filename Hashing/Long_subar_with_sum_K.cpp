// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k.
// Input: nums = [10, 5, 2, 7, 1, 9],  k=15
// Output: 4

// Bruteforce solution :- noraml two loops 1st one to fix element another one to iterate through.
// T.C :- O(n^2)        where n is the size of the array.
// S.C :- O(1)

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLength = 0;

        for (int startIndex = 0; startIndex < n; startIndex++)
        {

            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {

                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++)
                {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
};

// optimised solution :- hash map to store its sum - k
// T.C :- O(N)        where n is the size of the array.
// S.C :- O(logN )       where O(N)  is for storing the data into map.          it can be O(N)   if used unordered map data structure

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i
            sum += nums[i];

            // if the sum equals k, update maxLen
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e., sum - k
            int rem = sum - k;

            // calculate the length and update maxLen
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // update the map if sum is not already present
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
