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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;

        if(!root) return false;

        // True base case - If the node matches the subroot we return true.
        if(sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    // Helper function to check if subtree exists within the tree for each node.
    bool sameTree(TreeNode* p, TreeNode* q){
        // Base case 1 - If we reach nullptr for both nodes
        if(!p && !q){
            return true;
        }
        // Base case 2 - If both nodes exist and their values are the same-> we iterate. Otherwise they dont match and we return false
        if(p && q && p->val == q->val){
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }else{
            return false;
        }
    }
};
