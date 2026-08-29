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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        // Start by pushing the root
        q.push(root);

        // BFS
        while(!q.empty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                TreeNode* node = q.front();
                q.pop();
                // Only pushing the last value in the q into the result.
                if(i == length - 1) res.push_back(node->val);

                // Push all children into the q. Only the last node is visible from the right side 
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
