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
    bool isBalanced(TreeNode* root) {
        int res = 0;
        bool balanced = true;
        dfs(root, res, balanced);
        return balanced;
    }

private:
    int dfs(TreeNode* root, int& res, bool& balanced){
        if(!root) return 0;

        int left = dfs(root->left, res, balanced);
        int right = dfs(root->right, res, balanced);

        // Checking if one subtree if greater than the other by more than 1. ABS used if right > left
        if(abs(left - right) > 1){
            balanced = false;
        }

        return 1 + max(left, right);
    }
};
