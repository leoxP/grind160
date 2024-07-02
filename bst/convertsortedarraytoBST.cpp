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
    TreeNode* helper(vector<int> &nums,int low,int high){
        if(low>high) return nullptr;
        int mid=(low+high)/2;
        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=helper(nums,low,mid-1);
        curr->right=helper(nums,mid+1,high);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int low=0;
       int high=nums.size()-1; 
       TreeNode* root=helper(nums,low,high); 
       return root;
    }
};