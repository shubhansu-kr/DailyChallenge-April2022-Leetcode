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

class KthLargest2
{
public:
    // Discussion solution : 
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest2(int k, vector<int> nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

class KthLargest1
{
public:
    // Runtime error : Since k is more than the nums.size() ;
    // ["KthLargest","add","add","add","add","add"]
    // [[2,[0]],[-1],[1],[-2],[-4],[3]]

    vector<int> v;
    KthLargest1(int k, vector<int> &nums)
    {
        if (nums.size())
        {
            sort(nums.begin(), nums.end());
            for (int i = nums.size() - k; i < nums.size(); i++)
            {
                v.push_back(nums[i]);
            }
        }
        else
        {
            v.push_back(-10001);
        }
    }

    int add(int val)
    {
        if (v[0] >= val)
        {
            return v[0];
        }
        else
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
            v.erase(v.begin());
            return v[0];
        }
    }
};

class KthLargest
{
    // This solution is intitutive - Without much thinking
    // Why would you consider storing all the val, when you literally
    // need only the last k element

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