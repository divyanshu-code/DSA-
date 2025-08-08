// Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.
// The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

// example : Input: arr1 = [2, 4, 6], arr2 = [1, 3, 5]
//           Output: 3.5

// bruteforce solution :- merge the two arrays and then find the median
// T.C :- O(m + n)  where m and n are the sizes of the two arrays
// S.C :- O(m + n)  for storing the merged array

class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();

        vector<int> merged;
        // Apply the merge step
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
                merged.push_back(arr1[i++]);
            else
                merged.push_back(arr2[j++]);
        }

        // Copy the remaining elements
        while (i < n1)
            merged.push_back(arr1[i++]);
        while (j < n2)
            merged.push_back(arr2[j++]);

        // Find the median
        int n = n1 + n2;
        if (n % 2 == 1)
        {
            return (double)merged[n / 2];
        }

        double median = ((double)merged[n / 2] + (double)merged[(n / 2) - 1]) / 2.0;
        return median;
    }
};

// better solution :- count the number of elements in the first array that are less than to the median
// T.C :- O((m+ n))) where m and n are the sizes of the two arrays
// S.C :- O(1)  no extra space is used

class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();
        int n = n1 + n2; // Total size

        // Required indices for median calculation
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        // Apply the merge step
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (cnt == ind1)
                    ind1el = arr1[i];
                if (cnt == ind2)
                    ind2el = arr1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == ind1)
                    ind1el = arr2[j];
                if (cnt == ind2)
                    ind2el = arr2[j];
                cnt++;
                j++;
            }
        }

        // Copy the remaining elements
        while (i < n1)
        {
            if (cnt == ind1)
                ind1el = arr1[i];
            if (cnt == ind2)
                ind2el = arr1[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == ind1)
                ind1el = arr2[j];
            if (cnt == ind2)
                ind2el = arr2[j];
            cnt++;
            j++;
        }

        // Find the median
        if (n % 2 == 1)
        {
            return (double)ind2el;
        }

        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

// optimised solution :- using binary search
// T.C :- O(log(min(m, n))) where m and n are the sizes of the two arrays
// S.C :- O(1)  no extra space is used

class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();

        /* Ensure arr1 is not larger than
        arr2 to simplify implementation*/
        if (n1 > n2)
            return median(arr2, arr1);

        int n = n1 + n2;

        // Length of left half
        int left = (n1 + n2 + 1) / 2;

        // Apply binary search
        int low = 0, high = n1;
        while (low <= high)
        {

            // Calculate mid index for arr1
            int mid1 = (low + high) >> 1;

            // Calculate mid index for arr2
            int mid2 = left - mid1;

            // Calculate l1, l2, r1, and r2
            int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                // If condition for finding median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
            {
                // Eliminate the right half of arr1
                high = mid1 - 1;
            }
            else
            {
                // Eliminate the left half of arr1
                low = mid1 + 1;
            }
        }
        // Dummy statement
        return 0;
    }
};
