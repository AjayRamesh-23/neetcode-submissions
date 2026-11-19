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
    int getIndex(int node, vector<int>& inorder){
        auto it = find(inorder.begin(), inorder.end(), node);
        int idx = distance(inorder.begin(), it);
        return idx;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = getIndex(preorder[0], inorder);
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + mid);
        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightInOrder(inorder.begin() + mid + 1, inorder.end());
        vector<int> rightPreOrder(preorder.begin() + mid + 1, preorder.end());

        root->left = buildTree(leftPreOrder, leftInOrder);
        root->right = buildTree(rightPreOrder, rightInOrder);
        return root;
    }
};



