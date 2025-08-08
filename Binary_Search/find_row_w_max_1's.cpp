// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

// bruteforce solution :- normal two loops 1st one to fix element another one to iterate through.
//  T.C :- O(n*m)        where n is the number of rows and m is the number of columns.
//  S.C :- O(1)

class Solution
{
public:
    /* Function to find the row
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        /* Variable to store the
        maximum count of 1's found*/
        int cnt_max = 0;

        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;

        // Traverse the matrix row by row
        for (int i = 0; i < n; i++)
        {

            /* Counter for 1's
            in the current row*/
            int cnt_ones = 0;

            /* Count the number of
            1's in the current row*/
            for (int j = 0; j < m; j++)
            {
                cnt_ones += mat[i][j];
            }

            /* Update cnt_max and index if current
            row has more 1's than previously found*/
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row
        with the maximum number of 1's*/
        return index;
    }
};

// optimised solution :- using binary search
// T.C :- O(n*log(m)) where n is the number of rows and m is the number of columns.
// S.C :- O(1)  no extra space is used

class Solution
{
private:
    // Helper function to find the lower bound of 1.
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            /* If element at mid is greater than or equal
            to x then it counld be a possible answer.*/
            if (arr[mid] >= x)
            {
                ans = mid;

                // Look for smaller index on the left
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Return the answer
        return ans;
    }

public:
    /* Function to find the row
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        /* Variable to store the
        maximum count of 1's found*/
        int cnt_max = 0;

        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;

        // Traverse each row of the matrix
        for (int i = 0; i < n; i++)
        {
            // Get the number of 1's
            int cnt_ones = m - lowerBound(mat[i], m, 1);

            /*If the current count is greater than
            maximum, store the index of current row
            and update the maximum count.*/
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row
        with the maximum number of 1's*/
        return index;
    }
};
