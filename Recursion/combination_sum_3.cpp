// Determine all possible set of k numbers that can be added together to equal n while meeting the following requirements:
// There is only use of numerals 1 through 9.
// A single use is made of each number.

// Return list of every feasible combination that is allowed.

// T.C :-  O(2^9 * k)
// S.C :- O(K)

class Solution
{
public:
    void combination(int sum, int k, int a, vector<int> &v, vector<vector<int>> &ans)
    {

        if (sum == 0 && v.size() == k)
        {

            ans.push_back(v);
            return;
        }

        if (sum < 0 || v.size() > k)
        {
            return;
        }

        for (int i = a; i <= 9; i++)
        {

            if (i <= sum)
            {

                v.push_back(i);
                combination(sum - i, k, i + 1, v, ans);
                v.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // your code goes here

        vector<vector<int>> ans;
        vector<int> v;

        combination(n, k, 1, v, ans);

        return ans;
    }
};