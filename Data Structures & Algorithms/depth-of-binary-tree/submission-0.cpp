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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int result = 0;

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});

        while(!stack.empty()){
            // Grab the top and get rid of it on the stack
            pair<TreeNode*, int> temp = stack.top();
            stack.pop();

            // Grab the node from the pair above
            TreeNode* node = temp.first;

            // Grab the depth from the pair above
            int depth = temp.second;

            // As long as the top value of the stack is not nullptr, add its children and increase the depth by 1
            if(node != nullptr){
                // Find the max
                result = max(result, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
        }
        return result;
        
    }
};
