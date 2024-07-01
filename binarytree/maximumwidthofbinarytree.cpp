#include<iostream>
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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(!root) return 0;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()){
            int size=q.size();
            long long left=q.front().second;
            long long right;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                long long idx=q.front().second-left;
                q.pop();
                if(i==size-1) right=idx+left;
                if(curr->left) q.push({curr->left,idx*2+1});
                if(curr->right) q.push({curr->right,idx*2+2});
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};