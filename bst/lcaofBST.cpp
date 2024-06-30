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

//Approach for BT, TC=O(N)
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p || root==q) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;
        return left ? left : right;
    }
};

//Optimization for BST, TC=O(logN) & SC=O(H)
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(curr){
            if(p->val<curr->val && q->val<curr->val) curr=curr->left;
            else if(p->val>curr->val && q->val>curr->val) curr=curr->right;
            else return curr;
        }
        return nullptr;
    }
};