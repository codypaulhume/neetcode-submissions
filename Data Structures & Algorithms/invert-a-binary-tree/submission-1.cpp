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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        // Create a queue for order and push root into to begin
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()){
            // Grab current node at the front of the queue and swap its children
            TreeNode* node = queue.front();
            queue.pop();

            swap(node->left, node->right);

            // If node has children, put them in the queue.
            if(node->left){
                queue.push(node->left);
            }
            if(node->right){
                queue.push(node->right);
            }
        }
        return root;
        
    }
};
