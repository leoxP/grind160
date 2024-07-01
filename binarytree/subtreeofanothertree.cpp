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
    bool same(TreeNode* root, TreeNode* sub){
        if(!root && !sub) return true; //if both are null 
        if(!root || !sub) return false; //if either are null
        if(root->val!=sub->val) return false; //if their values do not match

        return same(root->left,sub->left) && same(root->right,sub->right); //traverse both left and right when values match
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        if(same(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); 
        ///find the start point of both and return if either left or right side has subtree i.e. True
    }
};