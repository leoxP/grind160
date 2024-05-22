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
    int calc(TreeNode* root,int &dia){
        if(!root) return 0;
        int lh = calc(root->left, dia);
        int rh = calc(root->right, dia);
        dia = max(dia, lh + rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x=0;
        calc(root,x);
        return x;
    }
};