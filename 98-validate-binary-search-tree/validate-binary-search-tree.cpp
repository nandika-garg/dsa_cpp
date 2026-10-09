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
bool check(TreeNode* node, long long minm, long long maxm){
    if (node==NULL) return true;
    if(node->val<=minm || node->val>=maxm) return false;
    return check(node->left, minm, node->val) && check(node->right, node->val, maxm);

}
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);        
    }
};