#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { //Using BFS/Level Order Traversal
public:
    TreeNode* invertTree(TreeNode* root) {
        vector<vector<TreeNode*>> ans;
        if(root==nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*> level;
            for(int i=0;i<size;i++){
                TreeNode* x=q.front();
                q.pop();
                TreeNode* swap=x->left;
                x->left=x->right;
                x->right=swap;

                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
                level.push_back(x);
            }
            ans.push_back(level);
        }
        return ans[0][0];
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root; //Final point of post order is root
    }
};