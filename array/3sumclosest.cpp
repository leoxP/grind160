#include<iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX/2; //to prevent integer overflow
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<abs(diff-target)) diff=sum;
                if(sum>target) r--;
                else if(sum<target) l++;
                else return diff; //when sum is equal to the target value
            }
        }
        return diff;
    }
};