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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> curNode;
        curNode.push_back(root);
        
        int maxSum = INT_MIN;
        int maxSumLevel = 0;
        int curLevel = 0;

        while (!curNode.empty()) {
            curLevel++;
            int curSum = 0;
            vector<TreeNode*> nextNode;

            for (TreeNode* node : curNode) {
                curSum += node->val;
                if (node->left) nextNode.push_back(node->left);
                if (node->right) nextNode.push_back(node->right);
            }

            if (curSum > maxSum) {
                maxSum = curSum;
                maxSumLevel = curLevel;
            }

            curNode = nextNode;
        }
        return maxSumLevel;
    }
};
