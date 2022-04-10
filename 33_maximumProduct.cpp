// Maximum Product After K Increments

// You are given an array of non-negative integers nums and an integer k.
// In one operation, you may choose any element from nums and increment it by 1.

// Return the maximum product of nums after at most k operations. Since the answer
// may be very large, return it modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (nums[i] == 0)
            {
                if (k)
                {
                    nums[i]++;
                    k--;
                }
                else
                {
                    return 0;
                }
            }
        }
        nums[0] += k;
        int res = 1;
        const unsigned int M = 1000000007;
        for (int i = 0; i < nums.size(); i++)
        {
            res = (res * nums[i]) % M;
        }
        return res;
    }
};

int main()
{

    return 0;
}