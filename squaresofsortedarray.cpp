#include<iostream>
#include<vector>
using namespace std;

//TC=O(NlogN), SC=O(logN)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(), nums.end()); 
        return nums;
    }
};

//More efficient two pointer approach
//TC=O(N), SC=O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l=0,r=nums.size()-1,idx=nums.size()-1;
        while(l<=r){
            int x=nums[l]*nums[l];
            int y=nums[r]*nums[r];
            if(x>y){
                ans[idx]=x;
                l++;
            }
            else{
                ans[idx]=y;
                r--;
            }
            idx--;
        }
        return ans;
    }
};