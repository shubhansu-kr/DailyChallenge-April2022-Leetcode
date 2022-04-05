// https://leetcode.com/problems/container-with-most-water/

// You are given an integer array height of length n.
// There are n vertical lines drawn such that the two endpoints
// of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container,
// such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        // Area of container = min(height[i], height[j]) * (j-1) ;
        // We need to choose the container

        // Brute Force solution - Iterate all over the graph
        // Issue - Time Limit exceeded :( 

        int area = min(height[1], height[0]);

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (area < (min(height[i], height[j]) * abs(j - i)))
                {
                    area = (min(height[i], height[j]) * abs(j - i));
                }
            }
        }
        return area;
    }
};

int main()
{

    return 0;
}