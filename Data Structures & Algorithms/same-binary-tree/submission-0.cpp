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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Plan: DFS for to make sure length is the same while also checking values at once.

        bool same = true;
        dfs(p, q, same);
        return same;
    }

private:
    int dfs(TreeNode* rootOne, TreeNode* rootTwo, bool& same){
        if(!rootOne){
            if(!rootTwo){
                return 0;
            }
            same = false;
            return 0;
        }
        // Repeat for second tree

        if(!rootTwo){
            if(!rootOne){
                return 0;
            }
            same = false;
            return 0;
        }
        // Base case 2 - If the values don't match
        if(rootOne->val != rootTwo->val){
            same = false;
        }

        int left = dfs(rootOne->left, rootTwo->left, same);
        int right = dfs(rootOne->right, rootTwo->right, same);
        
        //int left = dfs(rootOne->left, rootTwo->left, same);
        //int right = dfs(rootOne->right, rootTwo->right, same);
        return 0;
    }
};
