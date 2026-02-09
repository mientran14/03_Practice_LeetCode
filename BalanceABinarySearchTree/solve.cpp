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
    void traversal(TreeNode* node, vector<int>& values) {
        if (node == nullptr) return;
        traversal(node->left, values);
        values.push_back(node->val);
        traversal(node->right, values);
    }

    TreeNode* rebuild(const vector<int>& values, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(values[mid]);

        root->left = rebuild(values, left, mid - 1);
        root->right = rebuild(values, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        traversal(root, values);
        return rebuild(values, 0, values.size() - 1);
    }
};