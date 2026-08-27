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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        queue<TreeNode*> myQueue;

        if(!root){
            return res;
        }
        myQueue.push(root);

        while(!myQueue.empty()){
            int queueLength = myQueue.size();
            vector<int> toPush;

            for(int i = 0; i < queueLength; i++){
                TreeNode* node = myQueue.front();
                myQueue.pop();
                toPush.push_back(node->val);

                if(node->left){
                    myQueue.push(node->left);
                }
                if(node->right){
                    myQueue.push(node->right);
                }
            }
            res.push_back(toPush);
        }

        return res;
    }
};
