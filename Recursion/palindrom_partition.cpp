// Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.

// Input : s = "aabaa"
// Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] , [ "aa", "b", "aa" ] , [ "aabaa" ] ]

// T.C :- O(2^N)
// S.C :- O(N);

class Solution
{
public:
    bool Check(string s, int left, int right)
    {

        string b = s.substr(left, right - left + 1);
        string rev = b;
        reverse(rev.begin(), rev.end());

        return rev == b;
    }
    void partition1(int ind, string s, vector<string> &v, vector<vector<string>> &ans)
    {

        if (ind == s.size())
        {

            ans.push_back(v);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {

            if (Check(s, ind, i))
            {

                string a = s.substr(ind, i - ind + 1);
                v.push_back(a);

                partition1(i + 1, s, v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> v;

        partition1(0, s, v, ans);

        return ans;
    }
};