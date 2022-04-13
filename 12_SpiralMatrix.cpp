// https://leetcode.com/problems/spiral-matrix-ii/

// Given a positive integer n, generate an n x n matrix filled
// with elements from 1 to n2 in spiral order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // There are two ways to solve this problem :
    // Either you find the formula on the basis of i and j ;
    // Or, You approach the elements on the basis of their value.

public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, val = 0;
        int changeI = 0;
        int positive = 1;
        while (val < n * n)
        {
            res[i][j] = val + 1;
            val++;
            if (changeI)
            {
                if (positive)
                {
                    i++;
                    if (i == n || res[i][j])
                    {
                        positive = 0;
                        changeI = 0;
                        i--;
                        j-- ;
                    }
                }
                else
                {
                    i--;
                    if (i < 0 || res[i][j])
                    {
                        i++;
                        changeI = 0;
                        positive = 1;
                        j++;
                    }
                }
            }
            else
            {
                if (positive)
                {
                    j++;
                    if (j == n || res[i][j])
                    {
                        changeI = 1;
                        j--;
                        positive = 1;
                        i++;
                    }
                }
                else
                {
                    j--;
                    if (j < 0 || res[i][j])
                    {
                        changeI = 1;
                        j++;
                        positive = 0;
                        i--;
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