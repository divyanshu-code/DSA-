// Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.

// Input : digits = "34"
// Output : [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]

// T.C : -O(4 ^ N * N)
// S.C : -O(N)


 class Solution
{
public:
    void func(int ind, string digits, string s, vector<string> &ans, string combos[])
    {
        // Base case: if index reaches the end of digits
        if (ind == digits.size())
        {
            // Add the current combination to the answer
            ans.push_back(s);
            return;
        }
        // Convert the current character to an integer
        int digit = digits[ind] - '0';
        // Loop through the corresponding characters
        for (int i = 0; i < combos[digit].size(); i++)
        {
            // Recursively call function with next index
            // Add current character to the string
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        // your code goes here
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; // Vector to store results
        string s = "";      // Temporary string to build combinations
        // Initiate recursive function
        func(0, digits, s, ans, combos);
        return ans; // Return the result
    }
};