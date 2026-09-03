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
    TreeNode* findSuccessor(TreeNode* node) {
        node = node->right;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;              
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        if(key==root->val){
            if(root->left==NULL && root->right==NULL) root=NULL;
            else if (root->left==NULL) root=root->right;
            else if (root->right==NULL) root=root->left;
            else {
                TreeNode* node=findSuccessor(root);
                root->right=deleteNode(root->right, node->val);
                root->val=node->val;  
            }
        }
        else if (key<root->val) root->left=deleteNode(root->left, key);
        else if (key>root->val) root->right=deleteNode(root->right, key);

        return root;
    }
};