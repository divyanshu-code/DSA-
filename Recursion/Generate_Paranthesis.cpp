//Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.

// Input : n = 3
// Output : [ "((()))" , "(()())" , "(())()" , "()(())" , "()()()" ]

//optimal solution 
// T.C =  O((4^n / sqrt(n))*n)
// S.c = O((4^n / sqrt(n))*n)

class Solution {
   public:
    void validparanthesis(string s, int open, int close, vector<string> &v,
                          int n) {
        if (open == close && (open + close) == 2 * n) {
            v.push_back(s);
            return;
        }

        if (open < n) {
            validparanthesis(s + '(', open + 1, close, v, n);
        }

        if (open > close) {
            validparanthesis(s + ')', open, close + 1, v, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        // your code goes here
        string s = "";
        vector<string> v;
        validparanthesis(s, 0, 0, v, n);

        return v;
    }
};