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
    int sum=0;
    bool findBST(TreeNode* root,int& mn,int& mx,int& currSum){
        if(root==NULL){
            mn=INT_MAX;
            mx=INT_MIN;
            currSum=0;
            return true;
        }
        int lmn,lmx,lsum;
        int rmn,rmx,rsum;
        bool leftBST=findBST(root->left,lmn,lmx,lsum);
        bool rightBST=findBST(root->right,rmn,rmx,rsum);
        if(leftBST && rightBST && lmx<root->val && root->val<rmn){
            currSum=lsum+rsum+root->val;
            mn=min(lmn,root->val);
            mx=max(rmx,root->val);
            sum=max(sum,currSum);
            return true;
        }
        mn=INT_MIN;
        mx=INT_MAX;
        currSum=0;
        return false;
    }
    int maxSumBST(TreeNode* root) {
        int mn,mx,currSum;
        findBST(root,mn,mx,currSum);
        return sum;
    }
};