// https://leetcode.com/problems/last-stone-weight/

// You are given an array of integers stones where stones[i] is the
// weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose
// the heaviest two stones and smash them together. Suppose the
// heaviest two stones have weights x and y with x <= y. The result
// of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of
// weight y has new weight y - x.

// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there
// are no stones left, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Intutive approach 
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size();
        if (n == 1)
        {
            return stones[0];
        }
        while (true)
        {
            sort(stones.begin(), stones.end());
            if (stones[n - 1] > 0)
            {
                if (stones[n - 2] > 0)
                {
                    stones[n - 1] -= stones[n - 2];
                    stones[n - 2] = 0;
                }
                else
                {
                    return stones[n - 1];
                }
            }
            else
            {
                return stones[n - 1];
            }
        }
    }
};

int main()
{

    return 0;
}