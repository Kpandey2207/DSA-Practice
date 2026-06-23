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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> nodesQueue;
        bool LtoR = true;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            int n = nodesQueue.size();
            vector<int> row(n);  
            for (int i=0;i<n;i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = LtoR?i:(n-1-i);  

                row[index] = node->val;
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }
            LtoR = !LtoR;
            result.push_back(row);
        }
        return result;
    }
};