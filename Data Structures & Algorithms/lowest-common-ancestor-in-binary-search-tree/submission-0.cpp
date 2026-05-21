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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (p->val < root->val && q->val < root->val) {
            // ancestor is in the left subtree
            if (root->left == NULL) return root;
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) {
            // ancestor is in right subtree
            if (root->right == NULL) return root;
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val <= root->val && q->val >= root->val)
            return root;
    }

};
