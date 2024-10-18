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

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        diameter = max(diameter, leftHeight + rightHeight+ root->val);
        diameter = max(diameter, root->val);
        diameter = max(diameter, leftHeight + root->val);
        diameter = max(diameter, rightHeight+ root->val);

        int num = max(leftHeight, rightHeight) + root->val;
        num = max(num, root->val);
        num = max(num, rightHeight+ root->val);
        num = max(num, leftHeight+ root->val);
        return num;
    }

    int maxPathSum(TreeNode* root) {
        calculateHeight(root);
        return diameter;
    }
};
