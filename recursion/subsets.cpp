#include<iostream>
#include<vector>
using namespace std;

//TC=O(2^NxN) SC=O(N)
class Solution {
public:
    void helper(int idx,vector<int> &ds,vector<int> &nums,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx+1,ds,nums,res); //pick
        ds.pop_back();
        helper(idx+1,ds,nums,res); //not pick
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0,ds,nums,res);
        return res;
    }
};