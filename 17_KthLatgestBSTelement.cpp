// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode *root, int k)
    {
        return find(root, k);
    }
    int find(TreeNode *root, int &k)
    {
        if (root)
        {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val
                                 : find(root->right, k);
        }
        return 0;
    }
};

int main()
{

    return 0;
}