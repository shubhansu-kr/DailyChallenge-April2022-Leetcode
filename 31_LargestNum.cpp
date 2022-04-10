// 6037. Largest Number After Digit Swaps by Parity

// You are given a positive integer num. You may swap any two
// digits of num that have the same parity (i.e. both odd digits
// or both even digits).

// Return the largest possible value of num after any number of swaps

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestInteger(int num)
    {
        vector<int> nums;
        while (num)
        {
            nums.push_back(num % 10);
            num /= 10;
        }

        for (int i = 0; i < nums.size() / 2; i++)
        {
            swap(nums[i], nums[nums.size() - 1 - i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int maxEven = nums[i];
            int index = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (maxEven < nums[j] && nums[j] % 2 == nums[i] % 2)
                {
                    maxEven = nums[j];
                    index = j;
                }
            }
            swap(nums[i], nums[index]);
        }
        num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            num = num * 10 + nums[i];
        }
        return num;
    }
};

int main()
{

    return 0;
}