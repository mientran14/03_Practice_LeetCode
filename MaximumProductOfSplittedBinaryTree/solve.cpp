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
    const int MOD = 1e9 + 7;
    long long sumTree = 0, result = 0;

    long long calsumTree (TreeNode* root) {
        if (!root) return 0;
        long long sumTree = root->val + calsumTree(root->left) + calsumTree(root->right);
        return sumTree;
    }
    
    long long calsumSubTree (TreeNode* root) {
        if (!root) return 0;
        long long sumSubTree = root->val + calsumSubTree(root->left) + calsumSubTree(root->right);
        result = max(result, sumSubTree * (sumTree - sumSubTree));
        return sumSubTree;
    }

    int maxProduct(TreeNode* root) {
        sumTree =  calsumTree(root);
        calsumSubTree(root);
        return result % MOD;
    }
};
