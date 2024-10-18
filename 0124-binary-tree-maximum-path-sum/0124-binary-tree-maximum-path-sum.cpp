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
    int diameter = INT_MIN;
    int calculateHeight(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = max(0, calculateHeight(root->left));
        int rightHeight = max(0, calculateHeight(root->right));

        diameter = max(diameter, leftHeight + rightHeight+ root->val);

        return max(leftHeight, rightHeight) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        calculateHeight(root);
        return diameter;
    }
};
