// we have given the array of pages with ith book.
// and m is the students

// we have to covered all the books that is also assgin to students.
//  also we can't use two books to assign one student.

// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized

// Bruteforce solution : normal two loops with linear search
// T.C :- O(high - low) + O(n)         where high is sum of the array and low is the maximum element.
// S.C :- O(1)

class Solution
{
public:
    int allocation(vector<int> &nums, int m)
    {

        int student = 1, sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (sum + nums[i] <= m)
            {

                sum += nums[i];
            }
            else
            {

                sum = nums[i];
                student++;
            }
        }

        return student;
    }
    int findPages(vector<int> &nums, int m)
    {

        int n = nums.size();
        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int count = 0;
        for (int i = low; i <= high; i++)
        {

            count = allocation(nums, i);

            if (count == m)
            {
                return i;
            }
        }

        return -1;
    }
};

// Optimised solution  :- binary search --- important thing to find a range for binary search
// T.C :-   O(N log(high -low ))          where high is sum of the array and low is the maximum element and N is the loop where we iterate through the array.
// S.C :- O(1)

class Solution
{
public:
    int allocation(vector<int> &nums, int m)
    {

        int student = 1, sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (sum + nums[i] <= m)
            {

                sum += nums[i];
            }
            else
            {

                sum = nums[i];
                student++;
            }
        }

        return student;
    }
    int findPages(vector<int> &nums, int m)
    {

        int n = nums.size();
        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int a = -1;
        while (low <= high)
        {

            int mid = (low + high) / 2;

            if (allocation(nums, mid) <= m)
            {
                a = mid;
                high = mid - 1;
            }
            else
            {

                low = mid + 1;
            }
        }
        return a;
    }
};
