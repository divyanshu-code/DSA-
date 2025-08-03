// Given an array nums of n integers.

// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

// Bruteforce solution :- Normal loops
// T.C :- O(n^2)      where n is the size of the array
// S.C :- O(1)

class Solution
{
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int> &a, int num)
    {
        int n = a.size();
        // Traverse through the array
        for (int i = 0; i < n; i++)
        {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int> &nums)
    {
        // If the array is empty
        if (nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++)
        {
            // Current element
            int x = nums[i];
            // Count of the current sequence
            int cnt = 1;

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true)
            {
                // Move to the next number in the sequence
                x += 1;
                // Increment the count of the sequence
                cnt += 1;
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// better solution  :- greedy like store its previous no. and then update if not found
// // T.C :- O(NlogN) + O(N)      where N is the size of the array and Nlogn is for sorting the array 
// S.C :- O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        // Return 0 if array is empty
        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        // Track last smaller element
        int lastSmaller = INT_MIN;
        // Count current sequence length
        int cnt = 0;
        // Track longest sequence length
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            // If consecutive number exists
            if (nums[i] - 1 == lastSmaller)
            {
                // Increment sequence count
                cnt += 1;
                // Update last smaller element
                lastSmaller = nums[i];
            }
            // If consecutive number doesn't exits
            else if (nums[i] != lastSmaller)
            {
                // Reset count for new sequence
                cnt = 1;
                // Update last smaller element
                lastSmaller = nums[i];
            }
            // Update longest if needed
            longest = max(longest, cnt);
        }
        return longest;
    }
};


// optimised solution :- using  a hash map 
// T.C = O(N) + O(2xN) 
// S.C = O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        // If the array is empty
        if (n == 0) return 0; 
    
        // Initialize the longest sequence length
        int longest = 1; 
        unordered_set<int> st;
    
        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }
    
        /* Traverse the set to 
           find the longest sequence  */
        for (auto it : st) {
            // Check if 'it' is a starting number of a sequence
            if (st.find(it - 1) == st.end()) {
                // Initialize the count of the current sequence
                int cnt = 1; 
                // Starting element of the sequence
                int x = it; 
    
                // Find consecutive numbers in the set
                while (st.find(x + 1) != st.end()) {
                    // Move to the next element in the sequence
                    x = x + 1; 
                    // Increment the count of the sequence
                    cnt = cnt + 1; 
                }
                // Update the longest sequence length
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};