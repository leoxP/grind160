#include<iostream>
#include<vector>
using namespace std;

//TC=N!xN SC=O(2N)
class Solution {
public:
    void helper(vector<int> &ds,vector<int> &nums,vector<vector<int>> &res,vector<int> &freq){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]); //pick
                freq[i]=1;

                helper(ds,nums,res,freq);
                
                ds.pop_back(); //not pick
                freq[i]=0; 
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<vector<int>> res;
        vector<int> ds;
        helper(ds,nums,res,freq);
        return res;
    }
};

//TC=N!xN SC=O(N) using Swapping indices method
//No extra ds needed
class Solution {
public:
    void helper(int idx,vector<int> &nums,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0,nums,res);
        return res;
    }
};