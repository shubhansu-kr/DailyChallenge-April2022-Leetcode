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

class UnionFind
{
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size)
    {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i)
        {
            group[i] = i;
        }
    }

    int find(int node)
    {
        if (group[node] != node)
        {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2)
    {
        int group1 = find(node1);
        int group2 = find(node2);

        // node1 and node2 already belong to same group.
        if (group1 == group2)
        {
            return false;
        }

        if (rank[group1] > rank[group2])
        {
            group[group2] = group1;
        }
        else if (rank[group1] < rank[group2])
        {
            group[group1] = group2;
        }
        else
        {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<pair<int, pair<int, int>>> allEdges;

        // Storing all edges of our complete graph.
        for (int currNode = 0; currNode < n; ++currNode)
        {
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode)
            {
                int weight = abs(points[currNode][0] - points[nextNode][0]) +
                             abs(points[currNode][1] - points[nextNode][1]);

                allEdges.push_back({weight, {currNode, nextNode}});
            }
        }

        // Sort all edges in increasing order.
        sort(allEdges.begin(), allEdges.end());

        UnionFind uf(n);
        int mstCost = 0;
        int edgesUsed = 0;

        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i)
        {
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;

            if (uf.join(node1, node2))
            {
                mstCost += weight;
                edgesUsed++;
            }
        }

        return mstCost;
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
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                {
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