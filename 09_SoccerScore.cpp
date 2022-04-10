// https://leetcode.com/problems/baseball-game/

// You are keeping score for a baseball game with strange rules.
// The game consists of several rounds, where the scores of past
// rounds may affect future rounds' scores.

// At the beginning of the game, you start with an empty record.
// You are given a list of strings ops, where ops[i] is the ith
// operation you must apply to the record and is one of the following:

// An integer x - Record a new score of x.

// "+" - Record a new score that is the sum of the previous two scores.
// It is guaranteed there will always be two previous scores.

// "D" - Record a new score that is double the previous score. It is
// guaranteed there will always be a previous score.

// "C" - Invalidate the previous score, removing it from the record.
// It is guaranteed there will always be a previous score.

// Return the sum of all the scores on the record.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int point = 0;
        vector<int> record;
        for (auto x : ops)
        {
            int newScore;
            if (x == "+")
            {
                newScore = record[record.size() - 2] + record[record.size() - 1];
                // point += newScore;
                record.push_back(newScore);
            }
            else if (x == "D")
            {
                newScore = 2 * record.back();
                // point += newScore;
                record.push_back(newScore);
            }
            else if (x == "C")
            {
                // newScore = record.back();
                // point -= newScore;
                record.pop_back();
            }
            else
            {
                newScore = stoi(x);
                // point += newScore;
                record.push_back(newScore);
            }
        }
        for (auto x : record)
        {
            point += x;
        }
        return point;
    }
};

int main()
{

    return 0;
}