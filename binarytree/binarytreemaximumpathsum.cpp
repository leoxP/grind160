#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//TC=O(N) SC=O(H)
class Solution {
public:
    int helper(TreeNode* root,int &res){
        if(!root) return 0;

        int left=helper(root->left,res);
        int right=helper(root->right,res);

        int temp=max(root->val,root->val+max(left,right)); //choosing/not choosing one branch
        int currsum=max(temp,root->val+left+right); //choosing both branches and making path
        res=max(currsum,res); //compare to the current max path
        return temp; //can only choose one side of subtree
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
};