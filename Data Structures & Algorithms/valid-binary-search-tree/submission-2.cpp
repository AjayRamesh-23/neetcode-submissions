/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool checkBST(TreeNode* root, int minVal, int maxVal)
    {   
        if(root == nullptr) return true;
        if(root->val <= minVal || root->val >=maxVal) return false;
        return checkBST(root->left, minVal, root->val) && checkBST(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        int minVal = INT_MIN;
        int maxVal = INT_MAX;
        if(checkBST(root, minVal, maxVal)) return true;
        return false;
        
    }
};
