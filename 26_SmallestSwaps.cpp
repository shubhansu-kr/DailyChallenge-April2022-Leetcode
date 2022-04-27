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
    // Discussion solution 
    
public:
    // Maximum number of vertices
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];

    void DFS(string &s, int vertex, vector<char> &characters, vector<int> &indices)
    {
        // Add the character and index to the list
        characters.push_back(s[vertex]);
        indices.push_back(vertex);

        visited[vertex] = true;

        // Traverse the adjacents
        for (int adjacent : adj[vertex])
        {
            if (!visited[adjacent])
            {
                DFS(s, adjacent, characters, indices);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        // Build the adjacency list
        for (vector<int> edge : pairs)
        {
            int source = edge[0];
            int destination = edge[1];

            // Undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }

        for (int vertex = 0; vertex < s.size(); vertex++)
        {
            // If not covered in the DFS yet
            if (!visited[vertex])
            {
                vector<char> characters;
                vector<int> indices;

                DFS(s, vertex, characters, indices);
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++)
                {
                    s[indices[index]] = characters[index];
                }
            }
        }

        return s;
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int flag = 1;
        vector<vector<int>> p;
        for (int i = 0; i < pairs.size(); i++)
        {
            for (int j = i + 1; j < pairs.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (pairs[i][0] == pairs[j][0])
                {
                    p.push_back({pairs[i][1], pairs[j][1]});
                }
            }
        }
        for (auto a : p)
        {
            pairs.push_back(a);
        }

        while (flag)
        {
            flag = 0;
            for (int i = 0; i < pairs.size(); i++)
            {
                if (s[pairs[i][0]] > s[pairs[i][1]])
                {
                    swap(s[pairs[i][0]], s[pairs[i][1]]);
                    flag = 1;
                }
            }
        }
        return s;
    }
};

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