// Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.

// Input : nums = [1, 2, 3]
// Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

//T.C = O(2^N)
//S.c = O(N * 2^N)

class Solution
{
public:
    void func(int ind, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans)
    {
        // Base case: if the index reaches the length of the array,
        // add the current subset to the answer list
        if (ind == n)
        {
            ans.push_back(arr);
            return;
        }

        // Recursive case: Exclude the current element and move to the next element
        func(ind + 1, n, nums, arr, ans);

        // Include the current element in the subset and move to the next element
        arr.push_back(nums[ind]);
        func(ind + 1, n, nums, arr, ans);

        // Backtrack: remove the last added element to explore other subsets
        arr.pop_back();
    }

    vector<vector<int>> powerSet(vector<int> &nums)
    {
        // your code goes here

        vector<vector<int>> ans;
        vector<int> arr;
        func(0, nums.size(), nums, arr, ans);
        return ans;
    }
};