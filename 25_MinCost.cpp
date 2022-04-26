// https://leetcode.com/problems/min-cost-to-connect-all-points/

// You are given an array points representing integer coordinates
// of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the
// manhattan distance between them: |xi - xj| + |yi - yj|, where
// |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points
// are connected if there is exactly one simple path between any two points.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Wrong solution
    // [[0,0],[1,-5],[2, -2], [2,0], [3, -2]]
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int cost = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int minCost = abs(points[i][0] - points[i - 1][0]) + abs(points[i][1] - points[i - 1][1]);
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j) {
                    continue;
                }
                minCost = min(minCost, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
            }
            cost += minCost;
        }
        return cost;
    }
};

class Solution
{
    // Wrong solution
    // [[0,0],[1,-5],[2, -2], [2,0], [3, -2]]
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int cost = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int minCost = abs(points[i][0] - points[i - 1][0]) + abs(points[i][1] - points[i - 1][1]);
            for (int j = 0; j < i; j++)
            {
                minCost = min(minCost, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
            }
            cost += minCost;
        }
        return cost;
    }
};

int main()
{

    return 0;
}