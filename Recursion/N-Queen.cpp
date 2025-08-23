// The challenge of arranging n queens on a n × n chessboard so that no two queens attack one another is known as the "n-queens puzzle."
// Return every unique solution to the n-queens puzzle given an integer n. The answer can be returned in any sequence.
// Every solution has a unique board arrangement for the placement of the n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.

// Input : n = 4
// Output : [[".Q.." , "...Q" , "Q..." , "..Q."] , ["..Q." , "Q..." , "...Q" , ".Q.."]]

// T.C =  O(N!)
// S.C =  O(N)


class Solution {
   public:
    bool queendone(int row, int col, vector<string>& board) {
        int n = board.size();
          int r = row, c = col;

          // Check upper left diagonal
          while (r >= 0 && c >= 0) {
               if (board[r][c] == 'Q') return false;
               r--;
               c--;
          }

          // Reset to the original position
          r = row;
          c = col;

          // Check left side
          while (c >= 0) {
               if (board[r][c] == 'Q') return false;
               c--;
          }

          // Reset to the original position
          r = row;
          c = col;

          // Check lower left diagonal
          while (r<n && c>= 0) {
               if (board[r][c] == 'Q') return false;
               r++;
               c--;
          }

          return true;
    }
    void placedqueen(int col, int n, vector<string>& board,
                     vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (queendone(row, col, board)) {
                board[row][col] = 'Q';

                placedqueen(col + 1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // your code goes here

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        placedqueen(0, n, board, ans);

        return ans;
    }
};