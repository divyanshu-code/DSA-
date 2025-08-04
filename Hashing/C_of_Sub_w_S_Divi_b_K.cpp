// Given an array of integers, nums, and an integer k, the task is to find the total number of subarrays whose sum is divisible by k.
// Input: nums = [3, 1, 4, 1], k = 3

// Output: 3

// Bruteforce solution :- noraml two loops
// T.C :- O(n^2)        where n is the size of the array.
// S.C :- O(1)

// optimised solution :- hash map to store its sum % k
// T.C :- O(N logN)        where n is the size of the array. to used map d.s LogN
// S.C :- O(logN)                 O(logN)   used map data structure

class Solution
{
public:
    int subarraySumDivisbleByK(vector<int> &nums, int k)
    {

        int count = 0, sum = 0;
        map<int, int> mp;

        mp[0] = 1;

        for (int j = 0; j < nums.size(); j++)
        {

            sum += nums[j];
            int mod = sum % k;

            // handle negative mods correctly

            count += mp[mod];
            mp[mod]++;
        }

        return count;
    }
};
