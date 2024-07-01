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
    void helper(TreeNode* root,int lvl,vector<int> &res){
        if(!root) return;
        //if this is the first node we've encountered at this level
        if(lvl==res.size()) res.push_back(root->val); 
        //process right subtree first to get the right side view
        helper(root->right,lvl+1,res);
        helper(root->left,lvl+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level=0;
        helper(root,level,res);
        return res;
    }
};