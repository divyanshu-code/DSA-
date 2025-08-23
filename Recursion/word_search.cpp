// Given a grid of n x m dimension grid of characters board and a string word.The word can be created by assembling the letters of successively surrounding cells, whether they are next to each other vertically or horizontally. It is forbidden to use the same letter cell more than once.
// Return true if the word exists in the grid otherwise false.

// Input : board = [ ["A", "B", "C", "E"] , ["S" ,"F" ,"C" ,"S"] , ["A", "D", "E", "E"] ] , word = "ABCCED"
// Output : true


// T.C =  O(N * M * 4^L)
// S.C =  O(L)

class Solution
{
public:
    bool func(vector<vector<char>> &v, int i, int j, string &s, int k)
    {

        if (k == s.size())
        {
            return true;
        }

        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] != s[k] || v[i][j] == ' ')
        {
            return false;
        }

        char x = v[i][j];
        v[i][j] = ' ';

        bool ans = false;

        ans |= func(v, i + 1, j, s, k + 1); // for bottom
        ans |= func(v, i - 1, j, s, k + 1); // for top
        ans |= func(v, i, j + 1, s, k + 1); // for right
        ans |= func(v, i, j - 1, s, k + 1); // for left

        v[i][j] = x;
        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (board[i][j] == word[0])
                {

                    if (func(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};