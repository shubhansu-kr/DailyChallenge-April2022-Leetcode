// https://leetcode.com/problems/smallest-string-with-swaps/

// You are given a string s, and an array of pairs of indices
// in the string pairs where pairs[i] = [a, b] indicates 2
// indices(0-indexed) of the string.

// You can swap the characters at any pair of indices in the
// given pairs any number of times.

// Return the lexicographically smallest string that s can be
// changed to after using the swaps.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Wrong answer 
    // We can swap more than once, so its like keep swapping unless you get the min.
    // order string. 
public:
    bool check(string a, string b)
    {
        // check if a > b ;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            if (a[i] > b[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        string temp = s;
        for (int i = 0; i < pairs.size(); ++i)
        {
            // We can't skip the swapping , However we can
            // record when neccessary
            swap(s[pairs[i][0]], s[pairs[i][1]]);
            if (check(temp, s))
            {
                temp = s;
            }
        }
        return temp;
    }
};

int main()
{

    return 0;
}