// https://leetcode.com/problems/shift-2d-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), o, p;
        vector<vector<int>> res(m, vector<int>(n));
        k %= (m * n);
        if (k == 0)
        {
            return grid;
        }
        else
        {
            o = k / n;
            p = k % n;
        }
        // Write an appropriate pointer approach
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // [i][j] is the orignal element
                res[o][p] = grid[i][j];
                p++;
                if (p == n)
                {
                    p = 0;
                    o++;
                    if (o == m)
                    {
                        o = 0;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}