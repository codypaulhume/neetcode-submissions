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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // Similar plan here. Combine the last two assignments
        // Find the height of each and also calculate the diameter (left + right)

        int res = 0;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, int& res){
        // We are returning the height in this DFS. Not the diameter. We just happen to calculate it here

        // Base case - If we reach nullptr
        if(!root){
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        // Quick diameter check
        res = max(res, left + right);

        // Now we can return the height
        return 1 + max(left, right);
    }
};
