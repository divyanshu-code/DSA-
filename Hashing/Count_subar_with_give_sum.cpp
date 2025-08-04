// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// Input: nums = [1, 1, 1], k = 2
// Output: 2


// Bruteforce solution :- noraml two loops 1st one to fix element another one to iterate through.
// T.C :- O(n^2)        where n is the size of the array.
// S.C :- O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Number of subarrays
        int count = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            int currentSum = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                // calculate the sum of subarray [startIndex...endIndex]
                // sum of [startIndex..endIndex-1] + nums[endIndex]
                currentSum += nums[endIndex];

                // Increase the count if currentSum == k:
                if (currentSum == k)
                    count++;
            }
        }
        return count;
    }
};

// optimised solution :- hash map to store its sum - k
// T.C :- O(N)        where n is the size of the array.
// S.C :- O(N )       where O(N)  is for storing the data into unordered map.          it can be O(logN)   if used map data structure

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> prefixSumMap;
        int currentPrefixSum = 0, subarrayCount = 0;

        // Setting 0 in the map.
        prefixSumMap[0] = 1;
        for (int i = 0; i < n; i++)
        {
            // Add current element to the prefix sum:
            currentPrefixSum += nums[i];

            /*Calculate the value to
            remove (currentPrefixSum - k)*/
            int sumToRemove = currentPrefixSum - k;

            /* Add the number of subarrays
             with the sum to be removed*/
            subarrayCount += prefixSumMap[sumToRemove];

            /* Update the count of current
            prefix sum in the map*/
            prefixSumMap[currentPrefixSum] += 1;
        }
        return subarrayCount;
    }
};