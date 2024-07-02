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

class Solution {
public:
    vector<vector<int>> res;
    void helper(TreeNode* root,int sum,vector<int> &pos){
        if(!root) return;
        int x=root->val;
        sum-=root->val;
        pos.push_back(x);
        if(sum==0 && !root->left && !root->right){
            res.push_back(pos);
        }
        else{
            helper(root->left,sum,pos);
            helper(root->right,sum,pos);
        }
        pos.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> pos;
        helper(root,targetSum,pos);
        return res;
    }
};