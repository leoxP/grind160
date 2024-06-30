#include<iostream>
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
    bool isBalanced(TreeNode* root) {
        if(check(root)!=-1) return true;
        return false;
    }
    int check(TreeNode* root){
        if(root==nullptr) return 1;

        int l=check(root->left);
        int r=check(root->right);
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;

        return 1+max(l,r);
    }
};