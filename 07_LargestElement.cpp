// https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Design a class to find the kth largest element in a stream.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the
// integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns
// the element representing the kth largest element in the stream.

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    vector<int> v;
    int index;
    KthLargest(int k, vector<int> &nums)
    {
        if (nums.size())
        {
            sort(nums.begin(), nums.end());
            v = nums;
        }
        else
        {
            v.push_back(-10001);
        }
        index = k - 1;
    }

    int add(int val)
    {
        if (val >= v.back())
        {
            v.insert(v.begin() + v.size(), val);
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (val <= v[i])
                {
                    v.insert(v.begin() + i, val);
                    break;
                }
            }
        }
        return v[v.size() - index - 1];
    }
};

int main()
{

    return 0;
}