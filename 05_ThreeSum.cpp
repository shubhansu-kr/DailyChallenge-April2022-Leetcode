// https://leetcode.com/problems/3sum-with-multiplicity/

// Given an integer array arr, and an integer target, return
// the number of tuples i, j, k such that i < j < k and
// arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        // Same solution with conditions - Still the TLE probablity persists
        // If the arr will be sorted we can add more conditions
        sort(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] > target)
            {
                break;
            }
            for (int j = i + 1; j < arr.size(); ++j)
            {
                if (arr[i] + arr[j] > target)
                {
                    break;
                }
                for (int k = j + 1; k < arr.size(); ++k)
                {
                    if (arr[i] + arr[j] + arr[k] > target)
                    {
                        break;
                    }
                    if (arr[i] + arr[j] + arr[k] == target)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {

        // Prone to TLE

        //  Time limit exceeded as expected

        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                for (int k = j + 1; k < arr.size(); k++)
                {
                    if (arr[i] + arr[j] + arr[k] == target)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}