// https://leetcode.com/problems/recover-binary-search-tree/

// You are given the root of a binary search tree (BST), where
// the values of exactly two nodes of the tree were swapped by
// mistake. Recover the tree without changing its structure.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // Discussion solution : Revision required 
public:
    void markTree(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&end)
    {
        if (!root)
            return;
        markTree(root->left, prev, first, end);
        if (prev)
        {
            if (root->val < prev->val)
            {
                if (!first)
                {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        markTree(root->right, prev, first, end);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        markTree(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};

int main()
{

    return 0;
}