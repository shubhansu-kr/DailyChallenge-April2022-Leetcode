// https://leetcode.com/problems/trim-a-binary-search-tree/

// Given the root of a binary search tree and the lowest and highest
// boundaries as low and high, trim the tree so that all its elements
// lies in [low, high]. Trimming the tree should not change the relative
// structure of the elements that will remain in the tree (i.e., any node's
// descendant should remain a descendant). It can be proven that there is a
// unique answer.

// Return the root of the trimmed binary search tree. Note that the
// root may change depending on the given bounds.

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
public:
    TreeNode *trimLeft(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            // Some code
        }
        else if (root->val == low)
        {
            root->left = nullptr;
        }
        else if (root->val > low)
        {
            trimLeft(root->left, low, high);
        }
        else
        {
            trimBST(root, low, high);
        }
    }

    TreeNode *trimRight(TreeNode *root, int low, int high)
    {
        // This function trims the higher val ;
        
    }

    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // Let's break the question in two part :
        // 1. Remove the lower limit.
        // 2. Remove the higher limit.

        root = trimLeft(root, low, high);
    }
};

int main()
{

    return 0;
}