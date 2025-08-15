// it is 2nd part 
// Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.

                        // matrix = {{1, 4, 7, 11, 15}, 
                        //           {2, 5, 8, 12, 19},
                        //           {3, 6, 9, 16, 22},
                        //           {10, 13, 14, 17, 24},
                        //           {18, 21, 23, 26, 30}};
                        // int target = 8;

// where in search in matrix in 1st part matrix placed in different way 
// matrix = {
//     {1, 2, 3, 4}, 
//     {5, 6, 7, 8}, 
//     {9, 10, 11, 12}};
//     int target = 8;

//bruteforce solution :- normal two loops and find 
// T.C :- O(n*m)
// S.C :- O(1);

// better solution :- binary search 
// T.C :- O(n) + O(logm)
// S.C :- O(1);


class Solution {
private:
    //Helper function to perform binary search
    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size(); 
        int low = 0, high = n - 1;

        // Perform the steps:
        while (low <= high) {
            int mid = (low + high) / 2;
            
            //Return true if target is found
            if (nums[mid] == target) return true;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        //Return false if target not found
        return false;
}
public:
    //Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Traverse through each row
        for (int i = 0; i < n; i++) {
            
            /*Check if target is 
            present in the current row*/
            bool flag =  binarySearch(matrix[i], target);
            
            if (flag) return true;
        }
        // Return false if target is not found
        return false; 
    }
};


// Optimised solution :- to fix the row and fix the coloumn 
// T.C :- O(N + M)
// S.C :- O(1);

class Solution {
public:
    //Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Intialize the row and col
        int row = 0, col = m - 1;

        //Traverse the matrix from (0, m-1):
        while (row < n && col >= 0) {
            
            //Return true of target is found
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        //Return false if target not found
        return false;
    }
};