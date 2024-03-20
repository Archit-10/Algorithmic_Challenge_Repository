#include <iostream>
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
    TreeNode *call(vector<int> &nums, int low, int high)
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = call(nums, low, mid - 1);
            root->right = call(nums, mid + 1, high);
            return root;
        }
        return nullptr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return call(nums, 0, nums.size() - 1);
    }
};