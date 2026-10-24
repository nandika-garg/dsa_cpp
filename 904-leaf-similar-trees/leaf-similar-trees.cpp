/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            arr.push_back(root->val);
            return;
        }
        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2){ 
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return (a==b); 
    }
};