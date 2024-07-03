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

//TC=O(N^2)
class Solution {
public:
    int cnt=0;
    void helper(TreeNode* root,long long sum){
        if(!root) return;
        if(sum==root->val) cnt++;
        helper(root->left,sum-root->val);
        helper(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        helper(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return cnt;
    }
};

//TC=O(N) using prefix sum method
class Solution {
public:
    int cnt=0;
    void helper(TreeNode* root,long long target,unordered_map<long long,int> &m,long long psum,int &cnt){
        if(!root) return;

        //x+target=psum
        psum+=root->val;
        if(m.find(psum-target)!=m.end()){
            cnt+=m[(psum-target)]; //psum takes the continguous values similar to array
        //so when you check if psum exists or not, youre considering a set of elements before part of the path you're at
        //hence you increase the cnt based on that 
        }
        m[psum]++; 
        helper(root->left,target,m,psum,cnt);
        helper(root->right,target,m,psum,cnt);
        m[psum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        long long psum=0; //prefix sum
        unordered_map<long long,int> m;
        m[0]=1; //when root can also be included then psum-target=0
        helper(root,targetSum,m,psum,cnt);
        return cnt;
    }
};