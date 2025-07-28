// Brute force solution  :- Normal two loops
// T.C :- O(c^2)
// S.C :- O(1)

class Solution
{
public:
    bool judgeSquareSum(int c)
    {

        for (int i = 0; i <= c; i++)
        {

            for (int j = i; j <= c; j++)
            {

                long long a = pow(i, 2) + pow(j, 2);

                if (a > c)
                {
                    break;
                }

                if (a == c * 1LL)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// Better solution :- Binary search of  a^2 = c - b^2 instead of finding these two no. a and b . go for its one value only 
// T.C :- O(sqrt(c) * log(n))
// S.C :- O(1)

bool isPerfectSquare(long long target) {
    long long left = 0, right = target;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == target) return true;
        else if (square < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool judgeSquareSum(int c) {
    for (long long a = 0; a * a <= c; ++a) {
        long long b_squared = c - a * a;
        if (isPerfectSquare(b_squared)) return true;
    }
    return false;
}

// Optimised solution :- Two pointer where one pointer is placed at starting index and one is at last index.
// T.C :- O(sqrt(c))
// S.C :- O(1)

class Solution
{
public:
    bool judgeSquareSum(int c)
    {

        long left = 0, right = sqrt(c);
        while (left <= right)
        {
            long long sum = left * left + right * right;
            if (sum == c * 1ll)
                return true;
            if (sum < c)
                left++;
            else
                right--;
        }
        return false;
    }
};
