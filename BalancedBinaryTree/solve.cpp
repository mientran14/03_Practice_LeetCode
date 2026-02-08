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
        bool flag = true;

        function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;

            int leftHeight = height(node->left);
            int rightHeight = height(node->right);

            if (abs(leftHeight - rightHeight) > 1) {
                flag = false;
            }

            return 1 + max(leftHeight, rightHeight);
        };

        height(root);
        return flag;
    }
};