#include<iostream>
#include<vector>
using namespace std;

//TC=O((2^k)*N) SC=O(k*x)
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums,int idx,int target,vector<int> &ds){
        if(target<0) return;
        if(idx==nums.size()){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }
        if(target>=nums[idx]){
            ds.push_back(nums[idx]);
            if(target-nums[idx]>=0) helper(nums,idx,target-nums[idx],ds); //picking the number and not incrementing index since duplicates allowed
            ds.pop_back();
        }
        helper(nums,idx+1,target,ds); //not picking
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,ds);
        return res;
    }
};