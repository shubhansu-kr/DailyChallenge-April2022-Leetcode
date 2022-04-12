// https://leetcode.com/problems/game-of-life/

// According to Wikipedia's article: "The Game of Life, also known
// simply as Life, is a cellular automaton devised by the British
// mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has
// an initial state: live (represented by a 1) or dead
// (represented by a 0). Each cell interacts with its eight neighbors
// (horizontal, vertical, diagonal) using the following four rules
// (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused
// by under-population.
// Any live cell with two or three live neighbors lives on to the next
// generation.
// Any live cell with more than three live neighbors dies, as if by
// over-population.
// Any dead cell with exactly three live neighbors becomes a live cell,
// as if by reproduction.
// The next state is created by applying the above rules simultaneously
// to every cell in the current state, where births and deaths occur
// simultaneously. Given the current state of the m x n grid board,
// return the next state.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int work(vector<vector<int>> &board, int r, int c)
    {
        int m = board.size(), n = board[0].size(), cnt = 0;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 and j == 0)
                    continue;
                int newr = r + i, newc = c + j;
                if (newr < 0 or newr >= m or newc < 0 or newc >= n)
                    continue;
                cnt += (board[newr][newc] % 2);
            }

        if (board[r][c] == 1)
            return cnt == 2 or cnt == 3;
        else
            return cnt == 3;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int old = board[i][j];
                int newval = work(board, i, j);
                board[i][j] = old + 2 * newval;
            }

        for (auto &r : board)
            for (auto &ele : r)
                ele = ele / 2;
    }
};

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        // For The sake of correctness : Dont disturb the previous state
        vector<vector<int>> nextState /*( board.size(), vector<int>(board[0].size())) */;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // Decide for each cell if they would live or die
                // How would you decide the 8 neighbours :
                // Keep track of previous data ?
                // Or use index calculative approach

                // calculate neighbour :
                // we can use a condition : if (neighbour > 3 ) jump to next step
                int neighbour = 0;
                if (i > 0)
                {
                    if (j > 0)
                    {
                        neighbour += board[i - 1][j - 1];
                    }
                    neighbour += board[i - 1][j];
                    if (j < board[i].size() - 1)
                    {
                        neighbour += board[i - 1][j + 1];
                    }
                }
                if (i < board.size() - 1)
                {
                    if (j > 0)
                    {
                        neighbour += board[i + 1][j - 1];
                    }
                    if (neighbour > 3)
                    {
                        nextState[i][j] = 0;
                        continue;
                    }
                    neighbour += board[i + 1][j];
                    if (neighbour > 3)
                    {
                        nextState[i][j] = 0;
                        continue;
                    }
                    if (j < board[i].size() - 1)
                    {
                        neighbour += board[i + 1][j + 1];
                    }
                }
                if (neighbour > 3)
                {
                    nextState[i][j] = 0;
                    continue;
                }
                if (j > 0)
                {
                    neighbour += board[i][j - 1];
                }
                if (j < board[i].size() - 1)
                {
                    neighbour += board[i][j + 1];
                }

                // Now that i have the neighbour, Apply condition on neighbour
                if (neighbour < 2)
                {
                    nextState[i][j] = 0;
                }
                else if (neighbour == 2)
                {
                    nextState[i][j] = board[i][j];
                }
                else if (neighbour == 3)
                {
                    nextState[i][j] = 1;
                }
                else
                {
                    nextState[i][j] = 0;
                }
            }
        }
        board = nextState;
    }
};

int main()
{

    return 0;
}