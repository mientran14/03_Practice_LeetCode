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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;
            return 1 + max(height(node->left), height(node->right));
        };

        if (root == nullptr) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1) return false;

        bool check_left = isBalanced(root->left);
        bool check_right = isBalanced(root->right);

        return check_left && check_right;
    }
};